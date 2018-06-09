#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
	damage = 10.f;
	range = 8.f;
	attackSpeed = 0.5f;
}

Monster::~Monster()
{
}

void Monster::SetDamage(const float & damage)
{
	this->damage = damage;
}

void Monster::SetRange(const float & range)
{
	this->range = range;
}

void Monster::SetAttackSpeed(const float & attackSpeed)
{
	this->attackSpeed = attackSpeed;
}

float Monster::GetDamage()
{
	return this->damage;
}

float * Monster::GetAddressDamage()
{
	return &(this->damage);
}

float Monster::GetRange()
{
	return this->range;
}

float * Monster::GetAddressRange()
{
	return &(this->range);
}

float Monster::GetAttackSpeed()
{
	return this->attackSpeed;
}

float * Monster::GetAddressAttackSpeed()
{
	return &(this->attackSpeed);
}

sf::FloatRect Monster::Attack()//atakowanie troche podobne do playerAttack
{
	sf::FloatRect attackRectangle;
	if (this->clock.getElapsedTime().asSeconds() > (1 / this->attackSpeed))
	{
		attackRectangle = this->GetActualSpriteAddress()->getGlobalBounds();
		switch (GetLastMove())
		{
		case Direction::LEFT:
			attackRectangle.left -= attackRectangle.width;
			break;
		case Direction::DOWN:
			attackRectangle.top += attackRectangle.height;
			break;
		case Direction::UP:
			attackRectangle.top -= attackRectangle.height;
			break;
		case Direction::RIGHT:
			attackRectangle.left += attackRectangle.width;
			break;
		}
		attackRectangle.height = this->range;
		attackRectangle.width = this->range;
		this->clock.restart();
		return attackRectangle;
	}
	return attackRectangle; //else
}

void Monster::Decide()
{//AI action
}
