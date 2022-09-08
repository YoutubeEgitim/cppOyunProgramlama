#pragma once
#include "Cizilebilir.hpp"
#include "Tank.hpp"
#include "VektorSekli.hpp"
#include "SesYoneticisi.hpp"
class TankOyunu :public Cizilebilir
{
public:
	TankOyunu(float sahneGenisligi, float sahneYuksekligi);
	// Inherited via Cizilebilir
	virtual void baslat() override;
	virtual void guncelle(const sf::Time& dt) override;
	virtual void ciz(Pencere& pencere) override;
	virtual void guiCizdir(const std::string& yazi = "")override;
	bool gulleDusmanaCarptimi();
	bool gulleSahneDisinaCiktimi();
	bool gulleZemineCarptimi();
	void seviyeYukle(const std::string& dosyaIsmi);
private:
	
	std::vector< std::vector<bool> > m_hucreMatrisi;
	float				m_hucreBoyutu;
	float				m_sahneGenisligi;
	float				m_sahneYuksekligi;
	int					m_satirSayisi;
	int					m_sutunSayisi;
	float				m_ateslemeGucu;
	sf::Vector2f		m_yercekimiSabiti;
	sf::Vector2f		m_gulleHareket;
	bool				m_gulleFirlatildimi;
	sf::CircleShape		m_gulle;
	sf::RectangleShape	m_zemin;
	Tank::TankPtr		m_solTank;
	Tank::TankPtr		m_sagTank;
	Tank::TankYonu		m_siradakiTank;
	SesYoneticisi		m_sesYoneticisi;

};