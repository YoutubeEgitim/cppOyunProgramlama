#pragma once
#include "Cizilebilir.hpp"
#include "Ok.h"
class Sahne :public Cizilebilir
{
public:
	void guiCiz();
	sf::CircleShape m_daire;
	sf::CircleShape m_dogruBas;
	sf::CircleShape m_dogruSon;
	sf::RectangleShape	m_dogru;
	Ok					m_ok;
	float	m_yariCap;
	bool	m_yonBelirle;
	bool	m_hareketEtsinmi;
	bool	m_fareBasili;
	float	m_yonAci;
	sf::Vector2f	m_yon;
	sf::Vector2f	m_konum;
	// Inherited via Cizilebilir
	virtual void ciz(Pencere& pencere) override;
	void fareHareket(sf::Event::MouseMoveEvent olay);
	void fareTiklandi(sf::Event::MouseButtonEvent olay);
	void fareBirakildi(sf::Event::MouseButtonEvent olay);
	void	yonGuncelle();
	// Inherited via Cizilebilir
	virtual void baslat() override;

	virtual void guncelle(sf::Time& gecenSure) override;

};
