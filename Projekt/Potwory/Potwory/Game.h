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
#include"Object.h"
#include"Constances.h"
class Game
{
public:
//constructors and destructors
	Game();
	~Game();
//getters

//setters
	sf::Texture* LoadTexture(const std::string &fileName);//Loading Texture from file
	void LoadTextures();//n times LoadTexture
private:
//fields
	sf::Event event;
	sf::RenderWindow *window;
	std::vector<Object*> objects;
	std::vector<sf::Texture*> textures;
//methods
	void SaveToLogFile(const std::string &logFileName, const std::string &message);
};



