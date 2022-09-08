#pragma once
#include "Pencere.hpp"
#include "Izgara.hpp"
#include "Sahne.hpp"
class Uygulama
{
public:
	Uygulama();
	void insaEt(int genislik, int yukseklik);
	void baslat(int fps = 60);
	Sahne& sahne();
private:
	void guiPanelCiz();
	void cerceveOlustur();
	void cizimFonksiyonu();
	void sahneGuncelle();
	void tusBasildi(sf::Keyboard::Key tus);
	void tusBirakildi(sf::Keyboard::Key tus);
	void fareHareket(sf::Event::MouseMoveEvent olay);
	void fareTiklandi(sf::Event::MouseButtonEvent olay);
	void fareBirakildi(sf::Event::MouseButtonEvent olay);

	Izgara		m_izgara;
	Sahne		m_sahne;
	Pencere		m_pencere;
	sf::Clock	m_saat;
	sf::Time	m_cerceveSuresi;
	sf::Time	m_gecenSure;

};