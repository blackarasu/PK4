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
	this->sprites[Picked::PICKED].scale(0.25f, 0.5f);//need to test it 
	this->sprites[Picked::PICKED].setColor(sf::Color::Yellow);
	this->sprites.push_back(sf::Sprite(texture, REVERSE_RECT));
	this->sprites[Picked::REVERSE].scale(0.25f, 0.5f);//need to test it 
	this->sprites[Picked::REVERSE].setColor(sf::Color::Yellow);
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

void Pickable::DrawPickableObject(sf::RenderWindow * window,const sf::FloatRect &sizeOfPicker,const unsigned int lastMove)
{
	if (playerPosition != nullptr) //check it 
	{
		sf::Vector2f fixedPosition = *(this->playerPosition);
		fixedPosition.x += sizeOfPicker.width * 0.80f;
		fixedPosition.y += sizeOfPicker.height * 0.15f;
		if (lastMove == Direction::LEFT)
		{
			SetActualSprite(&(this->sprites[Picked::REVERSE]));
			fixedPosition.x -= sizeOfPicker.width * 0.3f;
			fixedPosition.y += sizeOfPicker.height * 0.05f;
		}
		else
		{
			SetActualSprite(&(this->sprites[Picked::PICKED]));
		}
		DrawToWindow(window, &(fixedPosition));
	}
}

void Pickable::PickedMe(sf::Vector2f *playerPosition)
{
	this->isPicked = true;
	this->SetActualSprite(&(this->sprites[Picked::PICKED]));
	this->playerPosition = playerPosition;
}