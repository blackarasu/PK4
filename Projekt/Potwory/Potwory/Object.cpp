#include "stdafx.h"
#include "Object.h"

Object::Object():Object(0.f,0.f,"I'm nothing")
{
	actualSprite = nullptr;
}

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
	actualSprite = nullptr;
}

Object::Object(const float &x, const float &y, const std::string &ID):Object(x, y)
{
	this->ID = ID;
}

Object::Object(const float & x, const float & y, const std::string & ID, const sf::Texture & texture):Object(x,y,ID)
{
	SetSprites(texture);
	FixPosition();
}

Object::Object(const std::string & ID, const sf::Texture & texture) :Object(ID)
{
	SetSprites(texture);
	FixPosition();
}

Object::Object(const std::string & ID):Object(0,0)
{
	this->ID = ID;
}

void Object::SetX(const float &x)
{
	this->pixelsPositon.x = x;
}

void Object::SetY(const float &y)
{
	this->pixelsPositon.y = y;
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

void Object::SetActualSprite(sf::Sprite *newSprite)
{
	this->actualSprite = newSprite;
}

void Object::SetPositionToActualSprite()
{
	this->actualSprite->setPosition(this->pixelsPositon.x, this->pixelsPositon.y);
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
	return this->pixelsPositon.x;
}

float Object::GetY()
{
	return this->pixelsPositon.y;
}

sf::Vector2f Object::GetPixelsPosition()
{
	return this->pixelsPositon;
}

sf::Vector2f * Object::GetAddressPixelsPosition()
{
	return &(this->pixelsPositon);
}

std::string Object::GetID()
{
	return this->ID;
}
sf::Sprite * Object::GetActualSpriteAddress()
{
	return this->actualSprite;
}

void Object::DrawToWindow(sf::RenderWindow * window, sf::Vector2f *position)
{
	sf::Vector2u windowSize = window->getSize(); //getting size of window in pixels (x,y)
	sf::Vector2f actualPixel;
	actualPixel.x = (position->x < windowSize.x && position->x >= 0.f)? position->x : windowSize.x;//calculating actualPixel.x of actualSprite
	actualPixel.y = (position->y < windowSize.y && position->y >= 0.f)? position->y : windowSize.y;//calculating actualPixel.y of actualSprite*/
	this->actualSprite->setPosition(actualPixel);
	window->draw(*(this->actualSprite)); //drawing actualSprite to the window
}

inline void Object::FixPosition()
{
	sf::IntRect sizeOfSprite = this->actualSprite->getTextureRect();
	SetPosition(float(sizeOfSprite.width)*this->pixelsPositon.x, float(sizeOfSprite.height)*this->pixelsPositon.y);
	this->actualSprite->setPosition(this->GetPixelsPosition());
}
