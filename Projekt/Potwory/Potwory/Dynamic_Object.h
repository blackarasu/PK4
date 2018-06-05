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
const sf::Vector2f SCALE(0.42105263157894736842105263157895f, 0.2962962962962962962962962962963f);
class Dynamic:public Object
{
public:
//constructors destructors
	Dynamic();
	Dynamic(const float &x, const float &y, const std::string &ID, const sf::Texture &texture);
	Dynamic(const float &x, const float &y, const std::string &ID, const sf::Texture &texture, const int &hp, const sf::Vector2f &speed);
	~Dynamic();
//setters
	void SetSprites(const sf::Texture &texture)override;
	void SetHP(const int &hp);
	template <class T>
	void Pick(T* item);//Use only derivatives of the Pickable
//getters
	int GetHP();
	unsigned int GetLastMove();
	Pickable * GetItem();
//methods
	void MoveUp(float frameTime);
	void MoveDown(float frameTime);
	void MoveLeft(float frameTime);
	void MoveRight(float frameTime);
	void NoMove();
protected:
	Pickable * item; //address to picked item if you picked one
private:
	int hp; 
	sf::Vector2f speed; //how many pixels u can go through one second
	sf::Sprite sprites[DIRECTIONS][ANIMATION_FRAMES];
	unsigned int lastMove;
	unsigned int frame;
};

template<class T>
inline void Dynamic::Pick(T * item)
{
	this->item = item;
}
