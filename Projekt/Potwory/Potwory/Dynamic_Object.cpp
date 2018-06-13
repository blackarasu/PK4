#include "stdafx.h"
#include "Dynamic_Object.h"

Dynamic::Dynamic():Object(0,0,"I'm nothing")
{
	this->hp = 100;
	this->speed.x = 150.0f;
	this->speed.y = 150.0f;
	this->item = nullptr;
	this->lastMove = Direction::DOWN;
	this->frame = Frame::STOP;
}

Dynamic::Dynamic(const float & x, const float & y, const std::string & ID, const int &hp, const sf::Vector2f &speed) :Object(x, y, ID)
{
	this->hp = hp;
	this->speed = speed;
}

Dynamic::Dynamic(const float & x, const float & y, const std::string & ID, const sf::Texture & texture):Object(x,y,ID)
{
	SetSprites(texture);
	FixPosition();
	this->hp = 100;
	this->speed.x = 150.0f;
	this->speed.y = 150.0f;
	this->item = nullptr;
	this->lastMove = Direction::DOWN;
	this->frame = Frame::STOP;
}

Dynamic::Dynamic(const float &x, const float &y, const std::string &ID, const sf::Texture &texture, const int &hp, const sf::Vector2f &speed) :Dynamic(x, y, ID, texture)
{
	this->hp = hp;
	this->speed = speed;
}

Dynamic::~Dynamic()
{
	if (this->item != nullptr)
	{
		delete this->item;
		this->item = nullptr;
	}
	SetActualSprite(nullptr);
}

void Dynamic::SetSprites(const sf::Texture & texture)
{
	for (auto i = 0; i < DIRECTIONS; ++i)
	{
		for (auto j = 0; j < ANIMATION_FRAMES; ++j)
		{
			this->sprites[i][j] = sf::Sprite(texture, SPRITES_POSITION[i][j]);
			this->sprites[i][j].setScale(((float)PIXELS_TO_GET/SPRITES_POSITION[i][j].width), ((float)PIXELS_TO_GET / SPRITES_POSITION[i][j].height));
		}
	}
	SetActualSprite(&(this->sprites[Direction::DOWN][Frame::STOP]));
}

void Dynamic::SetHP(const int & hp)
{
	this->hp = hp;
}

void Dynamic::SetSpeed(const sf::Vector2f & speed)
{
	this->speed = speed;
}

int Dynamic::GetHP()
{
	return this->hp;
}

int *Dynamic::GetAddressHP()
{
	return &(this->hp);
}

sf::Vector2f Dynamic::GetSpeed()
{
	return this->speed;
}

unsigned int Dynamic::GetLastMove()
{
	return this->lastMove;
}

Pickable * Dynamic::GetItem()
{
	return this->item;
}

void Dynamic::MoveUp(float frameTime)
{
	this->pixelsPositon.y -= frameTime * speed.y;
	if (this->lastMove == Direction::UP)
	{
		this->frame++;
		if (this->frame > Frame::THIRD)
		{
			this->frame = Frame::FIRST;
		}
	}
	else
	{
		this->lastMove = Direction::UP;
		this->frame = Frame::FIRST;
	}
	SetActualSprite(&(this->sprites[this->lastMove][this->frame]));
}

void Dynamic::MoveDown(float frameTime)
{
	this->pixelsPositon.y += frameTime * speed.y;
	if (this->lastMove == Direction::DOWN)
	{
		this->frame++;
		if (this->frame > Frame::THIRD)
		{
			this->frame = Frame::FIRST;
		}
	}
	else
	{
		this->lastMove = Direction::DOWN;
		this->frame = Frame::FIRST;
	}
	SetActualSprite(&(this->sprites[this->lastMove][this->frame]));
}

void Dynamic::MoveLeft(float frameTime)
{
	this->pixelsPositon.x -= frameTime * speed.x;
	if (this->lastMove == Direction::LEFT)
	{
		this->frame++;
		if (this->frame > Frame::THIRD)
		{
			this->frame = Frame::FIRST;
		}
	}
	else
	{
		this->lastMove = Direction::LEFT;
		this->frame = Frame::FIRST;
	}
	SetActualSprite(&(this->sprites[this->lastMove][this->frame]));
}

void Dynamic::MoveRight(float frameTime)
{
	this->pixelsPositon.x += frameTime * speed.x;
	if (this->lastMove == Direction::RIGHT)
	{
		this->frame++;
		if (this->frame > Frame::THIRD)
		{
			this->frame = Frame::FIRST;
		}
	}
	else
	{
		this->lastMove = Direction::RIGHT;
		this->frame = Frame::FIRST;
	}
	SetActualSprite(&(this->sprites[this->lastMove][this->frame]));
}

void Dynamic::NoMove()
{
	if (this->frame == Frame::FIRST)
	{
		++this->frame;
	}
	SetActualSprite(&(this->sprites[this->lastMove][Frame::STOP]));
}

void Dynamic::DoDamage(const float & damage)
{
	this->hp -= int(ceil(damage));
}
