class deneme
{

public:
	void yaz(sf::Keyboard::Key tus)
	{
		cout << "Merhaba" << endl;
	}
	void hareket(sf::Event::MouseMoveEvent fareOlayi)
	{
		cout << fareOlayi.x << "-" << fareOlayi.y << endl;
	}
};
void yaz1(sf::Keyboard::Key tus)
{
	cout << "hohoho" << endl;
}


int main()
{

	Pencere pencere;
	deneme yeniDeneme;

	pencere.tusaBasFonksiyonuEkle([](sf::Keyboard::Key tus) {
		std::cout << "tus:" << tus << std::endl;
		});

	pencere.fareHareketFonksiyonuEkle(
		std::bind(&deneme::hareket, &yeniDeneme, std::placeholders::_1)
	);
	pencere.tusuBirakFonksiyonuEkle(yaz1);
	sf::RectangleShape dikdortgen(sf::Vector2f(200, 200));
	pencere.olustur(800, 800);
	while (pencere.pencereAcikmi())
	{
		pencere.olaylariIsle();


		pencere.temizle();
		pencere.ciz(dikdortgen);
		pencere.goster();
	}
}




#include<iostream>
#include<string>
#include<functional>
#include "Pencere.hpp"
using namespace std;
#include <iostream>
using namespace std;
class Sekil
{
public:
	virtual void	ciz()
	{
		cout << "Sekil::Ciz()" << endl;
	}
};
class Pencerem
{
public:
	void sekilEkle(Sekil* yeniSekil)
	{
		sekiller.push_back(yeniSekil);
	}
	void sekilleriCiz()
	{
		for (auto siradaki : sekiller)
			siradaki->ciz();
	}
	std::vector<Sekil*> sekiller;
};




class Daire :public Sekil
{
public:
	void ciz() override
	{

		Sekil::ciz();
		cout << "daire ciz()" << endl;
	}
};
class Ucgen :public Sekil
{
public:
	void ciz()override
	{
		cout << "Ucgen ciz()" << endl;
	}
};
class Dikdortgen :public Sekil
{
public:
	void ciz()override
	{
		cout << "Dikdortgen ciz()" << endl;
	}
	int deneme = 30;
};
int main()
{
	Pencerem pencere;
	pencere.sekilEkle(new Daire());
	pencere.sekilEkle(new Dikdortgen());
	pencere.sekilEkle(new Ucgen());

	pencere.sekilleriCiz();

	auto* ptr = new Dikdortgen();
	auto* ptr2 = &ptr->deneme;

	int a = 5;


}