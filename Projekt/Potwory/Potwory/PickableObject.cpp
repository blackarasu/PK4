#include "stdafx.h"
#include "PickableObject.h"

Pickable::Pickable():Object(0,0,"I'm nothing")
{
	this->isPicked = false;
	this->playerPosition = nullptr;
}

Pickable::Pickable(const float & x, const float & y, const std::string ID):Object(x,y,ID)
{
	this->isPicked = false;
	this->playerPosition = nullptr;
}

Pickable::Pickable(const std::string ID, sf::Vector2f *playerPosition):Object(ID)
{
	PickedMe(playerPosition);
}

Pickable::Pickable(const float & x, const float & y, const std::string ID, const sf::Texture & texture):Object(x,y,ID)
{
	SetSprites(texture);
	FixPosition();
	this->isPicked = false;
	this->playerPosition = nullptr;
}

Pickable::Pickable(const std::string ID, const sf::Texture & texture, sf::Vector2f* playerPosition):Object(ID,texture)
{
	PickedMe(playerPosition);
}

Pickable::~Pickable()
{
	this->playerPosition = nullptr;
	SetActualSprite(nullptr);
}

void Pickable::SetPlayerPosition(sf::Vector2f* playerPosition)
{
	this->playerPosition = playerPosition;
}

void Pickable::SetSprites(const sf::Texture & texture)
{
	this->sprites.push_back(sf::Sprite(texture, NOT_PICKED_RECT));
	this->sprites.push_back(sf::Sprite(texture, PICKED_RECT));
	this->sprites[Picked::PICKED].scale(0.25f, 0.25f);//need to test it 
	this->SetActualSprite(&(this->sprites[Picked::NOT_PICKED]));
}

sf::Vector2f * Pickable::GetPlayerPosition()
{
	return this->playerPosition;
}

bool Pickable::IsPicked()
{
	return this->isPicked;
}

void Pickable::DrawPickableObject(sf::RenderWindow * window,const sf::IntRect &sizeOfPicker)
{
	if (playerPosition != nullptr) //check it 
	{
		sf::Vector2f fixedPosition = *(this->playerPosition);
		fixedPosition.x += sizeOfPicker.width * 0.5f;
		fixedPosition.y += sizeOfPicker.height * 0.5f;
		DrawToWindow(window, this->playerPosition);
	}
}

void Pickable::PickedMe(sf::Vector2f *playerPosition)
{
	this->isPicked = true;
	this->SetActualSprite(&(this->sprites[Picked::PICKED]));
	this->playerPosition = playerPosition;
}