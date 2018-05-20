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

Object::Object(float x, float y, std::string ID)
{
	setX(x);
	setY(y);
	setID(ID);
}

Object::Object(float x, float y, std::string ID, std::string fileName):Object(x,y,ID)
{
	setTexture(fileName);
}

void Object::setX(float x)
{
	this->x = x;
}

void Object::setY(float y)
{
	this->y = y;
}

void Object::setID(std::string ID)
{
	this->ID = ID;
}

void Object::setTexture(std::string fileName)
{
	if (!this->texture.loadFromFile(fileName))
	{
		std::string exception = "File " + fileName + " not found!";
		throw exception;
	}
}

sf::Sprite Object::textureToSprite(sf::Texture *texture)
{
	sf::Sprite sprite;
	sprite.setTexture(*texture);
	return sprite;
}

void Object::setSprite()
{
	this->sprites.push_back(textureToSprite(&texture));
}

float Object::getX()
{
	return this->x;
}

float Object::getY()
{
	return this->y;
}

std::string Object::getID()
{
	return this->ID;
}
