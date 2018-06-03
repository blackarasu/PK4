#include "stdafx.h"
#include "PickableObject.h"

Pickable::Pickable():Object(0,0,"I'm nothing")
{
	this->isPicked = false;
	this->picker = nullptr;
}

Pickable::Pickable(const float & x, const float & y, const std::string ID):Object(x,y,ID)
{
	this->isPicked = false;
	this->picker = nullptr;
}

Pickable::Pickable(const std::string ID, Object *picker):Object(ID)
{
	PickedMe(picker);
}

Pickable::Pickable(const float & x, const float & y, const std::string ID, const sf::Texture & texture):Object(x,y,ID)
{
	SetSprites(texture);
	FixPosition();
	this->isPicked = false;
	this->picker = nullptr;
}

Pickable::Pickable(const std::string ID, const sf::Texture & texture, Object *picker):Object(ID,texture)
{
	PickedMe(picker);
}

Pickable::~Pickable()
{
	if (this->picker != nullptr)
	{
		delete this->picker;
	}
}

void Pickable::SetPlayerPosition(Object * playerPosition)
{
	this->picker = playerPosition;
}

void Pickable::SetSprites(const sf::Texture & texture)
{
	this->sprites.push_back(sf::Sprite(texture, NOT_PICKED_RECT));
	this->sprites.push_back(sf::Sprite(texture, PICKED_RECT));
	this->sprites[PICKED].scale(0.25f, 0.25f);//need to test it 
	this->SetActualSprite(&(this->sprites[NOT_PICKED]));
}

sf::Vector2f * Pickable::GetPlayerPosition()
{
	return this->picker->GetAddressPixelsPosition();
}

bool Pickable::IsPicked()
{
	return this->isPicked;
}

void Pickable::DrawPickableObject(sf::RenderWindow * window)
{
	if (this->isPicked == false)
	{
		DrawToWindow(window, this->GetAddressPixelsPosition());
	}
	else
	{
		if (picker != nullptr) //check it 
		{
			sf::Vector2f fixedPosition = this->picker->GetPixelsPosition();
			sf::Sprite *sprite = this->picker->GetActualSpriteAddress();
			sf::IntRect sizeOfPicker = sprite->getTextureRect();
			fixedPosition.x += sizeOfPicker.width * 0.5f;//center of picker
			fixedPosition.y += sizeOfPicker.height * 0.5f;//center of picker
			DrawToWindow(window, &fixedPosition);
		}
	}
}

void Pickable::PickedMe(Object *picker)
{
	this->isPicked = true;
	this->SetActualSprite(&(this->sprites[PICKED]));
	this->picker = picker;
}