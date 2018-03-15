#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

//------------------

//Zadanie 1:
//Dla podanej klasy Kalkulator obs�uguj�cej operacje pierwiastkowania, dzielenia i logarytmowania, wyrzu� i obs�u� wyj�tki:
// - DividedBy0 dla dzielenia
// - Equals1 dla logarytmu
// - LessThan0 dla logarytmu i pierwiastka
//
//Klasy wyj�tk�w maj� dziedziczy� po klasie KalkulatorException
//
//Funkcja what() ma zwraca� opis wyj�tku.
//W bloku catch ka�dego wyj�tku wy�wietl jego opis

//------------------
class KalkulatorException
{
public:
	virtual const char* what() = 0;
};

class ExceptionDivBy0 :KalkulatorException
{
public:
	const char* what() { return "Nie mozna dzielic przez 0"; }
};

class ExceptionEquals1: KalkulatorException
{
public:
	const char* what() { return "Podstawa logarytmu rowna 1"; }
};

class ExceptionLessThan0 : KalkulatorException
{
public:
	const char* what() { return "Liczba logarytmowana Mniejsze od 0"; }
};

class Kalkulator
{
public:
	double Dzielenie(double a, double b)
	{
		try
		{
			if (b == 0)
			{
				throw ExceptionDivBy0();
			}
		}
		catch (ExceptionDivBy0 x)
		{
			std::cout<<x.what()<<std::endl;
		}
		return a / b;
	}
	double Logarytm(double a, double b)
	{
		try
		{
			if (a == 1)
			{
				throw ExceptionEquals1();
			}
			if (b < 0)
			{
				throw ExceptionLessThan0();
			}
		}
		catch(ExceptionEquals1 x)
		{
			std::cout << x.what() << std::endl;
		}
		catch (ExceptionLessThan0 x)
		{
			std::cout << x.what() << std::endl;
		}
		return log(b) / log(a);
	}
	double Pierwiastek(double a)
	{
		return sqrt(a);
	}
};
//------------------

//Zadanie 2:
//Za wykorzystaniem mechanizmu zagnie�d�ania wyj�tk�w, w metodzie Podroz::WybierzSrodekTransportu 
//obs�u� wyb�r �rodka transportu w zale�no�ci od zadanej pr�dko�ci.
//
//Wyb�r �rodka transportu nast�puje po przez por�wnanie zadanej pr�dko�ci z pr�dko�ci� maksymaln� ka�dego pojazdu,
//pocz�wszy od najwolniejszego.
//
//W przypadku Zadanej pr�dko�ci mniejszej lub r�wnej 0, wyrzu� wyj�tek NegativeOrZeroVelocity i wy�wietl stosowny komunikat.
//W przypadku zadanej pr�dko�ci wy�szej od najszybszego pojazdu, wy�wietl stosowny komunikat.
//Dla wyboru poszczeg�lnych pojazd�w wy�wietl komunikaty o ich wyborze.

//------------------
class SrodekTransportu
{
public:
	double predkoscMax;
};

class Rower : public SrodekTransportu
{
public:
	Rower()
	{
		this->predkoscMax = 50;
	}
};

class Samochod : public SrodekTransportu
{
public:
	Samochod()
	{
		this->predkoscMax = 200;
	}
};
class Shinkansen : public SrodekTransportu
{
public:
	Shinkansen()
	{
		this->predkoscMax = 405;
	}
};

class NegativeOrZeroVelocity
{

};
class Podroz
{
private:
	Rower rower;
	Samochod samochod;
	Shinkansen shinkansen;
public:
	Podroz()
	{
		this->rower = Rower();
		this->samochod = Samochod();
		this->shinkansen = Shinkansen();
	}
	void WybierzSrodekTransportu(double predkosc)
	{
		try
		{
			if (predkosc <= 0)
				throw NegativeOrZeroVelocity();
			if (predkosc < rower.predkoscMax)
				cout << "Wybor padl na rower" << endl;
			else
				throw predkosc;
		}
		catch (NegativeOrZeroVelocity)
		{
			std::cout << "Predkosc musi byc wieksza od 0"<<std::endl;
		}
		catch (double predkosc)
		{
			try 
			{
				if (predkosc < samochod.predkoscMax)
				{
					std::cout << "Wybor samochod" << std::endl;
				}
				else
					throw predkosc;
			}
			catch (double predkosc)
			{
				try
				{
					if (predkosc < shinkansen.predkoscMax)
					{
						std::cout << "Wybor shinkansen" << std::endl;
					}
					else
					{
						throw predkosc;
					}
				}
				catch (...)
				{
					std::cout << "Jestesmy zbyt biedni, nie mamy takiego pojazdu"<<std::endl;
				}
			}

		}

		//Komunikaty:
		//cout << "Predkosc musi byc wieksza od 0" << endl;
		//cout << "Wybor padl na rower" << endl;
		//cout << "Wybor padl na samochod" << endl;
		//cout << "Wybor padl na shinkansen" << endl;
		//cout << "Nie dysponujemy tak szybkim pojazdem" << endl;
	}
};
//------------------

//Zadanie 3:
//Obs�u� wyj�tek wyrzucany w funkcji getTooLongSubstring()
//
//W bloku catch wy�wietl opis wyrzuconego wyj�tku przy u�yciu funkcji what();

//------------------
string getTooLongSubstring()
{
	//Rzucany wyj�tek: std::exception& e
	try
	{
		return std::string("abc").substr(10);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
int main()
{
	//Zadanie 1:
	Kalkulator kalkulator;
	kalkulator.Dzielenie(100, 0);
	kalkulator.Logarytm(1, 100);
	kalkulator.Logarytm(-5, 10);
	kalkulator.Pierwiastek(-5);
	//Zadanie 2:
	Podroz podroz = Podroz();
	podroz.WybierzSrodekTransportu(-10);
	podroz.WybierzSrodekTransportu(0);
	podroz.WybierzSrodekTransportu(20);
	podroz.WybierzSrodekTransportu(100);
	podroz.WybierzSrodekTransportu(300);
	podroz.WybierzSrodekTransportu(1000);
	//Zadanie 3:
	getTooLongSubstring();

	getchar();
	return 0;
}