#pragma once
#include "stdafx.h"
#include "PickableObject.h"
class Sword :public Pickable
{
public:
//constructors and destructors
	Sword();
	Sword(const float &x, const float &y, const sf::Texture &texture);
	Sword(const float &x, const float &y, const sf::Texture &texture, const float &damage, const float &endurance, const float &attackSpeed);
	Sword(const sf::Texture &texture, sf::Vector2f *pickedPosition, const float &damage, const float &endurance, const float &attackSpeed);
	~Sword();
//setters
//getters
private:
	float damage; //dmg dealt in every attack
	float endurance;//how much attacks to destroy (even not hit)
	float attackSpeed; //how fast you can attack with that Sword (How many times per second you can use attack)
};
