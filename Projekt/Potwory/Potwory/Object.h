//Informacja pozycji na mapie, nazwa obiektu (chyba)
//x,y, textura, sprite
#pragma once
#include "stdafx.h"
class Object
{
public:
//Constructors/Destructors
	Object();
	~Object();
	Object(const float &x, const float &y);
	Object(const float &x, const float &y, const std::string &ID);
	Object(const float &x, const float &y, const std::string &ID, const std::string &fileName);
//Sets
	void SetPosition(const float &x,const float &y);//Set float x, y;
	void SetID(const std::string &ID);//Set ID of an Object
	void SetPositionToActualSprite();//Position x,y in class
	void SetPositionToActualSprite(const float &x, const float &y);//our Position (i.e. Teleport/absolut position)
	void SetTexture(const std::string &fileName);//Loading Texture from file
	virtual sf::Sprite TextureToSprite(sf::Texture *texture);//Load texture to vector of sprite;
	virtual void SetSprites();
//Gets
	float GetX();
	float GetY();
	std::string GetID();
//Methods
	void DrawToWindow(sf::RenderWindow *window);
private:
//Fields
	float x, y;
	std::string ID;
	sf::Texture texture;
	sf::Sprite actualSprite;
//Methods
	void SetX(const float &x); //Set float x
	void SetY(const float &y); //Set float y
};
