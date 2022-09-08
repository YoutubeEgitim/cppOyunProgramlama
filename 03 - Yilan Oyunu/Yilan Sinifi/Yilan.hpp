#pragma once
#include "Hucre.hpp"
class Yilan :public Cizilebilir
{
public:
	Yilan();
	void	ayarla(	float hucreGenisligi,
					float pencereGenisligi,
					float pencereYuksekligi
					);

	void	kuyrugaEkle();
	void	hareket();
	void	yonAta(HucreYon yenYon);
	void	ciz(Pencere& pencere) override;
	void	yemiYedimi();
	bool	kendineCarptimi();
	bool	duvaraCarptimi();
	
private:
	void	yemUret();

	bool				m_hazirmi;
	bool				m_oyunBittimi;
	std::vector<Hucre>	m_hucreler;
	float				m_alinanMesafe;
	float				m_hucreBoyutu;
	float				m_pencereGenisligi;
	float				m_pencereYuksekligi;
	HucreYon			m_yeniYon;

	Hucre				m_yem;
};
