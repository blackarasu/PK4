// Kontenery STL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "sstream"
#include "string"
#include "map"
#include "set"
#include "vector"
#include "list"
#include "iterator"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
using namespace std;



void wypisz(list <int> lista)
{
	list<int>::iterator it;
	for (it = lista.begin(); it != lista.end(); ++it)
	{
		cout << *it <<" ";
	}
	cout << endl;
}

class animal
{
public:
	virtual void glos() = 0;
};
class cat : public animal
{
public:
	void glos();
};

class dog : public animal
{
public:
	void glos();
};

class fish : public animal
{
public:
	void glos();
};
void cat::glos()
{
	cout << "Miau" << endl;
}

void dog::glos()
{
	cout << "Hal" << endl;
}

void fish::glos()
{
	cout << "Goldeen goldeen" << endl;
}

void podziel(const string& str, vector<string>& cont)
{
	istringstream iss(str);
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(cont));
}

int main()
{
	srand(unsigned int(time(NULL)));
	// ZADANIE 1 Stwórz listê intów i zape³nij j¹ losowymi wartoœciami, Napisz funkcjê wypisz() wypisuj¹ca ca³¹ listê, oraz posortuj listê i wypisz j¹ na nowo

	list<int> zmienna;
	for (auto i = 0; i < 10; ++i)
	{
		zmienna.push_back(rand());
	}
	wypisz(zmienna);
	zmienna.sort();
	wypisz(zmienna);
	// ZADANIE 2 Stwórz vector wskaŸników klasy animal i zape³nij je losowymi zwierzêtami, nastêpnie niech ka¿de z tych zwierz¹t u¿yje metody glos()
	vector<animal*> zwierzeta;
	for (auto i = 0; i < 10; ++i)
	{
		switch (rand() % 3)
		{
		case 0:
			zwierzeta.push_back(new cat());
			break;
		case 1:
			zwierzeta.push_back(new dog());
			break;
		case 2:
			zwierzeta.push_back(new fish());
		}
	}
	for (size_t i = 0; i < zwierzeta.size(); ++i)
	{
		zwierzeta[i]->glos();
	}
	// ZADANIE 3 Podane poni¿ej zdanie rozbito na pojedyncze s³owa i wstawione je do vectora stringów slowa, uzyj tego vectora do stworzenia kontenerow set i mapa.Przy ich u¿yciu policz ile jest unikalnych s³ów, i ile razy ka¿de s³owo siê powtarza.
	char tekst[] = "ja ja ja sie sie bardzo jakam i i i policz ile ile ile slow slow powiedzialem";
	vector<string> slowa;
	podziel(tekst, slowa);
	set<string> s1;
	set<string>::iterator it1;
	map<string, int>s2;
	map<string, int>::iterator it2;
	for (size_t i = 0; i < slowa.size(); ++i)
	{
		s1.insert(slowa[i]);
		if (s2.count(slowa[i]) == 0)
		{
			s2[slowa[i]] = 1;
		}
		else
		{
			s2[slowa[i]] = ++s2[slowa[i]];
		}
	}
	for (it2 = s2.begin(); it2 != s2.end(); ++it2)
	{
		cout << it2->first << ": " << it2->second << endl;
	}
	cout << "Liczba slow wypowiedzianych przez osobe z jakaniem: " << s1.size() << endl;
	return 0;
}
