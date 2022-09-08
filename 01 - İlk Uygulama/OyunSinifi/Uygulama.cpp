#include "Uygulama.hpp"
#include <iostream>
sf::RectangleShape kare;
float aci = 0.5f;
float aciArtirma = 1.0f;
float yon = 1.0f;


Uygulama::Uygulama()
{
	kare.setSize(sf::Vector2f(100, 100));
	kare.setOrigin(sf::Vector2f(50, 50));
	kare.setPosition(300, 100);
	kare.setOutlineColor(sf::Color::Red);
	kare.setOutlineThickness(4.0f);
	kare.setFillColor(sf::Color::White);
	



}

void Uygulama::insaEt(int genislik, int yukseklik)
{
	m_pencere.olustur(genislik, yukseklik);

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

}

void Uygulama::cerceveOlustur()
{
	sahneGuncelle();
	cizimFonksiyonu();
}

void Uygulama::cizimFonksiyonu()
{
	
	kare.rotate(aci);
	kare.move(sf::Vector2f(yon, 0));
	auto pos = kare.getPosition();
	if (yon == 1) 
	{
		if (pos.x >= 600)
		{
			yon = -1;
			aci = -1.0f;
		}
	}
	else
	{
		if (pos.x <= 0)
		{
			yon = 1;
			aci = 1.0f;
		}
			
	}
	m_pencere.temizle();

	m_pencere.ciz(kare);
	m_pencere.goster();
}

void Uygulama::sahneGuncelle()
{
}

void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{
	auto pos =  kare.getPosition();
	if (tus==sf::Keyboard::Left)
	{

		pos.x -= 10;

	}
	if (tus == sf::Keyboard::Right)
	{
		pos.x += 10;
	}

	kare.setPosition(pos);

}

void Uygulama::tusBirakildi(sf::Keyboard::Key tus)
{
}

void Uygulama::fareHareket(sf::Event::MouseMoveEvent olay)
{
}

void Uygulama::fareTiklandi(sf::Event::MouseButtonEvent olay)
{
}
