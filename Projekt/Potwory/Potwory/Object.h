//Informacja pozycji na mapie, nazwa obiektu (chyba)
//x,y, textura, sprite
#pragma once
#include "stdafx.h"
#include "Constances.h"
class Object
{
public:
//Constructors/Destructors
	Object();
	~Object();
	Object(const float &x, const float &y);
	Object(const float &x, const float &y, const std::string &ID);
	Object(const float &x, const float &y, const std::string &ID, const sf::Texture &texture);
//Setters
	void SetPosition(const float &x,const float &y);//Set float x, y;
	void SetID(const std::string &ID);//Set Object ID
	void SetPositionToActualSprite();//Position x,y in class
	void SetPositionToActualSprite(const float &x, const float &y);//our Position (i.e. Teleport/absolut position)
	virtual sf::Sprite* TextureToSprite(const sf::Texture &texture);//Load texture to vector of sprite;
	virtual void SetSprites(const sf::Texture &texture);
//Getters
	float GetX(); //from mapPosition
	float GetY(); //from mapPosition
	sf::Vector2f GetMapPosition();
	std::string GetID();
//Methods
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void DrawToWindow(sf::RenderWindow *window, sf::Vector2f *position); //!!!!!!Find other way to DrawToWindow because it is not scallable!!!!!!!!!!!!!!!!!!!!!!!!! //Optimal only for the same size of sprites
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	virtual void DoAction() = 0; //future object's Action/-s
	virtual void DoAction(int &valueToChange)=0; //object's Action/-s operated with referenced value to change
private:
//Fields
	sf::Vector2f mapPosition; 
	std::string ID; //Identificator for Object
	sf::Sprite* actualSprite; 
//Methods
	void SetX(const float &x); //Set mapPosition.x
	void SetY(const float &y); //Set mapPosition.y
};
