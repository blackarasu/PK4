//Dziedziczy po Dynamic_Object
//Poruszanie si� gramczem, 
//inne akcje (strza�/podniesienie przedmiotu[moze auto])
//Posiada Upgrade
#pragma once
#include "stdafx.h"
#include "Dynamic_Object.h"

class Player:public Dynamic
{
public:
//Constructors & Destructors
	Player();
	Player(const float &x, const float &y, const sf::Texture &texture, const int &hp, const sf::Vector2f &speed);
	~Player();
//Methods
	bool DoAction()override;//action for pickable (wearable)
	void DoAction(sf::Vector2f &valueToChange, const int &lastAction)override {}
	void DoAction(int &hp) override {}
private:

};
