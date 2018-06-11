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
}

void Board::GenerateLevel(std::shared_ptr<Player>& player, std::vector<Object*>& objects, std::vector<Pickable*>& pickableObjects, std::vector<Monster*>& monsters)
{
	if (this->maps.size() <= NO_SIZE+BLANK_LINE)
	{
		std::string exception = "There is no loaded maps my Lord!";
		throw exception;
	}
	else
	{
		Wall* new_wall = nullptr;
		Heart* new_heart = nullptr;
		Sword* new_sword = nullptr;
		float x, y, attackSpeed, endurance, dmg;
		unsigned int hpRecovery;
		unsigned int chosenMap = rand() % (this->maps.size()-1);//which map will be played
		for (auto i = 0; i < this->maps[chosenMap].size(); ++i)
		{
			for (auto j = 0; j < this->maps[chosenMap][i].size(); ++i)//i=y j=x
			{
				x = float(j);
				y = float(i);
				switch (maps[chosenMap][i][j])
				{
				case 'P'://player
					if (player != nullptr)
					{
						player->NoMove();
						sf::FloatRect playerSize = player->GetActualSpriteAddress()->getGlobalBounds();
						player->SetPositionToActualSprite(x*playerSize.width, y*playerSize.height);
						sf::Vector2f playerSpeed = float(PLAYER_SPEED_RATIO*this->level)<INITIAL ? INITIAL_PLAYER_SPEED : INITIAL_PLAYER_SPEED * float(PLAYER_SPEED_RATIO*this->level);
						if (playerSpeed.x > MAX_PLAYER_SPEED.x)
						{
							playerSpeed = MAX_PLAYER_SPEED;
						}
						player->SetSpeed(playerSpeed);
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

std::vector<std::string> Board::LoadMap(const std::string & fileName)
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
		return file;
	}
	else
	{
		return file;
	}
}

void Board::LoadMaps()
{
	std::vector<std::string> tmp;
	unsigned int levelMap = 1;
	do
	{
		tmp = LoadMap(this->FILE_NAME+std::to_string(levelMap) + ".lvl");
		if (tmp.size() > NO_SIZE + BLANK_LINE)
		{
			this->maps.push_back(tmp);
			++levelMap;
		}
		else
		{
			break;
		}
	} while(tmp.size()!=NO_SIZE);
}

