#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
	damage = 10.f;
	range = 8.f;
	attackSpeed = 0.5f;
}

Monster::Monster(const float & x, const float & y, const sf::Texture & texture, const int & hp, const sf::Vector2f & speed, const float & damage, const float attackSpeed):Dynamic(x,y,"Monster",hp,speed)
{
	this->damage = damage;
	this->attackSpeed = attackSpeed;
	SetSprites(texture);
	FixPosition();
	this->range = GetActualSpriteAddress()->getGlobalBounds().width;
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
		//switch (GetLastMove())
		//{
		//case Direction::LEFT:
		//	attackRectangle.left -= attackRectangle.width;
		//	break;
		//case Direction::DOWN:
		//	attackRectangle.top += attackRectangle.height;
		//	break;
		//case Direction::UP:
		//	attackRectangle.top -= attackRectangle.height;
		//	break;
		//case Direction::RIGHT:
		//	attackRectangle.left += attackRectangle.width;
		//	break;
		//}
		attackRectangle.height = 3 * this->range;//only for now
		attackRectangle.width = 3 * this->range; //only for now
		attackRectangle.top -= this->range;		 //only for now
		attackRectangle.left -= this->range;	 //only for now
		this->clock.restart();
		return attackRectangle;
	}
	return attackRectangle; //else
}

void Monster::Move(const float &frametime, unsigned int move)
{
	switch (move)
	{
	case Direction::RIGHT:
		MoveRight(frametime);
		break;
	case Direction::DOWN:
		MoveDown(frametime);
		break;
	case Direction::UP:
		MoveUp(frametime);
		break;
	case Direction::LEFT:
		MoveLeft(frametime);
		break;
	}
}

void Monster::SetSprites(const sf::Texture & texture)
{
	for (auto i = 0; i < DIRECTIONS; ++i)
	{
		for (auto j = 0; j < ANIMATION_FRAMES; ++j)
		{
			this->sprites[i][j] = sf::Sprite(texture, MONSTER_SPRITES_POSITION[i][j]);
			this->sprites[i][j].setScale(((float)PIXELS_TO_GET/MONSTER_SPRITES_POSITION[i][j].width),((float)PIXELS_TO_GET/MONSTER_SPRITES_POSITION[i][j].height));
		}
	}
	SetActualSprite(&(this->sprites[Direction::DOWN][Frame::STOP]));
}

void Monster::Decide(std::shared_ptr<Player> player, const std::vector<Object*>& objects, const float & frametime)
{
	sf::FloatRect attackRange = this->Attack();
	if (player->GetActualSpriteAddress()->getGlobalBounds().intersects(attackRange))
	{
		player->TakeDamage(this->damage);
	}
	unsigned int lastMove = this->GetLastMove();
	unsigned int newMove;
	Move(frametime, lastMove);
	sf::Vector2f actualPosition = this->GetPixelsPosition();
	sf::FloatRect monsterRectangle = this->GetActualSpriteAddress()->getGlobalBounds();
	monsterRectangle.top = actualPosition.y;
	monsterRectangle.left = actualPosition.x;
	--monsterRectangle.width;
	--monsterRectangle.height;
	bool isIntersected = false;
	for (auto i = 0; i < objects.size(); ++i)
	{
		if (objects[i]->GetActualSpriteAddress()->getGlobalBounds().intersects(monsterRectangle))
		{
			if (objects[i]->GetID() == "Wall")
			{
				isIntersected = true;
				switch (lastMove)
				{
				case Direction::RIGHT:
					MoveLeft(frametime);
					break;
				case Direction::DOWN:
					MoveUp(frametime);
					break;
				case Direction::UP:
					MoveDown(frametime);
					break;
				case Direction::LEFT:
					MoveRight(frametime);
					break;
				}
				break;
			}
		}
	}
	if (isIntersected)
	{
		do 
		{
			newMove = rand() % Direction::DIRECTION_LENGTH;
		} while (newMove == lastMove);
		Move(frametime, newMove);
	}
}


