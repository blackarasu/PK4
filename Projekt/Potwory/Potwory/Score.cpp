#include "stdafx.h"
#include <iomanip>
#include "score.h"

Score::Score()
{
	this->multiplier = 1.0;
	this->actualScore = 0.0;
	FillScoreBoardWith0();
	GetScoreBoardFromFile(FILE_NAME);
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
	return multiplier;
}

float Score::GetActualScore()
{
	return actualScore;
}

float Score::GetHighestScore()
{
	return this->scoreBoard[0].score;
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

std::string Score::GetNameAndScoreFromScoreBoard(unsigned int position)
{
	int iScore = int(scoreBoard[position].score);
	return scoreBoard[position].name + ": " + std::to_string(iScore);
}

void Score::ChangeMultiplier(int level)
{
	this->multiplier = float(ONE + float(ONE - float(ONE / float(level))));
}

void Score::ResetScore()
{
	actualScore = 0;
}

void Score::ScoreUp(int level)
{
	this->actualScore += multiplier * level;
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
	if (actualScore > scoreBoard[MAX_SCORES - ONE].score)
	{
		return true;
	}
	return false;
}

void Score::SaveToScoreBoard(std::string name)
{
	this->scoreBoard[MAX_SCORES - ONE].name = name;
	this->scoreBoard[MAX_SCORES - ONE].score = actualScore;
	std::sort(scoreBoard, scoreBoard + MAX_SCORES, [](ToScore a, ToScore b) {return a.score > b.score; });
}

void Score::GetScoreBoardFromFile(std::string fileName)
{
	std::ifstream readFromFile;
	readFromFile.open(fileName.c_str(), std::ios::in | std::ios::binary);
	unsigned int i = 0;
	if (readFromFile.is_open())
	{
		while (!readFromFile.eof() && i<MAX_SCORES)
		{
			//readFromFile >> scoreBoard[i].name >> scoreBoard[i].score;
			readFromFile >> scoreBoard[i].name;
			readFromFile.seekg(+1, std::ios_base::cur);
			readFromFile.read((char*)&scoreBoard[i].score, sizeof(float));
			++i;
		}
		//readFromFile.read((char*)&scoreBoard, MAX_SCORES * sizeof(ToScore));
	}
	else
	{
		std::string exception = "An error occurred. I couldnt open the file to read the data.";
		throw exception;
	}
	readFromFile.close();
}

void Score::SaveScoreBoardToFile(std::string fileName)
{
	std::ofstream saveToFile;
	saveToFile.open(fileName.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
	if (saveToFile.is_open())
	{
		for (auto i = 0; i < MAX_SCORES; ++i)
		{
			//saveToFile << scoreBoard[i].name << " " << scoreBoard[i].score << std::endl;
			saveToFile << scoreBoard[i].name << " ";
			saveToFile.write((char*)&scoreBoard[i].score, sizeof(float));
		}
		//saveToFile.write((char*)&scoreBoard, MAX_SCORES * sizeof(ToScore));

	}
	else
	{
		std::string exception = "An error occurred. I couldnt open the file to read the data.";
		throw exception;
	}
	saveToFile.close();
}

