#pragma once
#include<SFML/Graphics.hpp>

class Pencere;
class Cizilebilir
{
public:
	Cizilebilir();
	virtual void ciz(Pencere& pencere) = 0;

	sf::Vector2f konumGetir();
protected:
	bool			m_cizilecekmi;
	sf::Vector2f	m_konum;
};
