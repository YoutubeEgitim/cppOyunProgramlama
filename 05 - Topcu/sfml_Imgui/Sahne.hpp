#pragma once
#include "Cizilebilir.hpp"
#include "VektorSekli.hpp"
class Sahne :public Cizilebilir
{
public:
	Sahne();
	Sahne(const Sahne&) =delete;
	typedef std::shared_ptr<Sahne> SahnePtr;
	void daireMerkezAta(const sf::Vector2f& merkez);
	void daireSonKonumAta(const sf::Vector2f& merkez);
	void daireBittimi(bool bittimi);
	void guiCizdir();
	

	virtual void baslat() override;
	virtual void guncelle(const sf::Time& dt) override;
	virtual void ciz(Pencere& pencere) override;
private:
	bool				m_bilesenGoster;
	bool				m_panelUzerindemi;
	bool				m_degisimVarmi;
	float				m_aci;
	float				m_dogruYukseklik;
	sf::Vector2f		m_vecFark;
	sf::Vector2f		m_basKonum;
	sf::Vector2f		m_sonKonum;
	sf::CircleShape		m_daire;
	sf::CircleShape		m_nokta;
	sf::RectangleShape	m_dogru;
	
	
};