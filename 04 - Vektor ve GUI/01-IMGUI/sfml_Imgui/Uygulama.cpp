#include "Uygulama.hpp"
#include <iostream>
#include "imgui.h"
#include "imgui-SFML.h"
Uygulama::Uygulama()
{
	
}

void Uygulama::insaEt(int genislik, int yukseklik)
{
	
	m_pencere.olustur(genislik, yukseklik);
	

	m_izgara.ayarla(genislik, 50);

	m_sahne.baslat();

	
	m_pencere.fareHareketFonksiyonuEkle(
		std::bind(&Uygulama::fareHareket, this, std::placeholders::_1)
	);
	m_pencere.fareTiklamaFonksiyonuEkle(
		std::bind(&Uygulama::fareTiklandi, this, std::placeholders::_1)
	);
	m_pencere.tusaBasFonksiyonuEkle(
		std::bind(&Uygulama::tusBasildi, this, std::placeholders::_1)
	);
	m_pencere.tusuBirakFonksiyonuEkle(
		std::bind(&Uygulama::tusBirakildi, this, std::placeholders::_1)
	);
	m_pencere.fareBirakmaFonksiyonuEkle(
		std::bind(&Uygulama::fareBirakildi, this, std::placeholders::_1)
	);
}

void Uygulama::baslat(int fps)
{
	float cerfps = 1.0f / fps;
	m_cerceveSuresi = sf::seconds(cerfps);
	
	m_gecenSure = m_saat.restart();

	while (m_pencere.pencereAcikmi())
	{
		m_pencere.olaylariIsle();
		
		m_gecenSure = m_saat.getElapsedTime();

		if (m_gecenSure >= m_cerceveSuresi)
		{
			
			cerceveOlustur();
			
			m_gecenSure = sf::seconds(0.0f);
			m_saat.restart();
		}
		else
		{
			sf::sleep(m_gecenSure - m_cerceveSuresi);
		}
	}
	ImGui::SFML::Shutdown();

}

void Uygulama::cerceveOlustur()
{
	sahneGuncelle();
	
	ImGui::SFML::Update(m_pencere.pencereGetir(), m_cerceveSuresi);

	
	cizimFonksiyonu();
}

void Uygulama::cizimFonksiyonu()
{
	m_pencere.temizle();
	m_izgara.ciz(m_pencere);

	m_sahne.ciz(m_pencere);
	
	m_pencere.goster();
}

void Uygulama::sahneGuncelle()
{
	m_sahne.guncelle(m_cerceveSuresi);
}
int fps = 60;
void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Left)
		;
	if (tus == sf::Keyboard::Right)
		;
	if (tus == sf::Keyboard::Up)
		;
	if (tus == sf::Keyboard::Down)
		;
	if (tus == sf::Keyboard::Space)
		;
	if (tus == sf::Keyboard::E)
	{
		float cerfps = 1.0f / fps;
		m_cerceveSuresi = sf::seconds(cerfps);
		fps *= 2;
	}
}

void Uygulama::tusBirakildi(sf::Keyboard::Key tus)
{
}

void Uygulama::fareHareket(sf::Event::MouseMoveEvent olay)
{
	m_sahne.fareHareket(olay);
}

void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
	m_sahne.fareTiklandi(olay);
}

void Uygulama::fareBirakildi(sf::Event::MouseButtonEvent olay)
{
	m_sahne.fareBirakildi(olay);
}
