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

void Pickable::DrawPickableObject(sf::RenderWindow * window)
{
	if (this->isPicked == false)
	{
		DrawToWindow(window, &(this->GetMapPosition()));
	}
	else
	{
		DrawToWindow(window, &(this->playerPosition()));
	}
}

void Pickable::SetPlayerPosition(sf::Vector2f * playerPosition)
{
	this->playerPosition = playerPosition;
}

sf::Vector2f * Pickable::GetPlayerPosition()
{
	return this->playerPosition;
}
