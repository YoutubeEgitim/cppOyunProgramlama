#include "Yilan.hpp"

Yilan::Yilan()
{
	m_alinanMesafe = 0.0f;
	m_yeniYon = HucreYon::Sag;
	m_hazirmi = false;
	m_yem.renkAta(sf::Color::Black);
}

void Yilan::ayarla(float hucreGenisligi, float pencereGenisligi, float pencereYuksekligi)
{
	m_hazirmi = true;
	m_oyunBittimi = false;
	m_hucreBoyutu = hucreGenisligi;
	m_pencereGenisligi = pencereGenisligi;
	m_pencereYuksekligi = pencereYuksekligi;

	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	
}

void Yilan::kuyrugaEkle()
{
	if (m_hucreler.size())
	{
		Hucre yeniHucre = m_hucreler.back().hucreUret();
		yeniHucre.boyutAta(m_hucreBoyutu);
		m_hucreler.push_back(yeniHucre);
	}
	else
	{
		m_hucreler.push_back(Hucre());
	}

}

void Yilan::hareket()
{
	if (!m_hazirmi||m_oyunBittimi)
		return;

	for (auto& siradaki : m_hucreler)
	{
		siradaki.hareket();
	}
	m_alinanMesafe += m_hucreler[0].hizGetir();

	if (m_alinanMesafe == m_hucreler[0].boyutGetir())
	{
		if (duvaraCarptimi())
			m_oyunBittimi = true;
		if (kendineCarptimi())
			m_oyunBittimi = true;

		for (int i = m_hucreler.size() - 1; i > 0; i--)
		{
			m_hucreler[i].yonAta(m_hucreler[i - 1].yonGetir());
		}
		m_hucreler[0].yonAta(m_yeniYon);
		m_alinanMesafe = 0.0f;
	}

	
}

void Yilan::yonAta(HucreYon yenYon)
{

	m_yeniYon = yenYon;
		
}

void Yilan::ciz(Pencere& pencere)
{
	if (!m_hazirmi)
		return;
	m_yem.ciz(pencere);
	for (auto& siradaki : m_hucreler)
	{
		siradaki.ciz(pencere);
	}

}

void Yilan::yemUret()
{
	int sutunSayisi = m_pencereGenisligi / m_hucreBoyutu;
	int satirSayisi = m_pencereYuksekligi / m_hucreBoyutu;
	float x = (std::rand() % sutunSayisi)*m_hucreBoyutu;
	float y= (std::rand() % satirSayisi) * m_hucreBoyutu;

	m_yem.konumAta(sf::Vector2f(x, y));
}

void Yilan::yemiYedimi()
{
	if (m_hucreler[0].konumGetir() == m_yem.konumGetir())
	{
		yemUret();
		kuyrugaEkle();
	}

}

bool Yilan::kendineCarptimi()
{
	int hucreSayisi = m_hucreler.size();
	for (int i = 1; i < hucreSayisi; i++)
	{
		if (m_hucreler[0].konumGetir() == m_hucreler[i].konumGetir())
			return true;
	}
	return false;
}

bool Yilan::duvaraCarptimi()
{
	if (m_hucreler[0].konumGetir().x<0 ||
		m_hucreler[0].konumGetir().x + m_hucreBoyutu>m_pencereGenisligi ||
		m_hucreler[0].konumGetir().y < 0 ||
		m_hucreler[0].konumGetir().y + m_hucreBoyutu>m_pencereYuksekligi)
	{
		return true;
	}
	return false;
}
