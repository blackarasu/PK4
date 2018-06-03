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
#include"Heart.h"
#include"Sword.h"
#include"Wall.h"
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
	void AddWall(Wall *wall); //add wall to objects
	void AddSword(Sword *sword); //add sword to pickableObjects
	void AddHeart(Heart *heart); //add heart to objects
//methods
	void GameLoop();//main GameLoop
private:
//fields
	sf::Event event; //event element
	sf::RenderWindow *window; //pointer to window (probably will be moved to Console but who knows)
	std::vector<Object*> objects; //vector for objects
	std::vector<Pickable*> pickableObjects; //vector for Pickable(Object)
	std::vector<sf::Texture*> textures; //vector for textures
//methods
	void SaveToLogFile(const std::string &logFileName, const std::string &message);
};



