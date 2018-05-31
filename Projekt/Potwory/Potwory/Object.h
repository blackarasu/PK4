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
	void SetActualSprite(sf::Sprite *newSprite); //sets actualSpirte to newSprite
	void SetPositionToActualSprite();//Position x,y in class
	void SetPositionToActualSprite(const float &x, const float &y);//our Position (i.e. Teleport/absolut position)
	virtual sf::Sprite* TextureToSprite(const sf::Texture &texture);//Load texture to vector of sprite;
	virtual void SetSprites(const sf::Texture &texture);
//Getters
	float GetX(); //from pixelsPositon
	float GetY(); //from pixelsPositon
	sf::Vector2f GetMapPosition();
	std::string GetID();
	sf::Sprite* GetActualSpriteAddress();
//Methods
	void DrawToWindow(sf::RenderWindow *window, sf::Vector2f *position); //Draws to window Object
	virtual void DoAction() = 0; //future object's Action/-s
	virtual void DoAction(int &valueToChange)=0; //object's Action/-s operated with referenced value to change'
	virtual void DoAction(int &valueToChange, int lastAction) = 0; //Useful for walls
private:
//Fields
	sf::Vector2f pixelsPositon; 
	std::string ID; //Identificator for Object
	sf::Sprite* actualSprite; 
//Methods
	void SetX(const float &x); //Set pixelsPositon.x
	void SetY(const float &y); //Set pixelsPositon.y
};
