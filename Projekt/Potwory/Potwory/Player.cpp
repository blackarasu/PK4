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
		return action;
	}
	return false;
}

void Player::Move(float frameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		MoveLeft(frameTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		MoveDown(frameTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		MoveUp(frameTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		MoveRight(frameTime);
	}
	else
	{
		NoMove();
	}
}

sf::FloatRect Player::Attack()
{
	sf::FloatRect attackRectangle;
	if (this->DoAction())
	{//Attack
		float range = this->GetItem()->GetRange();
		float damage = this->GetItem()->GetDamage();
		sf::Vector2f playerPosition = this->GetPixelsPosition();
		attackRectangle = (this->GetActualSpriteAddress()->getGlobalBounds());
		switch (this->GetLastMove())
		{
		case Direction::RIGHT:
			attackRectangle.left = playerPosition.x + attackRectangle.width;
			break;
		case Direction::UP:
			attackRectangle.top = playerPosition.y - attackRectangle.height;
			break;
		case Direction::LEFT:
			attackRectangle.left = playerPosition.x - attackRectangle.width;
			break;
		case Direction::DOWN:
			attackRectangle.top = playerPosition.y + attackRectangle.height;
			break;
		}
		attackRectangle.width = range;
		attackRectangle.height = range;
		return attackRectangle;
	}
	return attackRectangle; //else
}
		
