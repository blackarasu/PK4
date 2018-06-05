//G��wna p�tla gry, zarz�dzanie innymi klasami 
//Posiada Console,
//Board,
//Menu,
//Score,
//Player
//Small_Monster
//Large_Monster
#pragma once
#include"stdafx.h"
#include"Large_Monster.h"
#include"Object.h"
#include"Heart.h"
#include"Player.h"
#include"Score.h"
#include"Small_Monster.h"
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
	bool IsAnyKeyPressed();
private:
//fields
	float frametime;
	sf::Clock clock;
	sf::Event event; //event element
	sf::RenderWindow *window; //pointer to window (probably will be moved to Console but who knows)
	std::vector<Object*> objects; //vector for objects
	std::shared_ptr<Player>player;
	//std::vector<Monster*> monsters;
	std::vector<Pickable*> pickableObjects; //vector for Pickable(Object)
	std::vector<sf::Texture*> textures; //vector for textures
//methods
	void SaveToLogFile(const std::string &logFileName, const std::string &message);
};



