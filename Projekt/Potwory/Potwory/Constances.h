#pragma once
#include"stdafx.h"
//files
enum files { HEART, BLACKHEART, SWORD, CHARACTER, MONSTER, WALL };
const std::vector<std::string> fileLocations = {
	"..//sprites//heart.png",
	"..//sprites//blackheart.png",
	"..//sprites//sword.png", 
	"..//sprites//character.png",
	"..//sprites//monster.png", 
	"..//sprites//wall.png"};
//FONTS
enum Fonts { COURIER_NEW };
const std::vector<std::string> FONTS = { "..//Fonts//cour.ttf" };
//Window
const sf::VideoMode DEFAULT_SIZE_VIDEO = { 1024,768 };
//others
enum Direction:unsigned int{ RIGHT, DOWN, UP, LEFT, DIRECTION_LENGTH };
const int OPPOSITE = -1;
const int DEAD = 0; //no HP
const unsigned int NO_SIZE = 0;
const unsigned int BLANK_LINE = 1;
const float HALF = 0.5f;
//Initial constances
const int INITIAL = 1;
//Sword
const float INITIAL_SWORD_DMG = 13.f;
const float SWORD_DMG_RATIO = 0.3f;
const float INITIAL_SWORD_END = 10.f;
const float SWORD_END_RATIO = 0.1f;
const float INITIAL_SWORD_AS = 1.f;
const float SWORD_AS_RATIO = 0.1f;
//Character
const int INITIAL_PLAYER_HP = 100;
const sf::Vector2f INITIAL_PLAYER_SPEED{ 125.f, 125.f };
const float PLAYER_SPEED_RATIO = 0.52f;
const sf::Vector2f MAX_PLAYER_SPEED{ 450.f,450.f };
//Heart
const unsigned int INITIAL_HEART_HP_RECOVERY = 10;
const unsigned int HEART_HP_REVOVERY_RATIO = 5;
//Monster
const sf::Vector2f INITIAL_MONSTER_SPEED{ 75.f, 75.f };
const float INITIAL_MONSTER_DMG = 15.f;
const float MONSTER_DMG_RATIO = 0.35f;
const float INITIAL_MONSTER_AS = 0.652f;
const float MONSTER_AS_RATIO = 0.13f;
const int INITIAL_MONSTER_HP = 50;
const float MONSTER_HP_RATIO = 0.1f;
//text
const char BACKSPACE = '\b';
//MonsterType
enum Monsters: unsigned int{NORMAL=1};