//Informacje o polach œcian, dróg itp, wielkoœæ mapy
//Tablica map do wylosowania, przekierowanie do bufora itp.
#pragma once
#include "stdafx.h"
#include "GameObjects.h"
class Board
{
public:
//constructors/destructors
	Board();
	Board(const std::vector<sf::Texture *> &textures);
	~Board();
//methods
	void GenerateLevel(std::shared_ptr<Player> &player,std::vector<Object*> &objects, std::vector<Pickable*> &pickableObjects,std::vector<Monster*> &monsters);
private:
//fields
	const std::string FILE_NAME = "..//levels//";
	std::vector<sf::Texture *> textures;
	unsigned int level;
	std::vector<std::vector<std::string>> maps;
//methods
	bool LoadMap(const std::string &fileName);
	void LoadMaps();
};
