#pragma once
#include "stdafx.h"
#include "Object.h"
class Wall :public Object
{
public:
//Constructors and destructors
	Wall();
	Wall(const float &x, const float &y, const sf::Texture &texture); //x,y are coordinates from map (not pixel position) / they are calculated to pixelPosition after adding texture
	~Wall();
//methods
	void DoAction(sf::Vector2f &valueToChange, const int &lastMove) override;
	bool DoAction()override { return false; }  //action for pickable (wearable)
	void DoAction(int &valueToChange) override {}
private:
};
