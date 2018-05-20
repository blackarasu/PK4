//Informacja pozycji na mapie, nazwa obiektu (chyba)
//x,y, textura, sprite
#pragma once
#include "stdafx.h"
class Object
{
public:
	Object();
	~Object();
	Object(float x, float y);
	Object(float x, float y, std::string ID);
	Object(float x, float y, std::string ID, std::string fileName);
//sets
	void setX(float x);
	void setY(float y);
	void setID(std::string ID);
	void setTexture(std::string fileName);
	virtual sf::Sprite textureToSprite(sf::Texture *texture);
	virtual void setSprite();
//gets
	float getX();
	float getY();
	std::string getID();

private:
	float x, y;
	std::string ID;
	sf::Texture texture;
	std::vector<sf::Sprite> sprites;
};
