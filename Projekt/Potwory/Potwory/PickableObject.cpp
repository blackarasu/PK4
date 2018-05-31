#include "stdafx.h"
#include "PickableObject.h"

Pickable::Pickable()
{
	this->isPicked = false;
	this->PlayerPosition = nullptr;
}

Pickable::~Pickable()
{
	if (this->PlayerPosition != nullptr)
	{
		delete this->PlayerPosition;
	}
}
