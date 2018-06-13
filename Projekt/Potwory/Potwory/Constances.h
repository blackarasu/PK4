#pragma once
#include"stdafx.h"

enum files{HEART,BLACKHEART,SWORD,CHARACTER,MONSTER,WALL};
const std::vector<std::string> fileLocations = {
	"..//sprites//heart.png",
	"..//sprites//blackheart.png",
	"..//sprites//sword.png", 
	"..//sprites//character.png",
	"..//sprites//monster.png", 
	"..//sprites//wall.png"};
const sf::VideoMode DEFAULT_SIZE_VIDEO = { 1024,768 };
enum Direction:unsigned int{ RIGHT, DOWN, UP, LEFT };
const int OPPOSITE = -1;
const int DEAD = 0; //no HP
const unsigned int NO_SIZE = 0;
const unsigned int BLANK_LINE = 1;
const float HALF = 0.5f;
const int INITIAL = 1;
const float INITIAL_SWORD_DMG = 10.f;
const float SWORD_DMG_RATIO = 0.3f;
const float INITIAL_SWORD_END = 10.f;
const float SWORD_END_RATIO = 0.1f;
const float INITIAL_SWORD_AS = 1.f;
const float SWORD_AS_RATIO = 0.1f;
const int INITIAL_PLAYER_HP = 100;
const sf::Vector2f INITIAL_PLAYER_SPEED{ 125.f, 125.f };
const float PLAYER_SPEED_RATIO = 0.52f;
const sf::Vector2f MAX_PLAYER_SPEED{ 450.f,450.f };
const unsigned int INITIAL_HEART_HP_RECOVERY = 10;
const unsigned int HEART_HP_REVOVERY_RATIO = 5;
const float INITIAL_MONSTER_DMG = 5.f;
const float MONSTER_DMG_RATIO = 0.35f;
const float INITIAL_MONSTER_AS = 0.5f;
const float MONSTER_AS_RATIO = 0.13f;
const int INITIAL_MONSTER_HP = 50;
const float MONSTER_HP_RATIO = 0.1f;
