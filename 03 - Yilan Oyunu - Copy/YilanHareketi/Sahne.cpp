#include "Sahne.hpp"
#include "Pencere.hpp"
#include "Math.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include<iostream>
bool deger;

void Sahne::guiCiz()
{
	ImGui::Begin("Sekil Ciz");
	ImGui::SliderFloat("Aci", &m_yonAci, 0, 360);
	ImGui::SliderFloat("Cap", &m_yariCap,0,300);
	ImGui::SliderFloat2("Konum", &m_konum.x, 0, 800);
	ImGui::SliderFloat2("Yon", &m_yon.x, 0, 800);
	ImGui::Checkbox("Hareket Et", &m_hareketEtsinmi);
	if (ImGui::Button("Yon Belirle"))
	{
		m_yonBelirle = true;
	}
	ImGui::End();
}

void Sahne::ciz(Pencere& pencere)
{
	guiCiz();

	pencere.ciz(m_daire);
	pencere.ciz(m_dogruBas);
	pencere.ciz(m_dogruSon);
	pencere.ciz(m_dogru);

	m_ok.ciz(pencere);
}

void Sahne::fareHareket(sf::Event::MouseMoveEvent olay)
{
	if (m_fareBasili && m_yonBelirle)
	{
		m_dogruSon.setPosition(sf::Vector2f(olay.x, olay.y));
		yonGuncelle();
	}
}

void Sahne::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
	if (olay.button == sf::Mouse::Left)
	{
		if (m_yonBelirle)
		{
			m_dogruBas.setPosition(m_daire.getPosition());
			m_fareBasili = true;
		}

	}
		
}
void Sahne::fareBirakildi(sf::Event::MouseButtonEvent olay)
{
	if (m_fareBasili && m_yonBelirle)
	{
		m_fareBasili = false;
		
	}
}
void Sahne::yonGuncelle()
{
	m_dogruBas.setPosition(m_konum);
	auto yon = m_dogruSon.getPosition() - m_dogruBas.getPosition();
	float uzun = uzunluk(yon);
	m_yon = normalize(yon);
	m_ok.m_uzunluk = uzun;
	m_ok.yonAta(m_yon);
	float d = dot(m_yon, normalize(sf::Vector2f(1.0f, 0.0f)));


	m_dogru.setPosition(m_dogruBas.getPosition());

	m_yonAci = RadToDeg(acos(d));
	if (m_yon.y <= 0)
		m_yonAci = 360.0f - m_yonAci;
	m_dogru.setSize(sf::Vector2f(uzun, 2.0f));
	m_dogru.setOrigin(sf::Vector2f(0.0f, 1.0f));
	m_dogru.setRotation(m_yonAci);
}
void Sahne::baslat()
{
	m_yariCap = 20.0f;
	m_hareketEtsinmi = false;
	m_daire.setRadius(m_yariCap);
	m_daire.setOrigin(sf::Vector2f(m_yariCap, m_yariCap));
	m_daire.setFillColor(sf::Color::Red);
	m_daire.setPosition(sf::Vector2f(400, 400));
	m_konum = sf::Vector2f(400, 400);
	m_dogruBas.setRadius(5);
	m_dogruBas.setOrigin(5, 5);
	m_dogruSon.setRadius(5);
	m_dogruSon.setOrigin(5, 5);
	m_dogruSon.setPosition(m_konum);
	m_dogruBas.setFillColor(sf::Color::Black);
	m_dogruSon.setFillColor(sf::Color::Green);

	m_dogru.setSize(sf::Vector2f(100, 2));
	m_dogru.setOrigin(sf::Vector2f(0, 1.0f));
	m_dogru.setFillColor(sf::Color::Magenta);
	m_fareBasili = false;
	m_yonBelirle = false;
	m_ok.baslat();
}

void Sahne::guncelle(sf::Time& gecenSure)
{
	m_daire.setRadius(m_yariCap);
	m_daire.setPosition(m_konum);
	yonGuncelle();
	if (m_hareketEtsinmi)
	{
		m_konum += m_yon*gecenSure.asSeconds() * 30.0f;
		if (uzunluk((m_dogruSon.getPosition() - m_dogruBas.getPosition())) <= 0.01f)
		{
			m_hareketEtsinmi = false;
		}
		
	}
	m_ok.guncelle(gecenSure);


}
