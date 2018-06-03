//Objekty typu broñ, oraz takie, która mo¿na podnieœæ i korzystaæ
#pragma once
#include "stdafx.h"
#include "Object.h"

//Change when create texture for weapons (2 views)
const sf::IntRect NOT_PICKED_RECT = { 0,0,16,16 }; //Left/Top /width/height in pixels
const sf::IntRect PICKED_RECT = { 17,0,16,16 }; //Left/Top /width/height in pixels

class Pickable :public Object
{
public:
//constructors and destructors
	Pickable();
	Pickable(const float &x, const float &y, const std::string ID);
	Pickable(const std::string ID, Object *picker);
	Pickable(const float &x, const float &y, const std::string ID, const sf::Texture &texture);
	Pickable(const std::string ID, const sf::Texture &texture, Object *picker);
	~Pickable();
//setters
	void SetPlayerPosition(Object *playerPosition); //set address to playerPosition
	void SetSprites(const sf::Texture &texture) override; //overrided method for SetSprites. It sets two sprites for NOT_PICKED and PICKED version;
//getters 
	sf::Vector2f *GetPlayerPosition();
	bool IsPicked();
//methods
	void DrawPickableObject(sf::RenderWindow *window); //different function for drawing PICKED and NOT_PICKED object
	void PickedMe(Object *playerPositon); //Someone picked Pickable Object
protected:
	enum Picked { NOT_PICKED, PICKED };
	bool isPicked;
private:
	Object * picker; // change to DynamicObject *dynamicObject when is written
	std::vector<sf::Sprite> sprites;
};

