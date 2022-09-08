#include "Ok.hpp"
#include "Pencere.hpp"
#include "Math.hpp"
#include <sstream>




Ok::Ok()
{
	m_dogruKalinlik = 4.0f;
	m_okBasiUzunlugu = m_dogruKalinlik * 2;

	if (!m_font.loadFromFile("./fontlar/arial.ttf"))
	{
		// error...
	}

	m_dogru.setFillColor(sf::Color::Blue);
	m_dogru.setPosition(sf::Vector2f(100, 100));


	m_okBasi.setFillColor(sf::Color::Red);


	m_yazi.setFont(m_font);
	m_yazi.setCharacterSize(12);
	m_yazi.setFillColor(sf::Color::Red);
	m_yazi.setStyle(sf::Text::Bold);
	
}

void Ok::baslat()
{



}	

void Ok::guncelle(const sf::Time& dt)
{
	
}

void Ok::ciz(Pencere& pencere)
{
	
	pencere.ciz(m_dogru);
	pencere.ciz(m_okBasi);
	
	if(m_degerlerGorulsunmu)
		pencere.ciz(m_yazi);
	

	
}

void Ok::basKonumAta(const sf::Vector2f& basKonum)
{
	m_konum = basKonum;
	m_dogru.setPosition(basKonum);
	
	
}




void Ok::sonKonumAta(const sf::Vector2f& sonKonum)
{
	auto yon = sonKonum - m_dogru.getPosition();
	yonAta(yon);
}

void Ok::renkAta(sf::Color renk)
{
	m_dogru.setFillColor(renk);
	m_okBasi.setFillColor(renk);
}

void Ok::kalinlikAta(float kalinlik)
{
	m_dogruKalinlik = kalinlik;
}

void Ok::okUzunluguAta(float okUzunlugu)
{
	m_okBasiUzunlugu = okUzunlugu;
}

void Ok::degerGoster(bool gostersinmi)
{
	m_degerlerGorulsunmu = gostersinmi;
}


void Ok::yonAta(const sf::Vector2f& yon)
{
	m_yon = yon;

	float uzunluk = Math::length(m_yon);
	
	
	auto vecX = sf::Vector2f(1.0f, 0.0f);
	auto cosq = Math::dotNormalize(m_yon, vecX);
	auto radAci = acosf(cosq);
	float aci = Math::radToDeg(radAci);

	if (m_yon.y <= 0.0f)
		aci = 360.0f - aci;

	float  oran =1-( m_okBasiUzunlugu / uzunluk);
	
	m_dogru.setSize(sf::Vector2f(uzunluk-m_okBasiUzunlugu, m_dogruKalinlik));
	m_dogru.setOrigin(sf::Vector2f(0.0f, m_dogruKalinlik / 2.0f));
	m_dogru.setRotation(aci);
	m_okBasi.setRadius(m_okBasiUzunlugu);
	m_okBasi.setPointCount(3);
	m_okBasi.setPosition(m_dogru.getPosition()+m_yon* oran);
	m_okBasi.setOrigin(sf::Vector2f(m_okBasiUzunlugu, m_okBasiUzunlugu));
	m_okBasi.setRotation(90.0f + aci);

	m_yazi.setPosition(m_konum + m_yon);



	std::ostringstream cikis;
	cikis.precision(1);
	cikis << "(";
	cikis << std::fixed << m_yon.x << "," << std::fixed << m_yon.y << ")";
	m_yazi.setString(cikis.str());
}

