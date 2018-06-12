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

void Wall::DoAction(sf::Vector2f & valueToChange, const unsigned int lastMove, float frametime, sf::Vector2f speed)
{
	switch (lastMove)
	{
	case UP:
		valueToChange.y += frametime * speed.y;
		break;
	case LEFT:
		valueToChange.x += frametime * speed.x;
		break;
	case DOWN:
		valueToChange.y -= frametime * speed.y;
		break;
	case RIGHT:
		valueToChange.x -= frametime * speed.x;
		break;
	default:
		break;
	}
}
