#pragma once
#include "Cizilebilir.hpp"

class Ok :public Cizilebilir
{
public:
	Ok();
	// Inherited via Cizilebilir
	virtual void baslat() override;
	virtual void guncelle(const sf::Time& dt) override;
	virtual void ciz(Pencere& pencere) override;


	virtual void yonAta(const sf::Vector2f& yon);

	void renkAta(sf::Color renk);
	
	void basKonumAta(const sf::Vector2f& basKonum);
	void sonKonumAta(const sf::Vector2f& sonKonum);

	void kalinlikAta(float kalinlik);
	void okUzunluguAta(float okUzunlugu);
	void degerGoster(bool gostersinmi);

protected:
	bool				m_degerlerGorulsunmu;
	sf::Text			m_yazi;
	sf::Font			m_font;
	float				m_uzunluk;
	float				m_dogruKalinlik;
	float				m_okBasiUzunlugu;
	sf::Vector2f		m_yon;
	
	sf::RectangleShape	m_dogru;
	sf::CircleShape		m_okBasi;
};
