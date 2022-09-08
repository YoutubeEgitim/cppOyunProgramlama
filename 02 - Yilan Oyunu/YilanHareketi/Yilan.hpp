#pragma once
#include "Hucre.hpp"
class Yilan :public Cizilebilir
{
public:
	Yilan();

	void	ayarla(	float hucreBoyut, 
					float pencereGenislik, 
					float pencereYukseklik);
	void	kuyrugaEkle();
	void	hareket();
	void	yonAta(HucreYon yenYon);
	void	ciz(Pencere& pencere) override;
	void	yemKontrol();
	bool	sinirIcindemi();
	bool	kendiniYedimi();
private:
	
	void	yemiYenile();
	Hucre				m_yem;
	std::vector<Hucre>	m_hucreler;
	float				m_alinanMesafe;
	float				m_hucreBoyut;
	float				m_pencereGenislik;
	float				m_pencereYukseklik;

	HucreYon			m_yeniYon;


};
