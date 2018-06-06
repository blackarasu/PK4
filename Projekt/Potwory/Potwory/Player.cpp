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
		bool action = this->item->DoAction();
		if (!action)
		{
			delete this->item;
			this->item = nullptr;
		}
		return action;
	}
	return false;
}

void Player::Move(float frameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		MoveLeft(frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MoveDown(frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MoveUp(frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		MoveRight(frameTime);
	}
}
		
