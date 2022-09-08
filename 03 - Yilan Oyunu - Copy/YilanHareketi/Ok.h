#pragma once
#include "Cizilebilir.hpp"

class Ok :public Cizilebilir
{
public:
	
	void yonAta(const sf::Vector2f& yon);
		// Inherited via Cizilebilir
	virtual void baslat() override;

	virtual void guncelle(sf::Time& gecenSure) override;

	virtual void ciz(Pencere& pencere) override;
	float				m_uzunluk;
	float				m_radius;
	sf::Vector2f		m_yon;
	sf::RectangleShape	m_dogru;
	sf::CircleShape		m_bas;
};
