#pragma once
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
class NumberGenerator
{
private:
	unsigned int howMany;
	int start, end;
public:
	void setStart(int _start);
	void setEnd(int _end);
	void setHowMany(int _howMany);

	unsigned int getHowMany() { return howMany; }
	int getStart() { return start; }
	int getEnd() { return end; }

	void odd();
	void wypisz() {

	}
	NumberGenerator(){}
	NumberGenerator(unsigned int _howMany, int _start, int _end);
	~NumberGenerator();
};

