#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

class Ksiazka
{
	int id;
	string tytul;
public:
	Ksiazka(int id, string tytul);
	void wypiszInformacje();
};

// ZADANIE 1
// Dodaj do klasy Uzytkownik kontener typu vector(Nazwij go zakupioneKsiazki), kt�ry b�dzie przechowywa� wska�niki na zakupione przez u�ytkownika ksi��ki.
// Jedna ksi��ka mo�e posiada� wi�cej ni� jeden wska�nik na jeden obiekt.
// Dodaj metode zakupu ksi��ki - przyjmuje wska�nik na ksi��k� do zakupienia i dodaje j� do kontenera.

// ZADANIE 2
// Utw�rz kontenery typu vector na wska�niki na uzytkownik�w i ksi��ki. Utw�rz 3 obiekty i wska�niki pozostaw w kontenerach.
// Wypisz dane uzytkownikow oraz informacje o ksiazkach.

// ZADANIE 3
// Dokonaj zakupu kilku losowych ksi��ek dla ka�dego z u�ytkownik�w.
// Odkomentuj metode wypiszZakupy()
// Wypisz wszystkie zakupy ka�dego z u�ytkownik�w.
// Podaj ilo�� zakupionych egzemplarzy dla ka�dego z dost�pnych tytu��w. Dokonaj tego poprzez zliczenie wyst�pie� wska�nika na dany obiekt.
// Pami�taj, �e po jednym wyst�pieniu znajduje si� w utworzonym w zadaniu 2 kontenerze na ksi��ki.

// ZADANIE 4
// Sprawdz czy zresetowanie wskaznika na ksiazke usunie obiekt. Uzyj do tego weak_ptr oraz metody expired().
// Sprawdz liczbe wystapien referencji po tym zdarzeniu.
// Przywroc zmiany sprzed zresetowania za pomoc� utworzonego wcze�niej weak_ptr oraz metody lock().

class Uzytkownik
{
	string imie;
	string nazwisko;
	vector<shared_ptr <Ksiazka>>zakupioneKsiazki;
public:
	Uzytkownik(string imie, string nazwisko);
	void KupKsiazke(shared_ptr <Ksiazka>);
	void wypiszDane();
	void wypiszZakupy();
};

int main()
{
	srand(time(NULL));
	//zad 2
	vector<unique_ptr <Uzytkownik>>uzytkownicy;
	uzytkownicy.push_back(make_unique<Uzytkownik>("Patryk", "Kram"));
	uzytkownicy.push_back(make_unique<Uzytkownik>("Mac", "Bro"));
	uzytkownicy.push_back(make_unique<Uzytkownik>("Paw", "Waw"));

	cout << "Info uzytkownicy" << endl;
	for (auto i = 0; i < uzytkownicy.size(); ++i)
	{
		uzytkownicy[i]->wypiszDane();
	}

	vector<shared_ptr <Ksiazka>>ksiazki;
	ksiazki.push_back(make_shared<Ksiazka>(1,"TUC"));
	ksiazki.push_back(make_shared<Ksiazka>(2,"KUC"));
	ksiazki.push_back(make_shared<Ksiazka>(3,"SMiW"));

	cout << "Info ksiazki" << endl;
	for (auto i = 0; i < ksiazki.size(); ++i)
	{
		ksiazki[i]->wypiszInformacje();
	}
	//zad 3
	for (auto i = 0; i < uzytkownicy.size(); ++i)
	{
		for (auto j = 0; j < 10; ++j)
		{
			switch (rand() % 3)
			{
			case 0:
				uzytkownicy[i]->KupKsiazke(ksiazki[0]);
				break;
			case 1:
				uzytkownicy[i]->KupKsiazke(ksiazki[1]);
				break;
			case 2:
				uzytkownicy[i]->KupKsiazke(ksiazki[2]);
				break;
			}
		}
		uzytkownicy[i]->wypiszZakupy();
	}
	for (auto i = 0; i < ksiazki.size(); ++i)
	{
		cout << endl;
		ksiazki[i]->wypiszInformacje();
		cout << "Zostala zakupiona " << ksiazki[i].use_count() - 1 << " razy" << endl;
	}
	
	//Zad 4
	weak_ptr<Ksiazka> weakly(ksiazki[0]);
	if (weakly.expired())
	{
		cout << "Ksiazka nie istnieje" << endl;
	}
	else
	{
		cout << "Ksiazka istnieje" << endl;
	}
	ksiazki[0].reset();
	if (weakly.expired())
	{
		cout << "Ksiazka nie istnieje" << endl;
	}
	else
	{
		cout << "Ksiazka istnieje" << endl;
	}

	cout << "Ilosc wystapien " << weakly.use_count() << endl;
	ksiazki[0] = weakly.lock();
	cout << "Ilosc wystapien " << weakly.use_count() << endl;
	system("pause >nul");
	return 0;
}

Uzytkownik::Uzytkownik(string imie, string nazwisko)
	:imie(imie), nazwisko(nazwisko)
{
}

void Uzytkownik::KupKsiazke(shared_ptr<Ksiazka> ksiazka)
{
	this->zakupioneKsiazki.push_back(ksiazka);
}


void Uzytkownik::wypiszDane()
{
	cout << "Imie: " << this->imie << ". Nazwisko: " << this->nazwisko << endl;
}



void Uzytkownik::wypiszZakupy()
{
	std::cout << endl;
	this->wypiszDane();
	for (int i = 0; i < zakupioneKsiazki.size(); i++)
	{
		cout << "Zakupil: " << endl;
		zakupioneKsiazki[i]->wypiszInformacje();
	}
}



Ksiazka::Ksiazka(int id, string tytul)
	:id(id), tytul(tytul)
{
}

void Ksiazka::wypiszInformacje()
{
	cout << "ID ksiazki: " << this->id << ". Tytul: " << this->tytul << endl;
}