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
#include"Board.h"
#include"C:\Program Files (x86)\Visual Leak Detector\include\vld.h"
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
	std::vector<Monster*> monsters;
	std::vector<Pickable*> pickableObjects; //vector for Pickable(Object)
	std::vector<sf::Texture*> textures; //vector for textures
	std::shared_ptr<Score> score;
	std::unique_ptr<GUI> ui;
	std::unique_ptr<Board> board;
//methods
	void SaveToLogFile(const std::string &logFileName, const std::string &message);
	inline void CatchAttackKey();
	template <class T>
	void CheckIntersection(T dynamicObject);
};

template<class T>
inline void Game::CheckIntersection(T dynamicObject)//only derivates of Dynamic 
{
	sf::FloatRect objectRectangle = dynamicObject->GetActualSpriteAddress()->getGlobalBounds();
	sf::Vector2f dynamicObjectPosition = dynamicObject->GetPixelsPosition();
	objectRectangle.left = dynamicObjectPosition.x;//fixing Rectangle
	objectRectangle.top = dynamicObjectPosition.y;//fixing Rectangle
	--objectRectangle.height;//to fit into hole between two walls
	--objectRectangle.width;//to fit into hole between two walls
	for (auto i = 0; i < this->objects.size(); ++i)
	{
		if (this->objects[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(objectRectangle))
		{
			this->objects[i]->DoAction(*(dynamicObject->GetAddressPixelsPosition()), dynamicObject->GetLastMove(), this->frametime, dynamicObject->GetSpeed()); //ie. walls
			if (this->objects[i]->DoAction(*(dynamicObject->GetAddressHP())))//ie. heart
			{
				delete this->objects[i];
				this->objects.erase(objects.begin() + i);
			}
			break;//small chance to hit more than 1 object at the same time
		}
	}
	for (auto i = 0; i < this->pickableObjects.size(); ++i)//items
	{
		if (this->pickableObjects[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(objectRectangle))
		{
			if (dynamicObject->GetItem() == nullptr /*|| dynamicObject->GetItem()->GetEndurance()==0*/)
			{
				dynamicObject->Pick(pickableObjects[i]);
				this->pickableObjects[i]->PickedMe(dynamicObject->GetAddressPixelsPosition());
				this->pickableObjects.erase(this->pickableObjects.begin() + i);//get rid off picked item from vector (it stills exists);
			}
			break;//small chance to hit more than 1 object at the same time
		}
	}
}
