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
#include"Large_Monster.h"
#include"Object.h"
#include"Heart.h"
#include"Player.h"
#include"Score.h"
#include"Small_Monster.h"
#include"Sword.h"
#include"Wall.h"
#include"Interface.h"
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
	std::shared_ptr<Score> score;
	std::unique_ptr<GUI> ui;
//methods
	void SaveToLogFile(const std::string &logFileName, const std::string &message);
	template <class T>
	void CheckIntersection(T dynamicObject);
};

template<class T>
inline void Game::CheckIntersection(T dynamicObject)//only derivates of Dynamic 
{
	sf::FloatRect objectRectangle = dynamicObject->GetActualSpriteAddress()->getGlobalBounds();
	for (auto i = 0; i < pickableObjects.size(); ++i)//items
	{
		if (pickableObjects[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(objectRectangle))
		{
			dynamicObject->Pick(pickableObjects[i]);
			pickableObjects[i]->PickedMe(dynamicObject->GetAddressPixelsPosition());
			pickableObjects.erase(pickableObjects.begin() + i);//get rid off picked item from vector (it stills exists);
		}
	}
	for (auto i = 0; i < objects.size(); ++i)
	{
		if (objects[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(objectRectangle))
		{
			if (objects[i]->DoAction(*(dynamicObject->GetAddressHP())))//ie. heart
			{
				delete objects[i];
				objects.erase(objects.begin() + i);
			}
			objects[i]->DoAction(*(dynamicObject->GetAddressPixelsPosition()), dynamicObject->GetLastMove(), frametime, dynamicObject->GetSpeed()); //ie. walls
		}
	}
	if (dynamicObject->GetID() != player->GetID())//if true dynamicObject is ie. monster
	{
		//if monster sticks with player->
		//monster attack
	}

	//add monsters
}
