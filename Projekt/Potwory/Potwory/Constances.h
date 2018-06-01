#pragma once
#include"stdafx.h"

enum files{HEART,BLACKHEART,SWORD,CHARACTER,MONSTER,WALL};
const std::vector<std::string> fileLocations = {"..//sprites//heart.png","..//sprites//blackheart.png","..//sprites//sword.png", "..//sprites//character.png","..//sprites//monster.png", "..//sprites//wall.png"};
const sf::VideoMode DEFAULT_SIZE_VIDEO = { 1366,768 };
enum Direction{ UP, LEFT, DOWN, RIGHT };