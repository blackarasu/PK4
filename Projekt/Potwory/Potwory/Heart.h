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
	void DoAction(int &hp) override;
private:
	unsigned int hpToRecover;
//getters
	unsigned int GetHpToRecover();
};
