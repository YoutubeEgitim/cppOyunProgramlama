#include "TankOyunu.hpp"
#include "imgui.h"
#include "Pencere.hpp"
#include "Math.hpp"
#include<fstream>
#include<sstream>
#include<iostream>
#include<iomanip>

TankOyunu::TankOyunu(float sahneGenisligi, float sahneYuksekligi)
{
	
	m_sahneGenisligi = sahneGenisligi;
	m_sahneYuksekligi = sahneYuksekligi;
	m_hucreBoyutu = 50.0f;

	m_satirSayisi = sahneYuksekligi / m_hucreBoyutu;
	m_sutunSayisi = m_sahneGenisligi / m_hucreBoyutu;

	m_ateslemeGucu = 1.0f;
	m_gulle.setRadius(m_hucreBoyutu * 0.25f);
	m_gulle.setOrigin(sf::Vector2f(m_hucreBoyutu *0.25f, m_hucreBoyutu *0.25f));
	m_gulle.setFillColor(sf::Color::Black);
	m_zemin.setSize(sf::Vector2f(m_sahneGenisligi, 100));
	m_zemin.setPosition(sf::Vector2f(0, m_sahneYuksekligi - 100));
	m_zemin.setFillColor(sf::Color::Green);
	m_gulleFirlatildimi = false;
	m_yercekimiSabiti = sf::Vector2f(0.0f, 0.01f);

	m_solTank = std::make_shared<Tank>(Tank::TankYonu::Sag);
	m_sagTank = std::make_shared<Tank>(Tank::TankYonu::Sol);
	m_siradakiTank = Tank::TankYonu::Sag;

	m_solTank->konumAta(sf::Vector2f(100, m_sahneYuksekligi - 100));
	m_sagTank->konumAta(sf::Vector2f(m_sahneGenisligi - 200, m_sahneYuksekligi - 100));
	m_solTank->isimAta("solTank");
	m_sagTank->isimAta("sagTank");

	m_sesYoneticisi.sesDosyasiEkle("topAtes", "./sesler/cannon_fire.ogg");
	m_sesYoneticisi.sesDosyasiEkle("topVurdu", "./sesler/cannon_hit_cannon.ogg");


	cocukEkle(m_solTank);
	cocukEkle(m_sagTank);
	
}
void TankOyunu::baslat()
{
	Cizilebilir::baslat();

}

void TankOyunu::guncelle(const sf::Time& dt)
{
	Cizilebilir::guncelle(dt);
	if (m_gulleFirlatildimi)
	{	
		if (gulleSahneDisinaCiktimi()||gulleZemineCarptimi())
		{
			m_gulleFirlatildimi = false;

			if(m_siradakiTank==Tank::TankYonu::Sag)
				m_siradakiTank = Tank::TankYonu::Sol;
			else
				m_siradakiTank = Tank::TankYonu::Sag;
			
		}
		else
		{
			m_gulleHareket += m_yercekimiSabiti;
			auto yeniPozisyon = m_gulle.getPosition() + m_gulleHareket;
			m_gulle.setPosition(yeniPozisyon);
		}

	}
		
}

void TankOyunu::ciz(Pencere& pencere)
{
	if (m_gulleFirlatildimi)
		pencere.ciz(m_gulle);
	for (int satir = 0; satir < m_satirSayisi; satir++)
	{

		for (int sutun = 0; sutun < m_sutunSayisi; sutun++)
		{
			if (m_hucreMatrisi[satir][sutun])
			{
				float x = sutun * m_hucreBoyutu;
				float y = satir * m_hucreBoyutu;
				m_zemin.setPosition(sf::Vector2f(x, y));
				m_zemin.setSize(sf::Vector2f(m_hucreBoyutu, m_hucreBoyutu));
				pencere.ciz(m_zemin);
			}
		}
	}
	Cizilebilir::ciz(pencere);

	
}

void TankOyunu::guiCizdir(const std::string& yazi)
{
	Cizilebilir::guiCizdir(yazi);

	ImGui::SliderFloat("guc", &m_ateslemeGucu, 1, 10, "%0.1f");

	if (ImGui::Button("Ates")&&m_gulleFirlatildimi==false)
	{
		if (m_siradakiTank == Tank::TankYonu::Sag)
		{
			m_gulleHareket = m_solTank->namluYonuGetir() * m_ateslemeGucu;
			auto yeniPozisyon = m_solTank->namluPozisyonuGetir();
			m_gulle.setPosition(yeniPozisyon);

			m_gulleFirlatildimi = true;
		}
		else
		{
			m_gulleHareket = m_sagTank->namluYonuGetir() * m_ateslemeGucu;
			auto yeniPozisyon = m_sagTank->namluPozisyonuGetir();
			m_gulle.setPosition(yeniPozisyon);

			m_gulleFirlatildimi = true;
		}
		m_sesYoneticisi.sesOynat("topAtes");
	}
}

bool TankOyunu::gulleDusmanaCarptimi()
{
	return false;
}

bool TankOyunu::gulleSahneDisinaCiktimi()
{
	bool sonuc = false;
	if (m_gulle.getPosition().x < 0)
	{
		sonuc = true;
	}
	if (m_gulle.getPosition().x > m_sahneGenisligi)
	{
		sonuc = true;
	}
	return sonuc;
}

bool TankOyunu::gulleZemineCarptimi()
{
	bool sonuc = false;
	sf::Vector2f gulleMerkez = m_gulle.getPosition();
	float yariCap = m_gulle.getRadius();
	for (int satir = 0; satir < m_satirSayisi; satir++)
	{
		for (int sutun = 0; sutun < m_sutunSayisi; sutun++)
		{
			if (m_hucreMatrisi[satir][sutun])
			{
				float x = sutun * m_hucreBoyutu;
				float y = satir * m_hucreBoyutu;

				sf::Vector2f kareMerkez(x + m_hucreBoyutu * 0.5f, y + m_hucreBoyutu * 0.5);
				
				if (Math::daireKareCarpisiyormu(gulleMerkez,yariCap,kareMerkez, m_hucreBoyutu))
				{
					m_gulleHareket = sf::Vector2f(0.0f, 0.0f);
					sonuc = true;
					m_sesYoneticisi.sesOynat("topVurdu");
					
				}
					
				
			}



		}
	}


	return sonuc;
}

void TankOyunu::seviyeYukle(const std::string& dosyaIsmi)
{
	bool solTankOkundumu = false;
	bool sagTankOkundumu = false;
	m_hucreMatrisi.resize(m_satirSayisi);
	std::ifstream dosya(dosyaIsmi);

	if (dosya.is_open())
	{
		for (int satir = 0; satir < m_satirSayisi; satir++)
		{
			m_hucreMatrisi[satir].resize(m_sutunSayisi,false);
			for (int sutun = 0; sutun < m_sutunSayisi; sutun++)
			{
				
				char ch;
				dosya >> ch;
				
				if (ch == '#')
					m_hucreMatrisi[satir][sutun] = true;
				if (ch == 'S')
				{
					dosya >> ch;
					float x = sutun * m_hucreBoyutu;
					float y = satir * m_hucreBoyutu;
					if (ch == 'O'&&!solTankOkundumu)
					{
						solTankOkundumu = true;
						m_solTank->konumAta(sf::Vector2f(x, y));
					}
					else if (ch == 'A'&&!sagTankOkundumu)
					{
						sagTankOkundumu = true;
						m_sagTank->konumAta(sf::Vector2f(x, y));
					}
					sutun++;
				}
					
			}

		}
		
		

	}
}


