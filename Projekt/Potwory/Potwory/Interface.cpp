#include "stdafx.h"
#include "Interface.h"

GUI::GUI()
{
	LoadFont(FONTS[Fonts::COURIER_NEW]);
}

GUI::GUI(sf::RenderWindow * window, std::shared_ptr<Player> player, std::shared_ptr<Score> score):GUI()
{
	this->window = window;
	this->player = player;
	this->score = score;
	PrepareLine();
	SetPositions();
}

GUI::~GUI()
{
	this->window = nullptr;
}

sf::Font GUI::GetFont()
{
	return this->font;
}

void GUI::setPlayer(std::shared_ptr<Player> player)
{
	this->player = player;
}

void GUI::LoadFont(const std::string & fileName)
{
	if (!font.loadFromFile(fileName))
	{
		std::string exception = "Font " + fileName + " could NOT be loaded!";
		throw exception;
	}
	else
	{
		std::cout << "Font " << fileName << " has been loaded successfully" << std::endl;
		SetFontToInformations();
	}
}

void GUI::ResetPlayerPointer()
{
	this->player.reset();
}

void GUI::DrawInterface()
{
	PrepareHP();
	PrepareScore();
	PrepareWeapon();
	window->draw(line);
	window->draw(informations[Texts::HP]);
	window->draw(informations[Texts::WEAPON]);
	window->draw(informations[Texts::SCORE]);
}

void GUI::SetFontToInformations()
{
	for (auto i = 0; i < Texts::TEXTS_LENGTH; ++i)
	{
		this->informations[i].setFont(this->font);
	}
}

void GUI::SetPositions()
{
	sf::Vector2u windowSize = this->window->getSize();
	for (auto i = 0; i < Texts::TEXTS_LENGTH; ++i)
	{
		informations[i].setPosition(POSITIONS_PERCENT[i][Position::X] * windowSize.x, POSITIONS_PERCENT[i][Position::Y] * windowSize.y);
		informations[i].setCharacterSize(24);
	}
}

void GUI::PrepareHP()
{
	if (this->player != nullptr)
	{
		informations[Texts::HP].setString(CONST_INFORMATION[Texts::HP] + std::to_string(this->player->GetHP()));
	}
}

void GUI::PrepareScore()
{
	informations[Texts::SCORE].setString(CONST_INFORMATION[Texts::SCORE] + score->PrintScore());
}

void GUI::PrepareWeapon()
{
	if (player != nullptr)
	{
		if (player->GetItem() == nullptr)
		{
			informations[Texts::WEAPON].setString(CONST_INFORMATION[Texts::WEAPON] + "NONE");
		}
		else
		{
			informations[Texts::WEAPON].setString(CONST_INFORMATION[Texts::WEAPON] + player->GetItem()->GetID() + " " + std::to_string(int(player->GetItem()->GetEndurance())));
		}
	}
}

void GUI::PrepareLine()
{
	this->line.setPosition(LINE_POSITION.x, LINE_POSITION.y*this->window->getSize().y);
	this->line.setFillColor(sf::Color(128,128,128));
	this->line.setSize(sf::Vector2f((float)this->window->getSize().x, 5));
}


