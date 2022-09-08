#pragma once
#include "Cizilebilir.hpp"


enum class HucreYon
{
	Sol,
	Sag,
	Yukari,
	Asagi

};

class Hucre :public Cizilebilir
{
public:
	Hucre();
	
	Hucre		hucreUret();
	void		yonAta(HucreYon yon);
	HucreYon	yonGetir();
	float		boyutGetir();
	void		boyutAta(float boyut);
	void		hizAta(float hiz);
	float		hizGetir();

	void		hareket(float gecenSure);
	void		renkAta(sf::Color renk);
	void ciz(Pencere& pencere) override;
private:
	float				m_alinanYol;
	HucreYon			m_yon;
	sf::RectangleShape	m_sekil;
	float				m_boyut;
	float				m_hiz;
};
typedef std::vector<Hucre> HucreListesi;