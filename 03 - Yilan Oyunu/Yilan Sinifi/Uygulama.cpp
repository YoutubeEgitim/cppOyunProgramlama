#include "Uygulama.hpp"
#include <iostream>

Uygulama::Uygulama()
{
	m_izgara.ayarla(600, 30);
	std::srand(time(0));

}

void Uygulama::insaEt(int genislik, int yukseklik)
{
	m_pencere.olustur(genislik, yukseklik);
	m_yilan.ayarla(30, genislik, yukseklik);
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
	m_pencere.temizle();
	m_izgara.ciz(m_pencere);
	m_yilan.ciz(m_pencere);
	
	m_pencere.goster();
}

void Uygulama::sahneGuncelle()
{
	m_yilan.yemiYedimi();
	m_yilan.hareket();
	
}

void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Left)
		m_yilan.yonAta(HucreYon::Sol);
	if (tus == sf::Keyboard::Right)
		m_yilan.yonAta(HucreYon::Sag);
	if (tus == sf::Keyboard::Up)
		m_yilan.yonAta(HucreYon::Yukari);
	if (tus == sf::Keyboard::Down)
		m_yilan.yonAta(HucreYon::Asagi);
	if (tus == sf::Keyboard::Space)
		m_yilan.kuyrugaEkle();
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


