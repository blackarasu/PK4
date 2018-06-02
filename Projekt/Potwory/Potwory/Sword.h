#pragma once
#include "stdafx.h"
#include "PickableObject.h"
class Sword :public Pickable
{
public:
//constructors and destructors
	Sword();
	Sword(const float &x, const float &y, const sf::Texture &texture);
	Sword(const float &x, const float &y, const sf::Texture &texture, const float &damage, const float &endurance, const float &attackSpeed, const float &range);
	Sword(const sf::Texture &texture, sf::Vector2f *pickedPosition, const float &damage, const float &endurance, const float &attackSpeed, const float &range);
	~Sword();
//setters
	void SetDamage(const float &damage);
	void SetEnduramce(const float &endurance);
	void SetAttackSpeed(const float &attackSpeed);
	void SetRange(const float &range);
	void SetAttributes(const float &damage, const float &endurance, const float &attackSpeed, const float &range);
//getters
	float GetDamage();//dmg dealt every attack
	float GetAttackSpeed();//how many times per second you can use attack
	float GetRange();//Range in pixels
//methods
	bool DoAction() override;
private:
	float damage; //dmg dealt in every attack
	float endurance;//how much attacks to destroy (even not hit)
	float attackSpeed; //how fast you can attack with that Sword (How many times per second you can use attack)
	float range; //range in pixels;
};
