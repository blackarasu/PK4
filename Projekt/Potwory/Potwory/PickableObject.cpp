#include "stdafx.h"
#include "PickableObject.h"

Pickable::Pickable()
{
	this->isPicked = false;
	this->playerPosition = nullptr;
}

Pickable::~Pickable()
{
	if (this->playerPosition != nullptr)
	{
		delete this->playerPosition;
	}
}

void Pickable::SetPlayerPosition(sf::Vector2f * playerPosition)
{
	this->playerPosition = playerPosition;
}

void Pickable::SetSprites(const sf::Texture & texture)
{
	this->sprites.push_back(sf::Sprite(texture, NOT_PICKED_RECT));
	this->sprites.push_back(sf::Sprite(texture, PICKED_RECT));
	this->sprites[PICKED].scale(0.25f, 0.25f);
	this->SetActualSprite(&(this->sprites[NOT_PICKED]));
}

sf::Vector2f * Pickable::GetPlayerPosition()
{
	return this->playerPosition;
}

void Pickable::DrawPickableObject(sf::RenderWindow * window, sf::IntRect &sizeOfPicker)
{
	if (this->isPicked == false)
	{
		DrawToWindow(window, &(this->GetMapPosition()));
	}
	else
	{
		sf::Vector2f fixedPosition = *(this->playerPosition);
		fixedPosition.x += sizeOfPicker.width * 0.5f;
		fixedPosition.y += sizeOfPicker.height * 0.5f;
		DrawToWindow(window, this->playerPosition);
	}
}

void Pickable::PickedMe(sf::Vector2f *playerPositon)
{
	this->isPicked = true;
	this->SetActualSprite(&(this->sprites[PICKED]));
	this->playerPosition = playerPosition;
}