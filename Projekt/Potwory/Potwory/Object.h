//Informacja pozycji na mapie, nazwa obiektu (chyba)
//x,y, textura, sprite
#pragma once
#include "stdafx.h"
#include "Constances.h"
class Object
{
public:
//Constructors/Destructors
	Object();
	~Object();
	Object(const float &x, const float &y);
	Object(const float &x, const float &y, const std::string &ID);
	Object(const float &x, const float &y, const std::string &ID, const std::string &fileName);
//Setters
	void SetPosition(const float &x,const float &y);//Set float x, y;
	void SetID(const std::string &ID);//Set ID of an Object
	void SetPositionToActualSprite();//Position x,y in class
	void SetPositionToActualSprite(const float &x, const float &y);//our Position (i.e. Teleport/absolut position)
	void SetTexture(const std::string &fileName);//Loading Texture from file -> nieoptymalne, obmyslic by moglo byc w game.h
	virtual sf::Sprite TextureToSprite(sf::Texture *texture);//Load texture to vector of sprite;
	virtual void SetSprites();
//Getters
	float GetX();
	float GetY();
	std::string GetID();
//Methods
	void DrawToWindow(sf::RenderWindow *window);
	virtual void DoAction() = 0;
private:
//Fields
	sf::Vector2f mapPosition;
	std::string ID;
	sf::Texture texture; //nieoptymalne
	sf::Sprite actualSprite;
//Methods
	void SetX(const float &x); //Set mapPosition.x
	void SetY(const float &y); //Set mapPosition.y
};
