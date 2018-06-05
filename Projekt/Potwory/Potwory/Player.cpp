#include "stdafx.h"
#include "Player.h"

Player::Player():Dynamic()
{
}

Player::Player(const float & x, const float & y, const sf::Texture & texture, const int & hp, const sf::Vector2f & speed) : Dynamic(x, y, "Player", texture, hp, speed)
{
}

Player::~Player()
{
}

bool Player::DoAction()
{
	if (this->item != nullptr)
	{
		return this->item->DoAction();
	}
	return false;
}
