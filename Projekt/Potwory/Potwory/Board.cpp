#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	this->level = 1;
}

Board::Board(const std::vector<sf::Texture*> &textures):Board()
{
	this->textures = textures;
	LoadMaps();
}

Board::~Board()
{
	for (auto i = 0; i < textures.size(); ++i)
	{
		this->textures[i] = nullptr;
	}
	textures.clear();
}

unsigned int Board::GetLevel()
{
	return this->level;
}

unsigned int * Board::GetAdressLevel()
{
	return &(this->level);
}

void Board::ResetLevel()
{
	this->level = 1;
}

void Board::NextLevel(std::shared_ptr<Player> &player, std::vector<Object*> &objects, std::vector<Pickable*> &pickableObjects, std::vector<Monster*> &monsters)
{
	++this->level;
	GenerateLevel(player, objects, pickableObjects, monsters);
}

void Board::GenerateLevel(std::shared_ptr<Player>& player, std::vector<Object*>& objects, std::vector<Pickable*>& pickableObjects, std::vector<Monster*>& monsters)
{
	if (this->maps.size() == NO_SIZE)
	{
		std::string exception = "There is no loaded maps my Lord!";
		throw exception;
	}
	else
	{
		Wall* new_wall = nullptr;
		Heart* new_heart = nullptr;
		Sword* new_sword = nullptr;
		Monster* new_monster = nullptr;
		sf::Vector2f speed;
		float x, y, attackSpeed, endurance, dmg;
		int hp;
		unsigned int hpRecovery;
		unsigned int chosenMap = rand() % (this->maps.size());//which map will be played
		if (chosenMap == this->maps.size())
		{
			--chosenMap;
		}
		for (auto i = 0; i < this->maps[chosenMap].size(); ++i)
		{
			y = float(i);
			for (auto j = 0; j < this->maps[chosenMap][i].size(); ++j)//i=y j=x
			{
				x = float(j);
				switch (maps[chosenMap][i][j])
				{
				case 'P'://player
					if (player != nullptr)
					{
						player->NoMove();
						player->SetPosition(x, y);
						player->FixPosition();
						speed = float(PLAYER_SPEED_RATIO*this->level)<INITIAL ? INITIAL_PLAYER_SPEED : INITIAL_PLAYER_SPEED * float(PLAYER_SPEED_RATIO*this->level);
						if (speed.x > MAX_PLAYER_SPEED.x)
						{
							speed = MAX_PLAYER_SPEED;
						}
						player->SetSpeed(speed);
					}
					else
					{
						player = std::make_shared<Player>(x, y, *textures[CHARACTER], INITIAL_PLAYER_HP, INITIAL_PLAYER_SPEED);
					}
					break;
				case 'W'://Wall
					new_wall = new Wall(x, y, *textures[WALL]);
					objects.push_back(new_wall);
					new_wall = nullptr;
					break;
				case 'M'://Monster
				//add monster here
					hp = int(INITIAL_MONSTER_HP + INITIAL_MONSTER_HP * (int(this->level)*MONSTER_HP_RATIO));
					speed = float(PLAYER_SPEED_RATIO*this->level)<INITIAL ? INITIAL_MONSTER_SPEED : INITIAL_MONSTER_SPEED * float(PLAYER_SPEED_RATIO*this->level);
					if (speed.x > MAX_PLAYER_SPEED.x)
					{
						speed = MAX_PLAYER_SPEED;
					}
					dmg = INITIAL_MONSTER_DMG + INITIAL_MONSTER_DMG * (float(this->level)*MONSTER_DMG_RATIO);
					attackSpeed = INITIAL_MONSTER_AS + INITIAL_MONSTER_AS * (float(this->level)*MONSTER_AS_RATIO);
					new_monster = new Monster(x, y, *textures[MONSTER], hp, speed, dmg, attackSpeed);
					monsters.push_back(new_monster);
					new_monster = nullptr;
					break;
				case 'H'://heart
					hpRecovery = INITIAL_HEART_HP_RECOVERY + this->level * HEART_HP_REVOVERY_RATIO;
					new_heart = new Heart(x, y, hpRecovery, *textures[HEART]);
					objects.push_back(new_heart);
					new_heart = nullptr;
					break;
				case 'S'://sword
					dmg = INITIAL_SWORD_DMG + INITIAL_SWORD_DMG * (this->level*SWORD_DMG_RATIO);
					endurance = INITIAL_SWORD_END + INITIAL_SWORD_END * (this->level*SWORD_END_RATIO);
					attackSpeed = INITIAL_SWORD_AS + INITIAL_SWORD_AS * (this->level*SWORD_AS_RATIO);
					new_sword = new Sword(x, y, *textures[SWORD], dmg, endurance, attackSpeed);
					pickableObjects.push_back(new_sword);
					new_sword = nullptr;
					break;
				default:
					break;
				}
			}
		}
	}
}

void Board::PrepareForNewLevel(std::vector<Object*>& objects, std::vector<Pickable*>& pickableObjects)
{
	for (auto i = 0; i < objects.size(); ++i)
	{
		delete objects[i];
	}
	objects.clear();
	for (auto i = 0; i < pickableObjects.size(); ++i)
	{
		delete pickableObjects[i];
	}
	pickableObjects.clear();
}

void Board::PrepareForNewLevel(std::vector<Object*>& objects, std::vector<Pickable*>& pickableObjects, std::vector<Monster*>& monsters)
{
	PrepareForNewLevel(objects, pickableObjects);
	for (auto i = 0; i < monsters.size(); ++i)
	{
		delete monsters[i];
	}
	monsters.clear();
}

bool Board::LoadMap(const std::string & fileName)
{
	std::ifstream input(fileName.c_str());
	std::vector<std::string> file;
	if (input.is_open())
	{
		while (!input.eof())
		{
			std::string line;
			std::getline(input, line);
			file.push_back(line);
		}
		if (file.size() > NO_SIZE + BLANK_LINE)
		{
			this->maps.push_back(file);
			return true;
		}
	}
	input.close();
	return false;
}

void Board::LoadMaps()
{
	std::vector<std::string> tmp;
	unsigned int levelMap = 1;
	while (LoadMap(this->FILE_NAME + std::to_string(levelMap) + ".lvl"))
	{
		++levelMap;
	}
}

