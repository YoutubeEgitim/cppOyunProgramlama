#include "Tank.hpp"
#include "Pencere.hpp"
#include "imgui.h"
#include "Math.hpp"
Tank::Tank(TankYonu yon,float hucreBoyutu)
{
	m_hucreBoyutu = hucreBoyutu;
	sf::Vector2f govdeBoyut(m_hucreBoyutu*3, m_hucreBoyutu);
	sf::Vector2f namluBoyut(m_hucreBoyutu*2, m_hucreBoyutu*0.5f);
	float		 kuleYariCap(m_hucreBoyutu);
	m_yon = yon;

	m_govdeSekli.setSize(govdeBoyut);
	m_kuleSekli.setRadius(kuleYariCap);
	m_namluSekli.setSize(namluBoyut);

	


	if (m_yon == TankYonu::Sag)
	{
		m_namluSekli.setOrigin(sf::Vector2f(0.0f, namluBoyut.y * 0.5f));
		m_govdeSekli.setFillColor(sf::Color::Black);
		m_kuleSekli.setFillColor(sf::Color::Black);
		m_namluSekli.setFillColor(sf::Color::Red);
	}
	else
	{
		m_namluSekli.setOrigin(sf::Vector2f(namluBoyut.x, namluBoyut.y * 0.5f));
		m_govdeSekli.setFillColor(sf::Color::Blue);
		m_kuleSekli.setFillColor(sf::Color::Blue);
		m_namluSekli.setFillColor(sf::Color::Red);
	}
	m_kuleSekli.setOrigin(sf::Vector2f(kuleYariCap, kuleYariCap));


	tankOlustur();
}

void Tank::baslat()
{
}

void Tank::guncelle(const sf::Time& dt)
{

}

void Tank::ciz(Pencere& pencere)
{
	pencere.ciz(m_namluSekli);
	pencere.ciz(m_kuleSekli);
	pencere.ciz(m_govdeSekli);
}

void Tank::konumAta(const sf::Vector2f& konum)
{
	Cizilebilir::konumAta(konum);
	tankOlustur();

}

void Tank::guiCizdir(const std::string& yazi)
{
	float aci=m_namluSekli.getRotation();
	if (aci > 90)
		aci = 360 - aci;
	std::string ekKimlik = "##" + m_isim;
	if (ImGui::SliderFloat(("aci"+ ekKimlik).c_str(), &aci, 0, 90, "%0.0f"))
	{
		namluDondur(aci);
	}

}

void Tank::namluDondur(float aci)
{
	if (m_yon == TankYonu::Sag)
		aci = -aci;
	if(aci <=90)
		m_namluSekli.setRotation(aci);
}

sf::Vector2f Tank::namluYonuGetir()
{
	float aci = 0.0f;
	sf::Vector2f hareket;
	if (m_yon == TankYonu::Sag)
	{
		aci = 360 - m_namluSekli.getRotation();
		hareket.x = cosf(Math::degToRad(aci));
	}
	else
	{
		aci = m_namluSekli.getRotation();
		hareket.x = -cosf(Math::degToRad(aci));
	}
		
	
	
	hareket.y = -sinf(Math::degToRad(aci));

	hareket = Math::normalize(hareket);

	return hareket;
}



sf::Vector2f Tank::namluPozisyonuGetir()
{

	auto yeniPozisyon = m_namluSekli.getPosition() + namluYonuGetir() *m_namluSekli.getSize().x;

	return yeniPozisyon;
}

void Tank::tankOlustur()
{
	auto govdeBoyutu = m_govdeSekli.getSize();
	auto kuleYariCap = m_kuleSekli.getRadius();
	auto namluBoyut = m_namluSekli.getSize();

	float govdeKuleDx = govdeBoyutu.x - kuleYariCap * 2;
	float kuleNamluDy = kuleYariCap - namluBoyut.y;

	m_govdeSekli.setPosition(m_konum);
	m_kuleSekli.setPosition(sf::Vector2f(m_konum.x + govdeBoyutu.x * 0.5f, m_konum.y));
	m_namluSekli.setPosition(sf::Vector2f(m_konum.x + govdeBoyutu.x * 0.5f, m_konum.y -kuleYariCap * 0.5f));

}
