//Dziedziczy po Object
//Rodzaj serduszka (normalne/czarne), iloœæ przywracanego HP
#pragma once
#include "stdafx.h"
#include "Object.h"
class Heart : public Object
{
public:
//constructors / destructors
	Heart();
	Heart(const float &x, const float &y, const sf::Texture &texture);
	Heart(const float &x, const float &y, const unsigned int &hpToRecover, const sf::Texture &texture);
	~Heart()=default;
//setters
	void SetHpToRecover(unsigned int hp);
//methods
	bool DoAction()override { return false; } //action for pickable (wearable)
	void DoAction(sf::Vector2f &valueToChange, const int &lastAction)override {}
	void DoAction(int &hp) override;
//getters
	unsigned int GetHpToRecover();
private:
	unsigned int hpToRecover;
};
