//Dziedziczy po Object
//Miecz, zasieg ataku, wytrzyma³oœæ, obra¿enia, czêstoœæAtaku
#pragma once
#include "stdafx.h"
#include "PickableObject.h"
class Sword :public Pickable
{
public:
//constructors and destructors
	Sword();
	Sword(const float &x, const float &y, const sf::Texture &texture);
	Sword(const float &x, const float &y, const sf::Texture &texture, const float &damage, const float &endurance, const float &attackSpeed, const float &range); //custom sword, use not fixed x,y (they are not pixels on the map but how many "swords" can be placed in this rectangle. For example if x=4 and y=5 and size of SpriteRect is 16x16 it will be placed at xpx=4*16 andd ypx=5*16)
	Sword(const sf::Texture &texture, sf::Vector2f* playerPosition, const float &damage, const float &endurance, const float &attackSpeed, const float &range); //if you want give someone a sword from the begining
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
	void DoAction(sf::Vector2f &valueToChange, const int &lastAction)override {}
	void DoAction(int &hp) override {}
private:
	float damage; //dmg dealt in every attack
	float endurance;//how much attacks to destroy (even not hit)
	float attackSpeed; //how fast you can attack with that Sword (How many times per second you can use attack)
	float range; //range in pixels;
};
