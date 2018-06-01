#include "stdafx.h"
#include "Wall.h"

Wall::Wall() :Object(0,0,"Wall")
{
}

Wall::Wall(const float & x, const float & y, const sf::Texture & texture) : Object(x, y, "Wall", texture)
{
}

Wall::~Wall()
{
}

void Wall::DoAction(sf::Vector2f & valueToChange, const int & lastAction)
{
	switch (lastAction)
	{
	case UP:
		valueToChange.y -= 1.0f;
		break;
	case LEFT:
		valueToChange.x -= 1.0f;
		break;
	case DOWN:
		valueToChange.y += 1.0f;
		break;
	case RIGHT:
		valueToChange.x += 1.0f;
		break;
	}
}
