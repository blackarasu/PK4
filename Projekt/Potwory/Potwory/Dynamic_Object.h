//Dziedziczy po Object
//dodatkowo prêdkoœæ ruchu
//Ró¿ne sprite'y
//Iloœæ zdrowia
#pragma once
#include "stdafx.h"
#include "PickableObject.h"

enum Frame :unsigned int { FIRST, STOP, THIRD };
const unsigned int DIRECTIONS = 4;
const unsigned int ANIMATION_FRAMES = 3;
const sf::IntRect SPRITES_POSITION[DIRECTIONS][ANIMATION_FRAMES] = {
	sf::IntRect({ 5,1,37,54 }),sf::IntRect({ 57,1,28,54 }),sf::IntRect({ 107,1,28,54 }),
	sf::IntRect({ 6,57,39,54 }),sf::IntRect({ 54,57,38,54 }),sf::IntRect({ 102,57,38,54 }),
	sf::IntRect({ 6,113,39,54 }),sf::IntRect({ 54,113,38,54 }),sf::IntRect({ 102,113,38,54 }),
	sf::IntRect({ 9,170,28,54 }),sf::IntRect({ 59,170,28,54 }),sf::IntRect({ 102,170,37,54 })
};
const int PIXELS_TO_GET = 16;
class Dynamic:public Object
{
public:
//constructors destructors
	Dynamic();
	Dynamic(const float & x, const float & y, const std::string & ID, const int &hp, const sf::Vector2f &speed);
	Dynamic(const float &x, const float &y, const std::string &ID, const sf::Texture &texture);
	Dynamic(const float &x, const float &y, const std::string &ID, const sf::Texture &texture, const int &hp, const sf::Vector2f &speed);
	~Dynamic();
//setters
	virtual void SetSprites(const sf::Texture &texture)override; //Set 9 sprites from texture and it makes Rectangle from SPRITES_POSITION
	void SetHP(const int &hp);
	void SetSpeed(const sf::Vector2f &speed);
	template <class T>
	void Pick(T* item);//Use only derivatives of the Pickable
//getters
	int GetHP();
	int *GetAddressHP();
	sf::Vector2f GetSpeed();
	unsigned int GetLastMove();
	Pickable * GetItem();
//methods
	void MoveUp(float frameTime);
	void MoveDown(float frameTime);
	void MoveLeft(float frameTime);
	void MoveRight(float frameTime);
	void NoMove();//Set STOP Sprite
	virtual sf::FloatRect Attack()=0; //function which returns AttackRectangle 
	void TakeDamage(const float &damage);
protected:
	Pickable * item; //address to picked item if you picked one
	sf::Sprite sprites[DIRECTIONS][ANIMATION_FRAMES];//sprites for "animation"
private:
	int hp; 
	sf::Vector2f speed; //how many pixels u can go through one second
	unsigned int lastMove;
	unsigned int frame;//contains wich one of 3 frames must be used as actual sprite
};

template<class T>
inline void Dynamic::Pick(T * item)
{
	this->item = item;
}
