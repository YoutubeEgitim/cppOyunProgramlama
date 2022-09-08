#pragma once
#include "Cizilebilir.hpp"

class Izgara :public Cizilebilir
{
public:
	Izgara();
	void ayarla(float boyut, float aralik);

	
	void ciz(Pencere& pencere) override;
	
	
	virtual void baslat() override;


	virtual void guncelle(const sf::Time& dt) override;
private:
	
	sf::RectangleShape	m_yatayCizgi;
	sf::RectangleShape	m_dikeyCizgi;
	float				m_mesafe;
	float				m_boyut;
	int					m_cizgiSayisi;
	










};