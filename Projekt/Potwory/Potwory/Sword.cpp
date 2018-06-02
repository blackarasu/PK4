#include "stdafx.h"
#include "Sword.h"

Sword::Sword():Pickable(0,0,"Sword")
{
	this->damage = 10.2f;
	this->endurance = 5.0f;
	this->attackSpeed = 1.0f;
}

Sword::Sword(const float & x, const float & y, const sf::Texture & texture) :Pickable(x, y, "Sword", texture)
{
	this->damage = 10.0f;
	this->endurance = 5.0f;
	this->attackSpeed = 1.0f;
}

Sword::Sword(const float & x, const float & y, const sf::Texture & texture, const float & damage, const float & endurance, const float & attackSpeed) : Pickable(x, y, "Sword", texture)
{
	this->damage = damage;
	this->endurance = endurance;
	this->attackSpeed = attackSpeed;
}

Sword::Sword(const sf::Texture & texture, sf::Vector2f * pickedPosition, const float & damage, const float & endurance, const float & attackSpeed) :Pickable("Sword", texture, pickedPosition)
{
	this->damage = damage;
	this->endurance = endurance;
	this->attackSpeed = attackSpeed;
}

Sword::~Sword()
{
}
