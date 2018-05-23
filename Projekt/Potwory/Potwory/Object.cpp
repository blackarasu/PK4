#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	this->mapPosition.x = 0;
	this->mapPosition.y = 0;
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
	try {
		SetTexture(fileName);
	}
	catch (std::string exp)
	{
		std::cout << exp << std::endl;
	}
	this->SetSprites();
}

void Object::SetX(const float &x)
{
	this->mapPosition.x = x;
}

void Object::SetY(const float &y)
{
	this->mapPosition.y = y;
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
	this->actualSprite.setPosition(this->mapPosition.x, this->mapPosition.y);
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
	return this->mapPosition.x;
}

float Object::GetY()
{
	return this->mapPosition.y;
}

std::string Object::GetID()
{
	return this->ID;
}

void Object::DrawToWindow(sf::RenderWindow * window)
{
	sf::IntRect actualSpritesRect = this->actualSprite.getTextureRect(); //getting Rectangle of actualSprite for calculating the maximumFieldOfMap
	sf::Vector2u windowSize = window->getSize(); //getting size of window in pixels (x,y)
	sf::Vector2u maximumField;
	maximumField.x = windowSize.x / actualSpritesRect.width;
	maximumField.y = windowSize.y/actualSpritesRect.height;
	sf::Vector2f actualPixel;
	actualPixel.x = (this->mapPosition.x < maximumField.x && this->mapPosition.x >= 0.f)? actualSpritesRect.width * this->mapPosition.x : actualSpritesRect.width * (maximumField.x-1.f);//calculating actualPixel.x of actualSprite
	actualPixel.y = (this->mapPosition.y < maximumField.y && this->mapPosition.y >= 0.f)? actualSpritesRect.height * this->mapPosition.y : actualSpritesRect.height * (maximumField.y-1.f);//calculating actualPixel.y of actualSprite*/
	this->actualSprite.setPosition(actualPixel);
	window->draw(this->actualSprite); //drawing actualSprite to the window
}