#include "Izgara.hpp"
#include "Pencere.hpp"
Izgara::Izgara()
{
	ayarla(100, 10);
	m_yatayCizgi.setFillColor(sf::Color::Green);
	m_dikeyCizgi.setFillColor(sf::Color::Green);
}
void Izgara::ciz(Pencere& pencere)
{
	sf::Vector2f konum;
	for (int i = 0; i <= m_cizgiSayisi; i++)
	{
		konum.x = 0.0f;
		konum.y = i * m_aralik;
		m_yatayCizgi.setPosition(konum);
		pencere.ciz(m_yatayCizgi);
		//dikey cizgiler ciziliyor
		konum.x = i * m_aralik;
		konum.y = 0.0f;
		m_dikeyCizgi.setPosition(konum);
		pencere.ciz(m_dikeyCizgi);

	}

}
void Izgara::ayarla(float uzunluk, float aralik)
{
	m_aralik = aralik;
	m_uzunluk = uzunluk;
	m_cizgiSayisi = uzunluk / aralik;

	m_yatayCizgi.setSize(sf::Vector2f(m_uzunluk, 1.0f));
	m_dikeyCizgi.setSize(sf::Vector2f(1.0f, m_uzunluk));
}
