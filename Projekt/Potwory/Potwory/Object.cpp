#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	this->x = 0;
	this->y = 0;
}

Object::~Object()
{
}

Object::Object(const float &x, const float &y)
{
	SetPosition(x, y);
}

Object::Object(const float &x, const float &y, const std::string &ID):Object(x, y)
{
	SetID(ID);
}

Object::Object(const float &x, const float &y,const std::string &ID, const std::string &fileName):Object(x,y,ID)
{
	SetTexture(fileName);
}

void Object::SetX(const float &x)
{
	this->x = x;
}

void Object::SetY(const float &y)
{
	this->y = y;
}

void Object::SetPosition(const float &x, const float &y)
{
	SetX(x);
	SetY(y);
}

void Object::SetID(const std::string &ID)
{
	this->ID = ID;
}

void Object::SetPositionToActualSprite()
{
	this->actualSprite.setPosition(this->x, this->y);
}

void Object::SetPositionToActualSprite(const float &x, const float &y)
{
	this->actualSprite.setPosition(x, y);
}

void Object::SetTexture(const std::string &fileName)
{
	if (!this->texture.loadFromFile(fileName))
	{
		std::string exception = "File " + fileName + " not found!";
		throw exception;
	}
}

sf::Sprite Object::TextureToSprite(sf::Texture *texture) //use it for vector of sprites
{
	sf::Sprite sprite;
	sprite.setTexture(*texture);
	return sprite;
}

void Object::SetSprites()
{
	this->actualSprite.setTexture(this->texture);
}

float Object::GetX()
{
	return this->x;
}

float Object::GetY()
{
	return this->y;
}

std::string Object::GetID()
{
	return this->ID;
}

void Object::DrawToWindow(sf::RenderWindow * window)
{
	window->draw(actualSprite);
}