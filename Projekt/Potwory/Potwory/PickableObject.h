//Objekty typu broñ, oraz takie, która mo¿na podnieœæ i korzystaæ
#pragma once
#include "stdafx.h"
#include "Object.h"

class Pickable :public Object
{
public:
	Pickable();
	~Pickable();

private:
	bool isPicked;
	sf::Vector2f *PlayerPosition;
};

