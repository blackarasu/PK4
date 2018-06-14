#pragma once
#include "stdafx.h"
#include "Object.h"
class Wall :public Object
{
public:
//Constructors and destructors
	Wall();
	Wall(const float &x, const float &y, const sf::Texture &texture); //x,y are coordinates from map (not pixel position) / they are calculated to pixelPosition after adding texture
	~Wall()=default;
//methods
	void DoAction(sf::Vector2f &valueToChange, const unsigned int lastMove, float frametime, sf::Vector2f speed) override;
	bool DoAction()override { return false; }  //action for pickable (wearable)
	bool DoAction(int &valueToChange) override { return false; }
private:
};
