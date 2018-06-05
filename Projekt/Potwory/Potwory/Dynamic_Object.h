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
	sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),
	sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),
	sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),
	sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 }),sf::IntRect({ 0,0,16,16 })
};//fill when sprites will be ready

class Dynamic:public Object
{
public:
//constructors destructors
	Dynamic();
	Dynamic(const float &x, const float &y, const std::string &ID, const sf::Texture &texture);
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
private:
	int hp; 
	sf::Vector2f speed; //how many pixels u can go through one second
	Pickable *item; //address to picked item if you picked one
	sf::Sprite sprites[DIRECTIONS][ANIMATION_FRAMES];
	unsigned int lastMove;
	unsigned int frame;
};

template<class T>
inline void Dynamic::Pick(T * item)
{
	this->item = item;
}
