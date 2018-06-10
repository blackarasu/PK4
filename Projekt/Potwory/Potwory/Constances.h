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
const unsigned int NO_SIZE = 0;
const float HALF = 0.5f;