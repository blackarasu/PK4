#include "stdafx.h"
#include "Object.h"

Object::Object():Object(0.f,0.f,"I'm nothing")
{}

Object::~Object()
{
	if (actualSprite != nullptr)
	{
		delete actualSprite;
		actualSprite = nullptr;
	}
}

Object::Object(const float &x, const float &y)
{
	SetPosition(x, y);
}

Object::Object(const float &x, const float &y, const std::string &ID):Object(x, y)
{
	SetID(ID);
}

Object::Object(const float & x, const float & y, const std::string & ID, const sf::Texture & texture):Object(x,y,ID)
{
	SetSprites(texture);
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
	this->actualSprite->setPosition(this->mapPosition.x, this->mapPosition.y);
}

void Object::SetPositionToActualSprite(const float &x, const float &y)
{
	this->actualSprite->setPosition(x, y);
}

sf::Sprite* Object::TextureToSprite(const sf::Texture &texture) //use it for vector of sprites
{
	sf::Sprite* sprite= new sf::Sprite();
	sprite->setTexture(texture);
	return sprite;
}

void Object::SetSprites(const sf::Texture &texture)
{
	if (actualSprite == nullptr)
	{
		this->actualSprite = new sf::Sprite();
	}
	this->actualSprite->setTexture(texture);
}

float Object::GetX()
{
	return this->mapPosition.x;
}

float Object::GetY()
{
	return this->mapPosition.y;
}

sf::Vector2f Object::GetMapPosition()
{
	return this->mapPosition;
}

std::string Object::GetID()
{
	return this->ID;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void Object::DrawToWindow(sf::RenderWindow * window, sf::Vector2f *position)
{
	sf::IntRect actualSpritesRect = this->actualSprite->getTextureRect(); //getting Rectangle of actualSprite for calculating the maximumFieldOfMap
	sf::Vector2u windowSize = window->getSize(); //getting size of window in pixels (x,y)
	sf::Vector2u maximumField;
	if (actualSpritesRect.width > 0 && actualSpritesRect.height > 0)
	{
		maximumField.x = windowSize.x / actualSpritesRect.width;
		maximumField.y = windowSize.y / actualSpritesRect.height;
	}
	else
	{
		return;
	}
	sf::Vector2f actualPixel;
	actualPixel.x = (position->x < maximumField.x && position->x >= 0.f)? actualSpritesRect.width * position->x : actualSpritesRect.width * (maximumField.x-1.f);//calculating actualPixel.x of actualSprite
	actualPixel.y = (position->y < maximumField.y && position->y >= 0.f)? actualSpritesRect.height * position->y : actualSpritesRect.height * (maximumField.y-1.f);//calculating actualPixel.y of actualSprite*/
	this->actualSprite->setPosition(actualPixel);
	window->draw(*(this->actualSprite)); //drawing actualSprite to the window
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!