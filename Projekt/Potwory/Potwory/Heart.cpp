#include "stdafx.h"
#include "Heart.h"

Heart::Heart():Object(0,0,"Heart")
{
	this->hpToRecover = 0;
}

Heart::Heart(const float & x, const float & y, const sf::Texture & texture):Object(x,y,"Heart",texture)
{
	this->hpToRecover = 50;
}

Heart::Heart(const float & x, const float & y, const unsigned int & hpToRecover, const sf::Texture & texture):Heart(x,y,texture)
{
	this->hpToRecover = hpToRecover;
}

void Heart::SetHpToRecover(unsigned int hp)
{
	this->hpToRecover = hp;
}

void Heart::DoAction(int &hp)
{
	hp += this->hpToRecover;
}

unsigned int Heart::GetHpToRecover()
{
	return this->hpToRecover;
}
