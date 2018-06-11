#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	this->level = 1;
}

Board::Board(std::vector<sf::Texture*>* textures)
{
	this->textures = textures;
}

Board::~Board()
{
	textures = nullptr;
	for (auto i = 0; i < maps.size(); ++i)
	{
		delete maps[i];
	}
}

void Board::GenerateLevel(std::shared_ptr<Player>& player, std::vector<Object*>& objects, std::vector<Pickable*>& pickableObjects, std::vector<Monster*>& monsters)
{
	if (this->maps.size() == NO_SIZE)
	{
		std::string exception = "There is no loaded maps my Lord!";
		throw exception;
	}
	else
	{
		unsigned int chosenMap = rand() % this->maps.size();
		for (auto i = 0; i < maps[chosenMap]->size(); ++i)
		{
			for (auto j = 0; j < maps[chosenMap][i].size(); ++i)
			{
				
			}
		}
	}
}

std::vector<std::string>* Board::LoadMap(const std::string & fileName)
{
	std::ifstream input(fileName.c_str());
	std::vector<std::string> file;
	if (input.is_open())
	{
		while (!input.eof())
		{
			std::string line;
			std::getline(input, line);
			file.push_back(line);
		}
		return &file;
	}
	else
	{
		return nullptr;
	}
}

void Board::LoadMaps()
{
	std::vector<std::string>* tmp = nullptr;
	unsigned int levelMap = 1;
	do
	{
		tmp = LoadMap(std::to_string(levelMap) + ".lvl");
		if (tmp != nullptr)
		{
			this->maps.push_back(tmp);
		}
	} while(tmp!=nullptr);
}

