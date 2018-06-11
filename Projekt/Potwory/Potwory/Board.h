//Informacje o polach �cian, dr�g itp, wielko�� mapy
//Tablica map do wylosowania, przekierowanie do bufora itp.
#pragma once
#include "stdafx.h"
#include "GameObjects.h"
class Board
{
public:
//constructors/destructors
	Board();
	Board(std::vector<sf::Texture *> *textures);
	~Board();
//methods
	void GenerateLevel(std::shared_ptr<Player> &player,std::vector<Object*> &objects, std::vector<Pickable*> &pickableObjects,std::vector<Monster*> &monsters);
private:
//fields
	std::vector<sf::Texture *> *textures;
	unsigned int level;
	std::vector<std::vector<std::string>*> maps;
//methods
	std::vector<std::string>* LoadMap(const std::string &fileName);
	void LoadMaps();
};
