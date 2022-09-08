#include<SFML/Graphics.hpp>
#include<iostream>

enum class YON
{
	SOL,
	SAG,
	YUKARI,
	ASAGI
};
void hareket(sf::Vector2f& konum, YON yon)
{
	switch (yon)
	{
	case YON::SAG:
		konum.x += 5;
		break;
	case YON::SOL:
		konum.x -= 5;
		break;
	case YON::YUKARI:
		konum.y -= 5;
		break;
	case YON::ASAGI:
		konum.y += 5;
	}

}
int main()
{
	sf::RenderWindow pencere(sf::VideoMode(600, 600), "Merhaba0");

	sf::Clock	saat;
	sf::CircleShape daire(100, 12);
	sf::RectangleShape dortgen(sf::Vector2f(100,100));
	daire.setFillColor(sf::Color::Red);
	daire.setOutlineThickness(2.0f);
	daire.setOutlineColor(sf::Color::Yellow);
	daire.setPosition(sf::Vector2f(100, 100));

	sf::Vector2f konum(100, 100);
	YON sekilYonu = YON::SAG;
	float cerceveSuresi = 1 / 60.0f;
	sf::Vector2f baslangic;
	bool cizimTamamlandimi = true;
	while (pencere.isOpen())
	{
		
		sf::Event olay;
		while (pencere.pollEvent(olay))
		{
			if (olay.type == sf::Event::Closed)
				pencere.close();

			if (olay.type == sf::Event::MouseMoved)
			{
				if (!cizimTamamlandimi)
				{
					sf::Vector2f son(olay.mouseMove.x, olay.mouseMove.y);
					float genislik = son.x - baslangic.x;
					float yukseklik = son.y - baslangic.x;
					dortgen.setSize(sf::Vector2f(genislik, yukseklik));
				}
	
			}
			if (olay.type == sf::Event::MouseButtonPressed)
			{
				if (olay.mouseButton.button == sf::Mouse::Left)
				{
					//baslangic = sf::Vector2f(olay.mouseButton.x, olay.mouseButton.y);
					//dortgen.setPosition(baslangic);
					//cizimTamamlandimi = false;
				}
				
			}

			if (olay.type == sf::Event::MouseButtonReleased)
			{
				if (olay.mouseButton.button == sf::Mouse::Left)
				{
					
					//cizimTamamlandimi = true;
				}
			}
			if (olay.type == sf::Event::KeyReleased)
			{
				if (olay.key.code == sf::Keyboard::Left)
				{
					//std::cout << "Sol tus birakildi" << std::endl;
				}
			}
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << "Sol tusa Basildi" << std::endl;
		}
		float gecenSure = saat.getElapsedTime().asSeconds();

		if (gecenSure >= cerceveSuresi)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{

				sekilYonu = YON::SOL;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sekilYonu = YON::SAG;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sekilYonu = YON::YUKARI;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sekilYonu = YON::ASAGI;
			}


			pencere.clear();

			hareket(konum, sekilYonu);
			daire.setPosition(konum);
			pencere.draw(daire);
			pencere.draw(dortgen);
			pencere.display();


			int fps = 1.0f / gecenSure;
			pencere.setTitle(std::to_string(fps));
			saat.restart();
		}
		else
		{
			sf::sleep(sf::seconds(cerceveSuresi - gecenSure));
		}




	}

}