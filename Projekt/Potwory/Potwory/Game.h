//G³ówna pêtla gry, zarz¹dzanie innymi klasami 
//Posiada Console,
//Board,
//Menu,
//Score,
//Player
//Small_Monster
//Large_Monster
#pragma once
#include"stdafx.h"
#include"Constances.h"
class Game
{
public:
//constructors and destructors
	Game();
	~Game();
//getters

//setters
	//void SetTexture(const std::string &fileName);//Loading Texture from file
private:
	std::vector<sf::Texture> textures;
};



