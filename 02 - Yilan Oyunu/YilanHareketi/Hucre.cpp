#include "Hucre.hpp"
#include "Pencere.hpp"
void Hucre::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);
	pencere.ciz(m_sekil);
}

Hucre::Hucre()
{
	m_sekil.setFillColor(sf::Color::Red);
	m_sekil.setOutlineColor(sf::Color::Blue);
	m_sekil.setOutlineThickness(2);
	boyutAta(30);
	hizAta(5);
	yonAta(HucreYon::Sag);
}



Hucre Hucre::hucreUret()
{
	sf::Vector2f yeniKonum = m_konum;

	switch (m_yon)
	{
	case HucreYon::Sag:
		yeniKonum.x -= m_boyut;
		break;
	case HucreYon::Sol:
		yeniKonum.x += m_boyut;
		break;
	case HucreYon::Yukari:
		yeniKonum.y += m_boyut;
		break;
	case HucreYon::Asagi:
		yeniKonum.y -= m_boyut;
		break;
	}
	Hucre yeniHucre;
	yeniHucre.konumAta(yeniKonum);
	yeniHucre.yonAta(m_yon);
	return yeniHucre;
}

void Hucre::yonAta(HucreYon yon)
{
	m_yon = yon;
}

HucreYon Hucre::yonGetir()
{
	return m_yon;
}
void Hucre::hizAta(float hiz)
{
	m_hiz = hiz;
}

float Hucre::hizGetir()
{
	return m_hiz;
}

void Hucre::hareket()
{
	switch (m_yon)
	{
	case HucreYon::Sag:
		m_konum.x += m_hiz;
		break;
	case HucreYon::Sol:
		m_konum.x -= m_hiz;
		break;
	case HucreYon::Yukari:
		m_konum.y -= m_hiz;
		break;
	case HucreYon::Asagi:
		m_konum.y += m_hiz;
		break;
	}
}
void Hucre::renkAta(sf::Color renk)
{
	m_sekil.setFillColor(renk);
}
float Hucre::boyutGetir()
{
	return m_boyut;
}

void Hucre::boyutAta(float boyut)
{
	m_boyut = boyut;
	m_sekil.setSize(sf::Vector2f(m_boyut, m_boyut));
}