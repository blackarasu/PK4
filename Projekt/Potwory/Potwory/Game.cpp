#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(DEFAULT_SIZE_VIDEO, "Potwory.exe", sf::Style::Default);
	this->window->setFramerateLimit(60);
	LoadTextures();
	player = nullptr;
	board = std::make_unique<Board>(textures);
	try
	{
		board->GenerateLevel(player, objects, pickableObjects, monsters);
	}
	catch (std::string exception)
	{
		std::cout << exception << std::endl;
		SaveToLogFile("MapsErrors.log", exception); 
		std::cout << "Loaded default level " << std::endl;
		player = std::make_shared<Player>(10.f, 5.f, *(this->textures[CHARACTER]), 100, sf::Vector2f{ 200.f,200.f });
		objects.push_back(new Heart(2.f, 3.f, *(textures[HEART])));
		objects.push_back(new Wall(4.f, 5.f, *(textures[WALL])));
		pickableObjects.push_back(new Sword(10.5f, 2.f, *(textures[SWORD])));
		pickableObjects.push_back(new Sword(20.5f, 2.f, *(textures[SWORD])));
	}
	score = std::make_shared<Score>();
	try
	{
		ui = std::make_unique<GUI>(window, player, score,board->GetAdressLevel());
	}
	catch (std::string exception)
	{
		std::cout << exception << std::endl;
		SaveToLogFile("FontsErrors.log", exception);
	}
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
	clock.restart();//right before game starting for the least diff
	while (window->isOpen())
	{
		frametime = clock.restart().asSeconds();//it should be first to get good AI decide
		if (player->GetHP() <= 0)
		{//endGame ->saveScore,ShowScores and waits for button to restart game with other random map
			score->EndGameScreen(window, &event, ui->GetFont());
			score->ResetScore();
			board->PrepareForNewLevel(objects, pickableObjects, monsters);
			board->ResetLevel();
			if (!player.unique())
			{
				ui->ResetPlayerPointer();
			}
			player.reset();
			board->GenerateLevel(player,objects,pickableObjects,monsters);
			ui->setPlayer(player);
			clock.restart();//restart game
			frametime = clock.restart().asSeconds();//get newest frametime
		}
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window->close();
			}
		}
		CatchAttackKey();
		if (player != nullptr)
		{
			player->Move(frametime);
			/*if (!IsAnyKeyPressed())
			{
			player->NoMove();//Stay still
			}*/
			CheckIntersection(player);//check intersection with player
		}
		for (auto i = 0; i < monsters.size(); ++i)//check intersection for every monster
		{
			monsters[i]->Decide(player,objects,frametime);//AI
			CheckIntersection(monsters[i]); //Check if went into object and grab;
		}
		window->clear();//black screen
	//DRAW
		if (ui)
		{
			ui->DrawInterface();
		}
		for (auto i = 0; i < objects.size(); ++i)
		{
			objects[i]->DrawToWindow(window, objects[i]->GetAddressPixelsPosition());//draw all others objects
		}
		for (auto i = 0; i < pickableObjects.size(); ++i)
		{
			pickableObjects[i]->DrawToWindow(window, pickableObjects[i]->GetAddressPixelsPosition());//draw all unpicked pickableObjects on window
		}
		for (auto i = 0; i < monsters.size(); ++i)
		{
			monsters[i]->DrawToWindow(window, monsters[i]->GetAddressPixelsPosition());
			if (monsters[i]->GetItem() != nullptr)
			{
				monsters[i]->GetItem()->DrawPickableObject(window, monsters[i]->GetActualSpriteAddress()->getGlobalBounds(), monsters[i]->GetLastMove());//draw pickableObject on monster
			}
		}
		if (player != nullptr)
		{
			player->DrawToWindow(window, player->GetAddressPixelsPosition());//draw player to window
			if (player->GetItem() != nullptr)
			{
				player->GetItem()->DrawPickableObject(window, player->GetActualSpriteAddress()->getGlobalBounds(), player->GetLastMove());//draw pickableObject on player
			}
		}
		window->display();
		if (monsters.size() == NO_SIZE)//level finished
		{
			board->PrepareForNewLevel(objects, pickableObjects);
			board->NextLevel(player, objects, pickableObjects, monsters);
		}
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

inline void Game::CatchAttackKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		sf::FloatRect attackRectangle = player->Attack();
		if (attackRectangle.height != NO_SIZE && attackRectangle.width != NO_SIZE)//you can do attack
		{
			/*for (auto i = 0; i < objects.size(); ++i)
			{
				if (objects[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(attackRectangle)) //Test on normal objects
				{
				delete objects[i];
				objects.erase(objects.begin() + i);
				score->ScoreUp(board->GetLevel(), 1);
				break;
				}
			}*/
			for (auto i = 0; i < monsters.size(); ++i)
			{
				if (monsters[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(attackRectangle)) //Test on monsters
				{
					monsters[i]->TakeDamage(player->GetItem()->GetDamage());
					if (monsters[i]->GetHP() <= DEAD)
					{
						score->ScoreUp(board->GetLevel(), Monsters::NORMAL);
						delete monsters[i];
						monsters.erase(monsters.begin() + i);
					}
				    //break;it would be too hard for normal human being
				}
			}
		}
		if (player->GetItem() != nullptr)
		{
			if (player->GetItem()->GetEndurance() == 0)//after attack -> after attack animation to be more precisely
			{
				delete player->GetItem();
				Pickable *nullItem = nullptr;
				player->Pick(nullItem);
			}
		}
	}
}



