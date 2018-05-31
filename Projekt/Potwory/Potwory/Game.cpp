#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(DEFAULT_SIZE_VIDEO, "Potwory.exe", sf::Style::Default);
	LoadTextures();
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
		try
		{
			this->textures.push_back(LoadTexture(fileLocations[i]));
		}
		catch (std::string exception)
		{
			std::cout << exception << std::endl;
			SaveToLogFile("TexturesErrors.log", exception);
		}
	}
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
		logFile << "<" << actualTime << "> " << message << std::endl;
	}
	logFile.close();
}
