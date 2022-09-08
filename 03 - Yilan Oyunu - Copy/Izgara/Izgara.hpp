#pragma once
#include "Cizilebilir.hpp"

class Izgara :public Cizilebilir
{
public:
	Izgara();
	void ayarla(float uzunluk, float aralik);
	virtual void ciz(Pencere& pencere) override;
private:

	float				m_aralik;
	float				m_uzunluk;
	int					m_cizgiSayisi;
	sf::RectangleShape	m_yatayCizgi;
	sf::RectangleShape	m_dikeyCizgi;
};