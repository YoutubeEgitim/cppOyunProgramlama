#include "Pencere.hpp"
#include <imgui.h>
#include <imgui-SFML.h>
void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& baslik)
{

	m_pencere.create(sf::VideoMode(genislik, yukseklik), baslik);
	ImGui::SFML::Init(m_pencere);
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
		ImGui::SFML::ProcessEvent(olay);


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
		if (olay.type == sf::Event::MouseButtonPressed)
		{
			for (auto siradaki : m_fareTiklamaFonksiyonlari)
				siradaki(olay.mouseButton);
		}
		if (olay.type == sf::Event::MouseButtonReleased)
		{
			for (auto siradaki : m_fareBirakmaFonksiyonlari)
				siradaki(olay.mouseButton);
		}
	}
	
}

void Pencere::kapat()
{
	if(pencereAcikmi())
		m_pencere.close();

	ImGui::SFML::Shutdown();

}

bool Pencere::pencereAcikmi()
{
	return m_pencere.isOpen();
}

sf::RenderWindow& Pencere::pencereGetir()
{
	return m_pencere;
}



void Pencere::temizle()
{
	m_pencere.clear(sf::Color::White);
}

void Pencere::goster()
{
	ImGui::SFML::Render(m_pencere);
	m_pencere.display();
}

void Pencere::guncelle(const sf::Time& dt)
{
	ImGui::SFML::Update(m_pencere, dt);
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

void Pencere::fareBirakmaFonksiyonuEkle(FareTiklamaFonksiyonu yeniFonksiyon)
{
	m_fareBirakmaFonksiyonlari.push_back(yeniFonksiyon);
}
