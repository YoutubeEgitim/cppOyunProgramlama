
#include<iostream>
#include<string>
#include "Uygulama.hpp"
#include "Sahne.hpp"
#include "TankOyunu.hpp"
using namespace std;
#include<SFML/Audio.hpp>
int main()
{

	Uygulama uygulama;
	uygulama.insaEt(1800, 900);

	auto yeniTank = std::make_shared<TankOyunu>(1800,900);
	yeniTank->seviyeYukle("./seviyeler/seviye2.txt");
	uygulama.sahne().cocukEkle(yeniTank);
	

	
	uygulama.baslat(60);
	
}