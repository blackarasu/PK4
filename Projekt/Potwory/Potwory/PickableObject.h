//Objekty typu bro�, oraz takie, kt�ra mo�na podnie�� i korzysta�
#pragma once
#include "stdafx.h"
#include "Object.h"

class Pickable :public Object
{
public:
//constructors and destructors
	Pickable();
	~Pickable();
//methods
	void DrawPickableObject(sf::RenderWindow *window);
//setters
	void SetPlayerPosition(sf::Vector2f *playerPosition);
//getters 
	sf::Vector2f *GetPlayerPosition();
private:
	bool isPicked;
	sf::Vector2f *playerPosition;
};

