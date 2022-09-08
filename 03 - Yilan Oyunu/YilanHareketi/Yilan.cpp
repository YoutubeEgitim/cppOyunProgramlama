#include "Yilan.hpp"
#include <random>
#include<iostream>
Yilan::Yilan()
{
	
	m_yeniYon = HucreYon::Sag;
	m_alinanMesafe = 0;

}
void	Yilan::ayarla(float hucreBoyut,
					  float pencereGenislik,
					  float pencereYukseklik)
{
	m_pencereGenislik = pencereGenislik;
	m_pencereYukseklik = pencereYukseklik;
	m_hucreBoyut = hucreBoyut;
	yemiYenile();
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();

}
void Yilan::yemKontrol()
{

	if (m_hucreler[0].konumGetir() == m_yem.konumGetir())
	{
		kuyrugaEkle();
		yemiYenile();

		bool carpismaVarmi;
		do
		{
			carpismaVarmi = false;
			for (auto& siradaki : m_hucreler)
			{
				if (siradaki.konumGetir() == m_yem.konumGetir())
				{
					yemiYenile();
					carpismaVarmi = true;
					break;
				}
			}
		} while (carpismaVarmi);
	}
}
bool Yilan::sinirIcindemi()
{
	if (m_hucreler[0].konumGetir().x<0 ||
		m_hucreler[0].konumGetir().x + m_hucreBoyut>m_pencereGenislik ||
		m_hucreler[0].konumGetir().y<0 ||
		m_hucreler[0].konumGetir().y + m_hucreBoyut>m_pencereYukseklik)
		return false;


	return true;
}

bool Yilan::kendiniYedimi()
{
	int hucreSayisi = m_hucreler.size();

	for (int i = 2; i < hucreSayisi; i++)
	{
		if (m_hucreler[0].konumGetir() == m_hucreler[i].konumGetir())
			return true;
	}
	return false;
}

void Yilan::kuyrugaEkle()
{
	Hucre yeniHucre;
	if (m_hucreler.size())
	{
		yeniHucre = m_hucreler.back().hucreUret();
	}
	yeniHucre.boyutAta(m_hucreBoyut);
	
	m_hucreler.push_back(yeniHucre);

}

void Yilan::hareket(float gecenSure)
{
	if (!sinirIcindemi())
		return;
	if (kendiniYedimi())
		return;
	
	for (auto& siradaki : m_hucreler)
	{
		siradaki.hareket(gecenSure);
	}
	m_alinanMesafe += m_hucreler[0].hizGetir();
	

	if (m_alinanMesafe == m_hucreler[0].boyutGetir())
	{
		yemKontrol();

		for (int i = m_hucreler.size() - 1; i > 0; i--)
		{
			m_hucreler[i].yonAta(
				m_hucreler[i - 1].yonGetir()
			);
		}
		m_hucreler[0].yonAta(m_yeniYon);
		m_alinanMesafe = 0.0f;
	}
}

void Yilan::yonAta(HucreYon yeniYon)
{
	if (yeniYon == HucreYon::Sag && m_hucreler[0].yonGetir() == HucreYon::Sol)		return;
	if (yeniYon == HucreYon::Sol && m_hucreler[0].yonGetir() == HucreYon::Sag)		return;
	if (yeniYon == HucreYon::Yukari && m_hucreler[0].yonGetir() == HucreYon::Asagi)return;
	if (yeniYon == HucreYon::Asagi && m_hucreler[0].yonGetir() == HucreYon::Yukari)return;
	m_yeniYon = yeniYon;
	
}

void Yilan::ciz(Pencere& pencere)
{
	m_yem.ciz(pencere);
	for (auto& siradaki : m_hucreler)
	{
		siradaki.ciz(pencere);
	}
}

void Yilan::yemiYenile()
{
	int sutunSayisi = m_pencereGenislik / m_hucreBoyut;
	int satirSayisi = m_pencereYukseklik / m_hucreBoyut;
	float x = (rand()%sutunSayisi) * m_hucreBoyut;
	float y = (rand() % satirSayisi) * m_hucreBoyut;
	m_yem.konumAta(sf::Vector2f(x, y));
	m_yem.boyutAta(m_hucreBoyut);
	m_yem.renkAta(sf::Color::Black);
}

