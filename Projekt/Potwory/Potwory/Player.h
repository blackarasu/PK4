//Dziedziczy po Dynamic_Object
//Poruszanie siê gramczem, 
//inne akcje (strza³/podniesienie przedmiotu[moze auto])
//Posiada Upgrade
#pragma once
#include "stdafx.h"
#include "Dynamic_Object.h"

class Player:public Dynamic
{
public:
//Constructors & Destructors
	Player();
	Player(const float &x, const float &y, const sf::Texture &texture, const int &hp, const sf::Vector2f &speed/*, sf::Event *event*/);
	~Player();
//Methods
	bool DoAction()override;//action for pickable (wearable)
	void DoAction(sf::Vector2f &valueToChange, const int &lastAction)override {}
	bool DoAction(int &hp) override { return false; }
	void Move(float frameTime);//move one of 4 to 8 directions
private:
	//sf::Event *event;
};
