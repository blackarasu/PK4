//AI potwora, wyznaczona trasa potwora po ktorej sie porusza domyœlnie
//Pole wizji po którym bêdzie atakowa³
#pragma once
#include"stdafx.h"
#include"Dynamic_Object.h"
#include"Player.h"

const sf::IntRect MONSTER_SPRITES_POSITION[DIRECTIONS][ANIMATION_FRAMES] = {
	sf::IntRect({ 3,1,30,54 }),sf::IntRect({ 52,1,30,54 }),sf::IntRect({ 102,1,30,54 }),
	sf::IntRect({ 1,57,43,54 }),sf::IntRect({ 50,57,43,54 }),sf::IntRect({ 98,57,43,54 }),
	sf::IntRect({ 1,113,43,54 }),sf::IntRect({ 50,113,43,54 }),sf::IntRect({ 98,113,43,54 }),
	sf::IntRect({ 9,170,30,54 }),sf::IntRect({ 54,170,30,54 }),sf::IntRect({ 102,170,30,54 })
};

class Monster:public Dynamic
{
public:
//Constructors destructors
	Monster();
	Monster(const float &x, const float &y, const sf::Texture &texture, const int &hp, const sf::Vector2f &speed, const float &damage, const float attackSpeed);
	~Monster();
//setters
	void SetDamage(const float &damage);
	void SetRange(const float &range);
	void SetAttackSpeed(const float &attackSpeed);
//getters
protected:
	float GetDamage();
	float *GetAddressDamage();//good for referance argument
	float GetRange();
	float *GetAddressRange();//good for referance argument
	float GetAttackSpeed();
	float *GetAddressAttackSpeed();//good for referance argument
//methods

	virtual sf::FloatRect Attack() override;
	bool DoAction()override { return false; }//action for pickable (wearable)
	void DoAction(sf::Vector2f &valueToChange, const unsigned int lastAction, float frametime, sf::Vector2f speed)override {}
	bool DoAction(int &hp) override { return false; }
protected:
	void Move(const float &frametime,const unsigned int move);
//virtual
	virtual void SetSprites(const sf::Texture &texture)override;
public:
	virtual void Decide(std::shared_ptr<Player> player,const std::vector<Object*> &objects,const float &frametime); //Monster AI
private:
//Fields
	sf::Clock clock;
	float damage;//monster's damage
	float range; //monster's range
	float attackSpeed;//how many attacks per second
};
