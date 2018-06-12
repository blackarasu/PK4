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
	void SetPosition(const sf::Vector2f &pixelsPosition);
	void SetID(const std::string &ID);//Set Object ID
	void SetActualSprite(sf::Sprite *newSprite); //sets actualSpirte to newSprite
	void SetPositionToActualSprite();//Position x,y in class
	void SetPositionToActualSprite(const float &x, const float &y);//our Position (i.e. Teleport/absolut position)
	virtual sf::Sprite* TextureToSprite(const sf::Texture &texture);//Load texture to vector of sprite;
	virtual void SetSprites(const sf::Texture &texture); //virtual setter for setting sprites (base sets actualSprite for texture)
//Getters
	float GetX(); //from pixelsPositon
	float GetY(); //from pixelsPositon
	sf::Vector2f GetPixelsPosition(); //Get values of pixelsPosition
	sf::Vector2f* GetAddressPixelsPosition(); //Get address to pixelsPosition
	std::string GetID(); //object's ID
	sf::Sprite* GetActualSpriteAddress(); //address to ActualSprite
//Methods
	void DrawToWindow(sf::RenderWindow *window, sf::Vector2f *position); //Draws to window Object
//virtual Methods
	virtual bool DoAction() = 0; //good for weapon Action
	virtual bool DoAction(int &valueToChange) = 0; //object's Action/-s operated with referenced value to change' ie. Heart
	virtual void DoAction(sf::Vector2f &valueToChange, const unsigned int lastAction,const float frametime, const sf::Vector2f speed) = 0; //Useful for walls
protected:
//Fields
	sf::Vector2f pixelsPositon; //fixed position
//Methods
	inline void FixPosition(); //fix postion got from map
private:
//Fields
	std::string ID; //Identificator for Object
	sf::Sprite* actualSprite; //used for drawing
//Methods
	void SetX(const float &x); //Set pixelsPositon.x
	void SetY(const float &y); //Set pixelsPositon.y
};

