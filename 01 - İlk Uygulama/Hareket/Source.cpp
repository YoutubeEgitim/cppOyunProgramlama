#include<SFML/Graphics.hpp>
#include<iostream>


sf::CircleShape top1(20, 20);
sf::CircleShape top2(20, 20);
int yon = 1;
int hiz = 1;
void insaEt()
{
	top1.setPosition(0, 100);
	top1.setFillColor(sf::Color::Red);
	top2.setPosition(560, 100);
	top2.setFillColor(sf::Color::Red);
}
bool dursunmu = false;
void guncelle()
{
	top1.move(hiz*yon, 0);
	top2.move(-hiz * yon, 0);
	if (top1.getGlobalBounds().intersects(top2.getGlobalBounds()))
	{
		yon = -yon;
		hiz *= 2;
		top1.setFillColor(sf::Color::Blue);
		top2.setFillColor(sf::Color::Blue);
		
	}
	if (top1.getPosition().x <= 0.0f)
	{
		top1.setFillColor(sf::Color::Red);
		top2.setFillColor(sf::Color::Red);
		yon = -yon;
		dursunmu = true;
	}
}
int main()
{
	sf::RenderWindow pencere(sf::VideoMode(600, 200), "Merhaba0");

	sf::Clock	saat;

	insaEt();

	

	float cerceveSuresi = 1 / 60.0f;

	while (pencere.isOpen())
	{
		sf::Event olay;
		while (pencere.pollEvent(olay))
		{
			if (olay.type == sf::Event::Closed)
				pencere.close();

		}

		float gecenSure = saat.getElapsedTime().asSeconds();

		if (gecenSure >= cerceveSuresi)
		{
			if (!dursunmu)
			guncelle();

			pencere.clear(sf::Color::White);

				pencere.draw(top1);
				pencere.draw(top2);


			pencere.display();


			saat.restart();
		}
		else
		{
			sf::sleep(sf::seconds(cerceveSuresi - gecenSure));
		}




	}

}