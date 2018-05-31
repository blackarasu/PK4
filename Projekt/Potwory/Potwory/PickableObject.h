//Objekty typu broñ, oraz takie, która mo¿na podnieœæ i korzystaæ
#pragma once
#include "stdafx.h"
#include "Object.h"

const sf::IntRect NOT_PICKED_RECT = { 0,0,16,16 };
const sf::IntRect PICKED_RECT = { 17,0,16,16 };
class Pickable :public Object
{
public:
//constructors and destructors
	Pickable();
	~Pickable();

//setters
	void SetPlayerPosition(sf::Vector2f *playerPosition); //set address to playerPosition
	void SetSprites(const sf::Texture &texture) override; //overrided method for SetSprites. It sets two sprites for NOT_PICKED and PICKED version;
//getters 
	sf::Vector2f *GetPlayerPosition();
//methods
	void DrawPickableObject(sf::RenderWindow *window, sf::IntRect &sizeOfPicker); //different function for drawing PICKED and NOT_PICKED object
	void PickedMe(sf::Vector2f *playerPositon); //Someone picked Pickable Object
private:
	enum Picked{NOT_PICKED, PICKED};
	bool isPicked;
	sf::Vector2f *playerPosition;
	std::vector<sf::Sprite> sprites;
};

