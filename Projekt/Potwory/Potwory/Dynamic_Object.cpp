#include "stdafx.h"
#include "Dynamic_Object.h"

Dynamic::Dynamic():Object(0,0,"I'm nothing")
{
	this->hp = 100;
	this->speed.x = 150;
	this->speed.y = 150;
	this->item = nullptr;
}

Dynamic::~Dynamic()
{
	if (this->item != nullptr)
	{
		delete this->item;
	}
}
