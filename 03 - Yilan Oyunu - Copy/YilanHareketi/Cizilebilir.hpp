#pragma once
#include<SFML/Graphics.hpp>

class Pencere;
class Cizilebilir
{
public:
	virtual void	baslat()=0;
	virtual void	guncelle(sf::Time& gecenSure)=0;
	virtual void	ciz(Pencere& pencere) = 0;
	void			konumAta(const sf::Vector2f& konum);
	sf::Vector2f	konumGetir();
protected:
	sf::Vector2f	m_konum;
};
