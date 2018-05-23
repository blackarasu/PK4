// Potwory.cpp : Defines the entry point for the console application.
//Dostęp do zaczecia gry i stowrzenie instancji okna

#include "stdafx.h"
#include "Object.h"
#include <time.h>
int main()
{
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Monsters");
	window.setFramerateLimit(60);
	std::vector<Object*> objects;
	for (auto i = 0; i < 10; ++i)
	{
		switch (rand() % 3)
		{
		case 0:
			objects.push_back(new Object(float(i), float(i), "Heart_small", "..//sprites//heart.png"));
			break;
		case 1:
			objects.push_back(new Object(float(i), float(i), "Heart_big", "..//sprites//blackheart.png"));
			break;
		case 2:
			objects.push_back(new Object(float(i), float(i), "Sword", "..//sprites//131078.png"));
			break;
		}
		
	}
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
		for (auto i = 0; i < objects.size(); ++i)
		{
			objects[i]->DrawToWindow(&window);
		}
		window.display();
	}
	return 0;
}

