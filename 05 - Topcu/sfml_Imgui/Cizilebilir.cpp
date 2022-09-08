#include "Cizilebilir.hpp"



void Cizilebilir::baslat()
{
	for (auto siradaki : m_cocuklar)
		siradaki->baslat();
}

void Cizilebilir::guncelle(const sf::Time& dt)
{
	for (auto siradaki : m_cocuklar)
		siradaki->guncelle(dt);
}

void Cizilebilir::ciz(Pencere& pencere)
{
	for (auto siradaki : m_cocuklar)
		siradaki->ciz(pencere);
}

void Cizilebilir::guiCizdir(const std::string& yazi)
{
	for (auto siradaki : m_cocuklar)
		siradaki->guiCizdir(m_isim);
}

void Cizilebilir::konumAta(const sf::Vector2f& konum)
{
	m_konum = konum;
}

sf::Vector2f Cizilebilir::konumGetir()
{
	return m_konum;
}

void Cizilebilir::cocukEkle(CizilebilirPtr yeniCocuk)
{
	m_cocuklar.push_back(yeniCocuk);
}

void Cizilebilir::isimAta(const std::string& isim)
{
	m_isim = isim;
}
