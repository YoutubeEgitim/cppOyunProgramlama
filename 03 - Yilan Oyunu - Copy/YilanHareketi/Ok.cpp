#include "Ok.h"
#include "Pencere.hpp"
#include "Math.hpp"
void Ok::yonAta(const sf::Vector2f& yon)
{
	m_yon = normalize(yon);
	float d = dot(m_yon, normalize(sf::Vector2f(1.0f, 0.0f)));

	float aci = RadToDeg(acos(d));
	if (m_yon.y <= 0)
		aci = 360.0f - aci;
	m_dogru.setSize(sf::Vector2f(m_uzunluk- m_radius, 4.0f));
	m_dogru.setOrigin(sf::Vector2f(0.0f, 2.0f));
	m_dogru.setRotation(aci);
	m_bas.setRotation(90 + aci);
	float centerToHeight = m_radius * sqrtf(3.0f) / 2.0f;
	m_bas.setPosition(m_konum + m_yon * (m_uzunluk - centerToHeight));
}

void Ok::baslat()
{
	m_yon = sf::Vector2f(1.0f, 0.0f);
	m_uzunluk = 100.0f;
	m_konum = sf::Vector2f(100, 100);
	m_radius = 15;
	m_dogru.setOrigin(sf::Vector2f(0, 2.0f));
	m_dogru.setPosition(m_konum);
	m_dogru.setFillColor(sf::Color::Red);
	m_bas = sf::CircleShape(m_radius, 3);

	float centerToHeight = m_radius * sqrtf(3.0f) / 2.0f;


	m_bas.setOrigin(m_radius, m_radius);
	m_bas.rotate(90.0f);
	
	m_bas.setFillColor(sf::Color::Blue);
	
	m_bas.setPosition(m_konum + m_yon * (m_uzunluk - centerToHeight));
	m_dogru.setSize(sf::Vector2f(m_uzunluk- m_radius, 4.0f));
}

void Ok::guncelle(sf::Time& gecenSure)
{
	m_dogru.setPosition(m_konum);
	
}

void Ok::ciz(Pencere& pencere)
{
	pencere.ciz(m_dogru);
	pencere.ciz(m_bas);

}
