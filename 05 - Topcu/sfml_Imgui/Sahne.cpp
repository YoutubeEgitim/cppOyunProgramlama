#include "Sahne.hpp"
#include "Pencere.hpp"
#include "Math.hpp"
#include <imgui.h>
#include <imgui-SFML.h>
#include<queue>
void Sahne::baslat()
{
	m_panelUzerindemi = false;
	m_degisimVarmi = false;
	m_bilesenGoster = false;

	for (auto siradaki : m_cocuklar)
		siradaki->baslat();
	
}
Sahne::Sahne()
{

}
void Sahne::daireMerkezAta(const sf::Vector2f& merkez)
{
	if (m_panelUzerindemi)
		return;
	
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
	
}

void Sahne::daireBittimi(bool bittimi)
{
	m_degisimVarmi = !bittimi;
}
void Sahne::guiCizdir()
{
	ImGui::Begin("Sahne Paneli");
	ImGui::AlignTextToFramePadding();
	m_panelUzerindemi = false;
	if (ImGui::IsWindowHovered())
	{
		m_panelUzerindemi = true;
	}
	
	for (auto siradaki : m_cocuklar)
	{
		siradaki->guiCizdir();
	}
	ImGui::End();

	
}
void Sahne::guncelle(const sf::Time& dt)
{
	for (auto siradaki : m_cocuklar)
		siradaki->guncelle(dt);
}


void Sahne::ciz(Pencere& pencere)
{

	for (auto siradaki : m_cocuklar)
	{
		siradaki->ciz(pencere);
	}
}
