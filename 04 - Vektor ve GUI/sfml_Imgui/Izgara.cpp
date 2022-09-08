#include "Izgara.hpp"
#include "Pencere.hpp"
Izgara::Izgara()
{
	ayarla(100, 10);
	
	m_yatayCizgi.setFillColor(sf::Color::Green);
	m_dikeyCizgi.setFillColor(sf::Color::Green);
}
void Izgara::ayarla(float boyut, float aralik)
{
	m_mesafe = aralik;
	m_boyut = boyut;
	m_cizgiSayisi = boyut / aralik;
	m_yatayCizgi.setSize(sf::Vector2f(m_boyut, 1.0f));
	m_dikeyCizgi.setSize(sf::Vector2f(1.0f, m_boyut));
}

void Izgara::ciz(Pencere& pencere)
{
	sf::Vector2f konum;
	for (int i = 0; i <=m_cizgiSayisi; i++)
	{
		konum.x = 0.0f;
		konum.y = i * m_mesafe;
		m_yatayCizgi.setPosition(konum);
		
		konum.x = i * m_mesafe;
		konum.y = 0.0f;
		m_dikeyCizgi.setPosition(konum);
		
		pencere.ciz(m_yatayCizgi);
		pencere.ciz(m_dikeyCizgi);
	}
}

void Izgara::baslat()
{

}

void Izgara::guncelle(const sf::Time& dt)
{
}



