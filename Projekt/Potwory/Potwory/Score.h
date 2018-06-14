//Tabela najlepszych wyników, obliczanie wyniku
//Zapis/odczyt pliku wyników, zapamiêtanie nazwy gracza
#pragma once
#include "stdafx.h"
#include <regex>
#include "Constances.h"
#define ONE unsigned int(1)
const unsigned int MAX_SCORES = 10;

struct ToScore
{
	std::string name;
	float score;
};

class Score
{
private:
	const std::string FILE_NAME = "..//scores//scores.bin";
	const unsigned int HIGHEST_SCORE = 0;
	const unsigned int INITIAL_MONSTER_KILL = 100;//score for normal monster / small
	const sf::Vector2f HEADER_POSITION{ 0.5f,0.1f };
	std::regex *namePattern;
	float actualScore;
	float multiplier;
	ToScore scoreBoard[MAX_SCORES];
	std::string name;
public:
	Score();
	~Score();
	Score& operator=(const Score &oldScore);
	Score& operator=(Score &&oldScore);
	//Koniec gry i wyswietlanie wyniku
private:
	float GetMultiplier();
	float GetActualScore();
	float GetHighestScore();
	std::string GetName();
	void SetName(const std::string &name);
public:
	std::string PrintScore();
	void PrintScores();
private:
	std::string GetNameAndScoreFromScoreBoard(const unsigned int position);
public:
	//Zmiany podczas gry i przygotowania
	void ChangeMultiplier(int level);
	void ResetScore();
	void ScoreUp(const int level,const unsigned int monsterType); //changed for monsters/objects
	//End-GameScreen
	void TypeYourName(sf::RenderWindow *window, sf::Event *event, const sf::Font &font);
	void ShowScoreBoard(sf::RenderWindow *window, sf::Event *event, const sf::Font &font);
	void EndGameScreen(sf::RenderWindow *window, sf::Event *event, const sf::Font &font);//end-Game-screen in sfml -> type your name, see your final score, show scoreboard with 10 first heroes and color your score if you went in scoreboard
private:
	void FillScoreBoardWith0();
	//Zapis do plikow i highScores	
	bool CheckIfNewScoreIsHigherThanTheLastOne();
	void SaveToScoreBoard();
	void GetScoreBoardFromFile();
	void SaveScoreBoardToFile();
	//inne
	void SaveToLogFile(const std::string & logFileName, const std::string & message);
};