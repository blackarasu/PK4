// Potwory.cpp : Defines the entry point for the console application.
//Dostęp do zaczecia gry i stowrzenie instancji okna

#include "stdafx.h"
#include "Game.h"
int main()
{
	srand(time(time_t(NULL)));
	Game *game = new Game();
	/*sf::RenderWindow window(sf::VideoMode(1366, 768), "Monsters");
	window.setFramerateLimit(60);
	std::vector<Object*> objects;
	for (auto i = 0; i < 10; ++i)
	{
		switch (rand() % 3)
		{
		case 0:
			//objects.push_back(new Object(float(1366/16- (1 + i)), float(768/16- (1 + i)), "Heart_small", "..//sprites//heart.png"));
			break;
		case 1:*/
			//objects.push_back(new Object(float(1366 / 16 - (1 + i)), float(768 / 16 - (1 + i)), "Heart_big",/* "pstro"));*/"..//sprites//blackheart.png"));
			/*break;
		case 2:
			//objects.push_back(new Object(float(1366/16- (1 + i)), float(768/16- (1 + i)), "Sword", "..//sprites//131078.png"));
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
	}*/
	delete game;
	return 0;
}

