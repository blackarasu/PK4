#include "stdafx.h"
#include "Player.h"

Player::Player():Dynamic()
{
}

Player::Player(const float & x, const float & y, const sf::Texture & texture, const int & hp, const sf::Vector2f & speed/*, sf::Event * event*/) : Dynamic(x, y, "Player", texture, hp, speed)
{
	//this->event = event;
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

void Player::Move(float frameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		MoveLeft(frameTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MoveDown(frameTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MoveUp(frameTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MoveRight(frameTime);
	}
	else
	{
		NoMove();
	}
}
		
