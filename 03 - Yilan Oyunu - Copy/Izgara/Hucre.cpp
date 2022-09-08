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
	m_sekil.setOutlineThickness(1);
	boyutAta(20);
	hizAta(1);
	yonAta(HucreYon::Sag);
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

float Hucre::boyutGetir()
{
	return m_boyut;
}

void Hucre::boyutAta(float boyut)
{
	m_boyut = boyut;
	m_sekil.setSize(sf::Vector2f(m_boyut, m_boyut));
}