//Objekty typu bro�, oraz takie, kt�ra mo�na podnie�� i korzysta�
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

