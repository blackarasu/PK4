#pragma once
#include "stdafx.h"
#include"Constances.h"
#include "Player.h"
#include "Score.h"
#include "Monster.h"
enum Texts{HP, WEAPON, SCORE, TEXTS_LENGTH};//add LEVEL later
const std::string CONST_INFORMATION[Texts::TEXTS_LENGTH] = { "HP: ","WEAPON: ","SCORE: " };
enum Position{X,Y};
const float POSITIONS_PERCENT[][2] = { {0.008f,0.94f},{0.2f,0.94f },{0.5f,0.94f} };
const sf::Vector2f LINE_POSITION = { 0.f,0.92f };
class GUI
{
public:
//constructors / destructors
	GUI();
	GUI(sf::RenderWindow *window, std::shared_ptr<Player> player, std::shared_ptr<Score> score);
	~GUI();
//getters
	sf::Font GetFont();
//setters
	void setPlayer(std::shared_ptr<Player> player);
//methods
	void LoadFont(const std::string &fileName);
	void ResetPlayerPointer();
	void DrawInterface();
private:
//fields
	sf::RectangleShape line;
	sf::Font font;
	sf::Text informations[Texts::TEXTS_LENGTH];
	sf::RenderWindow *window;
	std::shared_ptr<Player> player;
	std::shared_ptr<Score> score; 
	//std::vector<Monster*>* monsters
//methods
	void SetFontToInformations();
	void SetPositions();
	void PrepareHP();
	void PrepareScore();
	void PrepareWeapon();
	void PrepareLine();
	//void PrepareLastHitMonster(); add later
};
