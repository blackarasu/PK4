#include "stdafx.h"
#include "Sword.h"

Sword::Sword():Pickable(0,0,"Sword")
{
	this->damage = 10.2f;
	this->endurance = 5.0f;
	this->attackSpeed = 1.0f;
	this->range = 4.0f;
}

Sword::Sword(const float & x, const float & y, const sf::Texture & texture) :Pickable(x, y, "Sword", texture)
{
	this->damage = 10.0f;
	this->endurance = 10.0f;
	this->attackSpeed = 1.0f;
	this->range = GetActualSpriteAddress()->getGlobalBounds().width;
}

Sword::Sword(const float & x, const float & y, const sf::Texture & texture, const float & damage, const float & endurance, const float & attackSpeed):Pickable(x,y,"Sword",texture)
{
	this->damage = damage;
	this->endurance = endurance;
	this->attackSpeed = attackSpeed;
	this->range = GetActualSpriteAddress()->getGlobalBounds().width;
}

Sword::Sword(const float & x, const float & y, const sf::Texture & texture, const float & damage, const float & endurance, const float & attackSpeed, const float & range) : Pickable(x, y, "Sword", texture)
{
	this->damage = damage;
	this->endurance = endurance;
	this->attackSpeed = attackSpeed;
	this->range = range;
}

Sword::Sword(const sf::Texture & texture, sf::Vector2f * playerPosition, const float & damage, const float & endurance, const float & attackSpeed, const float & range) :Pickable("Sword", texture, playerPosition)
{
	this->damage = damage;
	this->endurance = endurance;
	this->attackSpeed = attackSpeed;
	this->range = range;
}

Sword::~Sword()
{
}

void Sword::SetDamage(const float & damage)
{
	this->damage = damage;
}

void Sword::SetEnduramce(const float & endurance)
{
	this->endurance = endurance;
}

void Sword::SetAttackSpeed(const float & attackSpeed)
{
	this->attackSpeed = attackSpeed;
}

void Sword::SetRange(const float & range)
{
	this->range = range;
}

void Sword::SetAttributes(const float & damage, const float & endurance, const float & attackSpeed, const float & range)
{
	this->damage = damage;
	this->endurance = endurance;
	this->attackSpeed = attackSpeed;
	this->range = range;
}

float Sword::GetDamage()
{
	return this->damage;
}

float Sword::GetAttackSpeed()
{
	return this->attackSpeed;
}

float Sword::GetRange()
{
	return this->range;
}

float Sword::GetEndurance()
{
	return this->endurance;
}

bool Sword::DoAction()
{
	if (clock.getElapsedTime().asSeconds() > (1 / this->attackSpeed))
	{
		if (this->endurance > 0 && IsPicked())
		{
			//add animation
			this->endurance -= 1.0f;
			clock.restart();
			return true;
		}
		return false;
	}
	else 
	{
		return true;
	}
}


