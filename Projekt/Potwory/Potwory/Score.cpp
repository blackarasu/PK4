#include "stdafx.h"
#include <iomanip>
#include "score.h"
#include "Constances.h"

Score::Score()
{
	this->multiplier = 1.0;
	this->actualScore = 0.0;
	this->namePattern=new std::regex(("[A-Za-z]+"));
	FillScoreBoardWith0();
	try 
	{
		GetScoreBoardFromFile();
	}
	catch (std::string exception)
	{
		std::cout << exception << std::endl;
		SaveToLogFile("ScoreErrors.log", exception);
	}
}

Score::~Score()
{
}

Score & Score::operator=(const Score & oldScore)
{
	this->actualScore = oldScore.actualScore;
	this->multiplier = oldScore.multiplier;
	for (auto i = 0; i < MAX_SCORES; ++i)
	{
		this->scoreBoard[i].name = oldScore.scoreBoard[i].name;
		this->scoreBoard[i].score = oldScore.scoreBoard[i].score;
	}
	return *this;
}

Score & Score::operator=(Score && oldScore)
{
	this->actualScore = oldScore.actualScore;
	this->multiplier = oldScore.actualScore;
	for (auto i = 0; i < MAX_SCORES; ++i)
	{
		this->scoreBoard[i].name = oldScore.scoreBoard[i].name;
		this->scoreBoard[i].score = oldScore.scoreBoard[i].score;
	}
	return *this;
}

float Score::GetMultiplier()
{
	return this->multiplier;
}

float Score::GetActualScore()
{
	return this->actualScore;
}

float Score::GetHighestScore()
{
	return this->scoreBoard[this->HIGHEST_SCORE].score;
}

std::string Score::GetName()
{
	return this->name;
}

void Score::SetName(const std::string &name)
{
	this->name = name;
}

std::string Score::PrintScore()
{
	int iScore = int(this->actualScore);
	return std::to_string(iScore);
}

