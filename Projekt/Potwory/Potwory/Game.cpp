#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(DEFAULT_SIZE_VIDEO, "Potwory.exe", sf::Style::Default);
	this->window->setFramerateLimit(60);
	LoadTextures();
	player =std::make_shared<Player>(10.f, 5.f, *(this->textures[CHARACTER]), 100, sf::Vector2f{200.f,200.f});
	objects.push_back(new Heart(2.f, 3.f, *(textures[HEART])));
	objects.push_back(new Wall(4.f, 5.f, *(textures[WALL])));
	pickableObjects.push_back(new Sword(10.5f, 2.f, *(textures[SWORD])));
}

Game::~Game()
{
	for (auto i = 0; i < textures.size(); ++i)
	{
		delete textures[i];
	}
	for (auto i = 0; i < objects.size(); ++i)
	{
		delete objects[i];
	}
	for (auto i = 0; i < pickableObjects.size(); ++i)
	{
		delete pickableObjects[i];
	}
}

sf::Texture* Game::LoadTexture(const std::string & fileName)
{
	sf::Texture* texture= new sf::Texture();
	if (!texture->loadFromFile(fileName))
	{
		std::string exception = "File " + fileName + " could not be opened!";
		throw exception;
	}
	return texture;
}

void Game::LoadTextures()
{
	for (auto i = 0; i < fileLocations.size(); ++i)
	{
		bool no_Error = true;
		try
		{
			this->textures.push_back(LoadTexture(fileLocations[i]));
		}
		catch (std::string exception)
		{
			no_Error = false;
			std::cout << exception << std::endl;
			SaveToLogFile("TexturesErrors.log", exception);
		}
		if (no_Error)
		{
			std::cout << "File " << fileLocations[i] << " has been loaded properly" << std::endl;
		}
	}
}

void Game::AddWall(Wall * wall)
{
	objects.push_back(wall);
}

void Game::AddSword(Sword * sword)
{
	pickableObjects.push_back(sword);
}

void Game::AddHeart(Heart * heart)
{
	objects.push_back(heart);
}

void Game::GameLoop()
{
	while (window->isOpen())
	{
		/*if (player->GetHP() <= 0)
		{
			//endGame ->saveScore,ShowScores and waits for button to restart game with other random map
		}*/
		frametime = clock.restart().asSeconds();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window->close();
			}
			player->Move(frametime);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				sf::FloatRect attackRectangle=player->Attack();
				if (attackRectangle.height != 0 && attackRectangle.width != 0)
				{
					////for loop for all monsters (check if they intersects attackRectangle) (intersects returns true if rect intersects over other rect) 
				}
			}
			if (!IsAnyKeyPressed())
			{
				player->NoMove();//Stay still
			}
		}
		CheckIntersection(player);//check intersection with player
		//for(auto i=0; i<monsters.size();++i)//check intersection for every monster
		//{
		//	CheckIntersection(monsters[i]);
		//}
		window->clear();//black screen
	//DRAW
		for (auto i = 0; i < objects.size(); ++i)
		{
			objects[i]->DrawToWindow(window, objects[i]->GetAddressPixelsPosition());//draw all others objects
		}
		for (auto i = 0; i < pickableObjects.size(); ++i)
		{
			pickableObjects[i]->DrawToWindow(window, pickableObjects[i]->GetAddressPixelsPosition());//draw all unpicked pickableObjects on window
		}
		player->DrawToWindow(window, player->GetAddressPixelsPosition());//draw player to window
		if (player->GetItem() != nullptr)
		{
			player->GetItem()->DrawPickableObject(window, player->GetActualSpriteAddress()->getGlobalBounds(), player->GetLastMove());//draw pickableObject on player
		}
		window->display();
	}
}

bool Game::IsAnyKeyPressed()
{
	for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
			return true;
	}
	return false;
}

void Game::SaveToLogFile(const std::string & logFileName, const std::string & message)
{
	time_t timer;
	time(&timer);
	std::ofstream logFile(logFileName.c_str(), std::ios_base::app);
	if (logFile.is_open())
	{
		char actualTime[26];
		ctime_s(actualTime, 26, &timer);
		for (int i = 0; i < 26; ++i)
		{
			if (actualTime[i] == '\n' || actualTime[i] == '\r')
			{
				actualTime[i] = '\0';
			}
		}
		logFile << "<" << actualTime << "> " << message << std::endl;
	}
	logFile.close();
}



