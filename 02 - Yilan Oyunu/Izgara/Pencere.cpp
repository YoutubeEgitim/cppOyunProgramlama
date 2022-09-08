#include "Pencere.hpp"

void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& baslik)
{

	m_pencere.create(sf::VideoMode(genislik, yukseklik), baslik);
}

void Pencere::ciz(sf::Drawable& sekil)
{
	m_pencere.draw(sekil);
}

void Pencere::olaylariIsle()
{
	sf::Event olay;

	while (m_pencere.pollEvent(olay))
	{
		if (olay.type == sf::Event::Closed)
			m_pencere.close();
		if (olay.type == sf::Event::KeyPressed)
		{
			for(auto siradaki:m_tusaBasFonksiyonlari)
				siradaki(olay.key.code);
		}
		if (olay.type == sf::Event::KeyReleased)
		{
			for (auto siradaki : m_tusuBirakFonksiyonlari)
				siradaki(olay.key.code);
		}
		if (olay.type == sf::Event::MouseMoved)
		{
			for (auto siradaki : m_fareHareketFonksiyonlari)
				siradaki(olay.mouseMove);
		}
	}
}

bool Pencere::pencereAcikmi()
{
	return m_pencere.isOpen();
}

void Pencere::temizle()
{
	m_pencere.clear(sf::Color::White);
}

void Pencere::goster()
{
	m_pencere.display();
}

void Pencere::tusaBasFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon)
{
	m_tusaBasFonksiyonlari.push_back( yeniFonksiyon);
}

void Pencere::tusuBirakFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon)
{
	m_tusuBirakFonksiyonlari.push_back(yeniFonksiyon);
}

void Pencere::fareHareketFonksiyonuEkle(FareHareketFonksiyonu yeniFonksiyon)
{
	m_fareHareketFonksiyonlari.push_back(yeniFonksiyon);
}

void Pencere::fareTiklamaFonksiyonuEkle(FareTiklamaFonksiyonu yeniFonksiyon)
{
	m_fareTiklamaFonksiyonlari.push_back(yeniFonksiyon);
}