void Score::PrintScores()
{
	system("cls");
	std::cout << "\t\t\tHIGHSCORES" << std::endl;
	for (auto i = 0; i < MAX_SCORES; ++i)
	{
		std::cout << i + ONE << ". " << std::setw(10) << scoreBoard[i].name << ": " << int(scoreBoard[i].score) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Press any button to back to previous screen.";
	system("pause >nul");
}

std::string Score::GetNameAndScoreFromScoreBoard(const unsigned int position)
{
	int iScore = int(scoreBoard[position].score);
	return scoreBoard[position].name + ": " + std::to_string(iScore);
}

void Score::ChangeMultiplier(const int level)
{
	this->multiplier = float(ONE + float(ONE - float(ONE / float(level))));
}

void Score::ResetScore()
{
	this->actualScore = 0;
}

void Score::ScoreUp(const int level,const unsigned int monsterType)
{
	this->actualScore += this->multiplier * level * monsterType * this->INITIAL_MONSTER_KILL;
}

void Score::TypeYourName(sf::RenderWindow * window, sf::Event * event, const sf::Font &font)
{
	sf::String str = this->name;
	sf::Text header("YOU DIED!", font,42);
	sf::Vector2f forOrigin{ 0.f,0.f };
	forOrigin.x = header.getGlobalBounds().width*HALF;
	header.setOrigin(forOrigin);
	header.setPosition(window->getSize().x*this->HEADER_POSITION.x, window->getSize().y*this->HEADER_POSITION.y);
	sf::Text type("Type your name: ", font);
	type.setPosition(window->getSize().x*(this->HEADER_POSITION.x - 0.4f),header.getPosition().y+100.f);
	sf::Text helper("Press ENTER to continue!", font);
	forOrigin.x = helper.getGlobalBounds().width*HALF;
	helper.setOrigin(forOrigin);
	helper.setPosition(window->getSize().x*this->HEADER_POSITION.x, window->getSize().y*(float(ONE) - this->HEADER_POSITION.y));
	sf::Text error("", font);
	const sf::String ERROR_MESSAGE = "Please use only LETTERS in your NAME";
	error.setFillColor(sf::Color::Red);
	error.setPosition(type.getPosition().x, type.getPosition().y + 50.f);
	sf::Text name(str,font);
	name.setPosition(type.getPosition().x+type.getGlobalBounds().width, type.getPosition().y);
	while (window->isOpen())
	{
		while (window->pollEvent(*event))
		{
			switch (event->type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::TextEntered:
				// Handle ASCII characters only
				if (event->text.unicode < 128)
				{
					if (event->text.unicode == '\n' || event->text.unicode == '\r')
					{
						if (std::regex_match(str.toAnsiString(), *(this->namePattern)))
						{
							this->name = str;
							return;
						}
						else
						{
							error.setString(ERROR_MESSAGE);
						}
					}
					else if (event->text.unicode == BACKSPACE)
					{
						error.setString("");
						if (!str.isEmpty())
						{
							str.erase(str.getSize() - ONE);
							name.setString(str);
						}
					}
					else
					{
						str += static_cast<char>(event->text.unicode);
						name.setString(str);
					}
				}
				break;
			}
		}
		window->clear();
		window->draw(header);
		window->draw(type);
		window->draw(error);
		window->draw(name);
		window->draw(helper);
		window->display();
	}
}

void Score::ShowScoreBoard(sf::RenderWindow * window, sf::Event * event, const sf::Font & font)
{
	sf::Text header("TOP 10:", font, 42);
	sf::Vector2f forOrigin{ 0.f,0.f };
	forOrigin.x = header.getGlobalBounds().width*HALF;
	header.setOrigin(forOrigin);
	header.setPosition(window->getSize().x*this->HEADER_POSITION.x, window->getSize().y*this->HEADER_POSITION.y);
	sf::Text helper("Press ENTER to continue!", font);
	forOrigin.x = helper.getGlobalBounds().width*HALF;
	helper.setOrigin(forOrigin);
	helper.setPosition(window->getSize().x*this->HEADER_POSITION.x, window->getSize().y*(float(ONE) - this->HEADER_POSITION.y));
	sf::Text scoreboard("", font);
	sf::String forScoreboard;
	scoreboard.setPosition(window->getSize().x*(this->HEADER_POSITION.x - 0.2f),header.getPosition().y+75.f);
	for (auto i = 0; i < MAX_SCORES; ++i)
	{
		forScoreboard += std::to_string(i + ONE) + ". " + GetNameAndScoreFromScoreBoard(i) + "\n";
	}
	scoreboard.setString(forScoreboard);
	while (window->isOpen())
	{
		while (window->pollEvent(*event))
		{
			switch (event->type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (event->key.code == sf::Keyboard::Enter)
				{
					return;
				}
			}
		}
		window->clear();
		window->draw(header);
		window->draw(scoreboard);
		window->draw(helper);
		window->display();
	}
}

void Score::EndGameScreen(sf::RenderWindow * window, sf::Event * event,const sf::Font &font)
{
	TypeYourName(window, event, font);
	if (CheckIfNewScoreIsHigherThanTheLastOne())
	{
		SaveToScoreBoard();
		SaveScoreBoardToFile();
	}
	ShowScoreBoard(window, event, font);
}

void Score::FillScoreBoardWith0()
{
	for (auto i = 0; i < MAX_SCORES; ++i)
	{
		this->scoreBoard[i].score = 0;
		this->scoreBoard[i].name = "HERO";
	}
}

bool Score::CheckIfNewScoreIsHigherThanTheLastOne()
{
	if (this->actualScore > this->scoreBoard[MAX_SCORES - ONE].score)
	{
		return true;
	}
	return false;
}

void Score::SaveToScoreBoard()
{
	this->scoreBoard[MAX_SCORES - ONE].name = this->name;
	this->scoreBoard[MAX_SCORES - ONE].score = actualScore;
	std::sort(this->scoreBoard, this->scoreBoard + MAX_SCORES, [](ToScore a, ToScore b) {return a.score > b.score; });
}

void Score::GetScoreBoardFromFile()
{
	std::ifstream readFromFile;
	readFromFile.open(this->FILE_NAME.c_str(), std::ios::in | std::ios::binary);
	unsigned int i = 0;
	if (readFromFile.is_open())
	{
		while (!readFromFile.eof() && i<MAX_SCORES)
		{
			//readFromFile >> scoreBoard[i].name >> scoreBoard[i].score;
			readFromFile >> this->scoreBoard[i].name;
			readFromFile.seekg(+1, std::ios_base::cur);
			readFromFile.read((char*)&scoreBoard[i].score, sizeof(float));
			++i;
		}
		//readFromFile.read((char*)&scoreBoard, MAX_SCORES * sizeof(ToScore));
	}
	else
	{
		std::string exception = "An error occurred. I couldnt open the file " + this->FILE_NAME + " to read the data.";
		throw exception;
	}
	readFromFile.close();
}

void Score::SaveScoreBoardToFile()
{
	std::ofstream saveToFile;
	saveToFile.open(this->FILE_NAME.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
	if (saveToFile.is_open())
	{
		for (auto i = 0; i < MAX_SCORES; ++i)
		{
			//saveToFile << scoreBoard[i].name << " " << scoreBoard[i].score << std::endl;
			saveToFile << this->scoreBoard[i].name << " ";
			saveToFile.write((char*)&scoreBoard[i].score, sizeof(float));
		}
		//saveToFile.write((char*)&scoreBoard, MAX_SCORES * sizeof(ToScore));

	}
	else
	{
		std::string exception = "An error occurred. I couldnt open the file "+this->FILE_NAME+" to save the data.";
		throw exception;
	}
	saveToFile.close();
}

void Score::SaveToLogFile(const std::string & logFileName, const std::string & message)
{
	time_t timer;
	time(&timer);
	std::ofstream logFile(logFileName.c_str(), std::ios_base::app);
	if (logFile.is_open())
	{
		char actualTime[26];
		ctime_s(actualTime, 26, &timer);
		for (int i = 0; i < 26; ++i)
		{
			if (actualTime[i] == '\n' || actualTime[i] == '\r')
			{
				actualTime[i] = '\0';
			}
		}
		logFile << "<" << actualTime << "> " << message << std::endl;
	}
	logFile.close();
}