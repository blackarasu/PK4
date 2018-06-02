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
	Object(const float &x, const float &y); //x,y are coordinates from map (not pixel position)/ if you want set pixel position use constructor with 4 parameters
	Object(const float &x, const float &y, const std::string &ID);
	Object(const float &x, const float &y, const std::string &ID, const sf::Texture &texture);
	Object(const std::string &ID, const sf::Texture &texture);
	Object(const std::string &ID);
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
	sf::Vector2f GetPixelsPosition(); //Get values of pixelsPosition
	sf::Vector2f* GetAddressPixelsPosition(); //Get address to pixelsPosition
	std::string GetID();
	sf::Sprite* GetActualSpriteAddress();
//Methods
	void DrawToWindow(sf::RenderWindow *window, sf::Vector2f *position); //Draws to window Object
	virtual bool DoAction() = 0; //good for weapon Action
	virtual void DoAction(int &valueToChange) = 0; //object's Action/-s operated with referenced value to change' ie. Heart
	virtual void DoAction(sf::Vector2f &valueToChange, const int &lastAction) = 0; //Useful for walls
protected:
	inline void FixPosition();
private:
//Fields
	sf::Vector2f pixelsPositon; 
	std::string ID; //Identificator for Object
	sf::Sprite* actualSprite; 
//Methods
	void SetX(const float &x); //Set pixelsPositon.x
	void SetY(const float &y); //Set pixelsPositon.y
};

