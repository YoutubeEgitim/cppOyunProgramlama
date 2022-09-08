#pragma once
#include<functional>
#include<vector>
#include<SFML/Window/Event.hpp>


typedef std::function<void(sf::Keyboard::Key)>	KlavyeFonksiyonu;
typedef std::vector<KlavyeFonksiyonu>			KlavyeFonksiyonListesi;

typedef std::function<void(sf::Event::MouseMoveEvent)>	FareHareketFonksiyonu;
typedef std::vector<FareHareketFonksiyonu>				FareHareketFonkListesi;