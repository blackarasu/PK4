//Tabela najlepszych wyników, obliczanie wyniku
//Zapis/odczyt pliku wyników, zapamiêtanie nazwy gracza
#pragma once
#include "stdafx.h"
#define ONE int(1)
const unsigned int MAX_SCORES = 10;

struct ToScore
{
	std::string name;
	float score;
};

class Score
{
private:
	const std::string FILE_NAME = "scores.bin";
	float actualScore;
	float multiplier;
	ToScore scoreBoard[MAX_SCORES];
public:
	Score();
	~Score();
	Score& operator=(const Score &oldScore);
	Score& operator=(Score &&oldScore);
	//Koniec gry i wyswietlanie wyniku
	float GetMultiplier();
	float GetActualScore();
	float GetHighestScore();
	std::string PrintScore();
	void PrintScores();
	std::string GetNameAndScoreFromScoreBoard(unsigned int position);
	//Zmiany podczas gry i przygotowania
	void ChangeMultiplier(int level);
	void ResetScore();
	void ScoreUp(int level);
	void FillScoreBoardWith0();
	//Zapis do plikow i highScores	
	bool CheckIfNewScoreIsHigherThanTheLastOne();
	void SaveToScoreBoard(std::string name);
	void GetScoreBoardFromFile(std::string fileName);
	void SaveScoreBoardToFile(std::string fileName);
};