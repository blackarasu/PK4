// Potwory.cpp : Defines the entry point for the console application.
//Dostęp do zaczecia gry i stowrzenie instancji okna

#include "stdafx.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(50.f);
	shape.setPosition(50.f, 50.f);
	shape.setFillColor(sf::Color::Magenta);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}

