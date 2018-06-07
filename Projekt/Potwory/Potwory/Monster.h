//AI potwora, wyznaczona trasa potwora po ktorej sie porusza domyœlnie
//Pole wizji po którym bêdzie atakowa³
#pragma once
#include"stdafx.h"
#include"Dynamic_Object.h"

class Monster:public Dynamic
{
public:
//Constructors destructors
	Monster();
	~Monster();
//setters
	void SetDamage(const float &damage);
	void SetRange(const float &range);
	void SetAttackSpeed(const float &attackSpeed);
//getters
	float GetDamage();
	float *GetAddressDamage();//good for referance argument
	float GetRange();
	float *GetAddressRange();//good for referance argument
	float GetAttackSpeed();
	float *GetAddressAttackSpeed();//good for referance argument
//methods
	virtual sf::FloatRect Attack() override;
//virtual
	virtual void Decide(); //Monster AI
private:
//Fields
	sf::Clock clock;
	float damage;//monster's damage
	float range; //monster's range
	float attackSpeed;//how many attacks per second
};
