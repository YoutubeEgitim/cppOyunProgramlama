#include "Sahne.hpp"
#include "Pencere.hpp"
#include "Math.hpp"
#include <imgui.h>
#include <imgui-SFML.h>

void Sahne::baslat()
{
	m_panelUzerindemi = false;
	m_degisimVarmi = false;
	m_bilesenGoster = false;
	m_nokta.setRadius(4);
	m_nokta.setOrigin(sf::Vector2f(4, 4));
	m_nokta.setFillColor(sf::Color::Blue);


	m_daire.setRadius(100.0f);
	m_daire.setOrigin(sf::Vector2f(100, 100));
	m_daire.setFillColor(sf::Color::Red);
	m_daire.setPointCount(3);


	m_dogruYukseklik = 4.0f;
	m_dogru.setSize(sf::Vector2f(100, m_dogruYukseklik));
	m_dogru.setOrigin(sf::Vector2f(0, m_dogruYukseklik / 2.0f));
	m_dogru.setFillColor(sf::Color::Black);

	m_vektorSekli.baslat();
	
}
void Sahne::daireMerkezAta(const sf::Vector2f& merkez)
{
	if (m_panelUzerindemi)
		return;

	
	m_degisimVarmi = true;
	m_daire.setPosition(merkez);
	m_daire.setRadius(2.0f);
	
	m_daire.setOrigin(sf::Vector2f(1.0f, 1.0f));

	
	

	m_basKonum = merkez;
	m_sonKonum = merkez;
	m_dogru.setPosition(m_basKonum);

	m_vektorSekli.basKonumAta(merkez);
	
	
}

void Sahne::daireSonKonumAta(const sf::Vector2f& sonKonum)
{
	if (m_degisimVarmi == false)
		return;

	auto merkez = m_daire.getPosition();
	auto fark = sonKonum - merkez;
	float yaricap = fark.y;
	if (fark.x > fark.y)
		yaricap = fark.x;
	m_daire.setRadius(yaricap);
	m_daire.setOrigin(sf::Vector2f(yaricap, yaricap));
	
	m_sonKonum = sonKonum;
	
	m_vektorSekli.sonKonumAta(sonKonum);
}

void Sahne::daireBittimi(bool bittimi)
{
	m_degisimVarmi = !bittimi;
}
void Sahne::guiPanelCiz()
{
	ImGui::Begin("Sahne Paneli");
	ImGui::AlignTextToFramePadding();
	m_panelUzerindemi = false;
	if (ImGui::IsWindowHovered())
	{
		m_panelUzerindemi = true;
	}
	
	ImGui::SliderFloat2("Baslangic", &m_basKonum.x, 0, 1000, "%0.1f");
	ImGui::SliderFloat2("son", &m_sonKonum.x, 0, 1000, "%0.1f");
	ImGui::SliderFloat("aci", &m_aci, -360, 360, "%0.0f");
	
	
	m_vektorSekli.guiCizdir("hiz vektoru");
	
	ImGui::End();
	
	
}
void Sahne::guncelle(const sf::Time& dt)
{
	m_vecFark = m_sonKonum - m_basKonum;
	
	
	float uzunluk = Math::length(m_vecFark);
	m_dogru.setSize(sf::Vector2f(uzunluk, m_dogruYukseklik));
	auto vecX = sf::Vector2f(1.0f, 0.0f);
	auto cosq = Math::dotNormalize(m_vecFark, vecX);
	auto radAci = acosf(cosq);
	m_aci = Math::radToDeg(radAci);

	if (m_vecFark.y <= 0.0f)
		m_aci = 360.0f - m_aci;

	m_dogru.setRotation(m_aci);
	
	m_vektorSekli.guncelle(dt);
}

void Sahne::ciz(Pencere& pencere)
{
	guiPanelCiz();
	
	m_vektorSekli.ciz(pencere);
}
