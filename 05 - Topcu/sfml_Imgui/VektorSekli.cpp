#include "VektorSekli.hpp"
#include <imgui.h>
#include <imgui-SFML.h>
void VektorSekli::baslat()
{

	m_vektorGorulsunmu=true;
	m_eksenlerGorulsunmu=false;
	m_yaziGorulsunmu=false;
	m_xEkseni.kalinlikAta(m_dogruKalinlik * 0.25f);
	m_yEkseni.kalinlikAta(m_dogruKalinlik * 0.25f);
	m_xEkseni.renkAta(sf::Color::Red);
	m_yEkseni.renkAta(sf::Color::Red);
}

void VektorSekli::guncelle(const sf::Time& dt)
{

}

void VektorSekli::ciz(Pencere& pencere)
{
	if(m_vektorGorulsunmu)
		Ok::ciz(pencere);
	if (m_eksenlerGorulsunmu)
	{
		m_xEkseni.ciz(pencere);
		m_yEkseni.ciz(pencere);
	}
}

void VektorSekli::guiCizdir(const std::string& yazi)
{
	
	ImGui::Separator();
	ImGui::Checkbox("Vektor", &m_vektorGorulsunmu);
	ImGui::SameLine();
	ImGui::Checkbox("Eksenler", &m_eksenlerGorulsunmu);
	ImGui::SameLine();
	ImGui::Checkbox("Degerler", &m_yaziGorulsunmu);
	if (ImGui::SliderFloat2(yazi.c_str(), &m_yon.x, -1000, 1000, "%0.1f"))
	{
		yonAta(m_yon);
	}

	degerGoster(m_yaziGorulsunmu);
	m_xEkseni.degerGoster(m_yaziGorulsunmu);
	m_yEkseni.degerGoster(m_yaziGorulsunmu);
}

void VektorSekli::yonAta(const sf::Vector2f& yon)
{
	Ok::yonAta(yon);

	m_xEkseni.basKonumAta(m_konum);
	m_yEkseni.basKonumAta(m_konum);

	m_xEkseni.yonAta(sf::Vector2f(m_yon.x, 0.0f));
	m_yEkseni.yonAta(sf::Vector2f(0.0f,m_yon.y));
}


