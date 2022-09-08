#pragma once

#include<SFML/Graphics.hpp>
#include "FonksiyonTurleri.hpp"
class Pencere
{
public:
	void olustur(unsigned int genislik,
		unsigned int yukseklik,
		const sf::String& baslik = "SFML");
	void ciz(sf::Drawable& sekil);
	void olaylariIsle();

	bool pencereAcikmi();
	sf::RenderWindow& pencereGetir();
	void temizle();
	void goster();
	void tusaBasFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon);
	void tusuBirakFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon);
	void fareHareketFonksiyonuEkle(FareHareketFonksiyonu yeniFonksiyon);
	void fareTiklamaFonksiyonuEkle(FareTiklamaFonksiyonu yeniFonksiyon);
	void fareBirakmaFonksiyonuEkle(FareTiklamaFonksiyonu yeniFonksiyon);
private:
	KlavyeFonksiyonListesi	m_tusaBasFonksiyonlari;
	KlavyeFonksiyonListesi	m_tusuBirakFonksiyonlari;

	FareHareketFonkListesi	m_fareHareketFonksiyonlari;
	FareTiklamaFonkListesi	m_fareTiklamaFonksiyonlari;
	FareTiklamaFonkListesi	m_fareBirakmaFonksiyonlari;
	sf::RenderWindow		m_pencere;
};

