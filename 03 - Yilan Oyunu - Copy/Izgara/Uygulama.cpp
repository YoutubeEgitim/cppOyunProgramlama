#include "Uygulama.hpp"
#include <iostream>
#include "Hucre.hpp"
#include "Izgara.hpp"
Hucre hucre;
Izgara izgara;

Uygulama::Uygulama()
{
	
	

}

void Uygulama::insaEt(int genislik, int yukseklik)
{
	m_pencere.olustur(genislik, yukseklik);
	izgara.ayarla(genislik, 20);
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
	hucre.ciz(m_pencere);
	izgara.ciz(m_pencere);
	m_pencere.goster();
}

void Uygulama::sahneGuncelle()
{
	hucre.hareket();
}

void Uygulama::tusBasildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Left)
		hucre.yonAta(HucreYon::Sol);
	if (tus == sf::Keyboard::Right)
		hucre.yonAta(HucreYon::Sag);
	if (tus == sf::Keyboard::Up)
		hucre.yonAta(HucreYon::Yukari);
	if (tus == sf::Keyboard::Down)
		hucre.yonAta(HucreYon::Asagi);
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
