#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <deque>
#include <iterator>

using namespace std;

class Complex
{
	double re, im;

public:
	Complex() {};
	~Complex() {};

	void setRe(double r) { re = r; };
	void setIm(double i) { im = i; };

	double getRe() { return re; };
	double getIm() { return im; };


};

bool ifSecondBiggerRe(Complex &c1, Complex&c2)
{
	if (c1.getRe() < c2.getRe())
		return true;
	else
		return false;
}

bool ifSecondBiggerIm(Complex &c1, Complex&c2)
{
	if (c1.getIm() < c2.getIm())
		return true;
	else
		return false;
}

int main()
{
	const int n = 10;

	default_random_engine generator;
	uniform_real_distribution<double> distribution(1, 10);
	distribution(generator);

	vector<Complex> Vector_1(n);
	vector<Complex> Vector_2(n);
	vector<Complex> Vector_3(n);
	vector<Complex> Vector_4(2 * n);

	for (int i = 0; i < n; i++)
	{
		Vector_1[i].setIm(distribution(generator));
		Vector_1[i].setRe(distribution(generator));
	}
	for (int i = 0; i < n; i++)
	{
		Vector_2[i].setIm(distribution(generator));
		Vector_2[i].setRe(distribution(generator));
	}

	//--------------------------algorytmy-------------------------//

	//Zadanie 1 posortowa� Vector_1 wzgl�dem warto�ci Re (sort())

	sort(Vector_1.begin(), Vector_1.end(), ifSecondBiggerRe);

	//Zadanie 2 posortowa� Vecotr_2 wzgl�dem warto�ci Re zaimplementowanym algorytmem sortowania b�belkowego (swap())

	int change;
	do
	{
		change = 0;
		for (auto i = 0; i < Vector_2.size()-1; ++i)
		{
			if (Vector_2[i].getRe()>Vector_2[i + 1].getRe())
			{
				swap(Vector_2[i],Vector_2[i + 1]);
				change++;
			}
		}
	} while (change != 0);

	//Zadanie 3 skopiowa� Vector_1 do Vector_3 i posortowa� go wzgl�dem warto�ci Im (copy())

	copy(Vector_1.begin(), Vector_1.end(), Vector_3.begin());
	sort(Vector_3.begin(), Vector_3.end(), ifSecondBiggerIm);

	//Zadanie 4 Po��czy� Vector_1 i Vector _2 i posortowa� je wzgl�dem warto�ci Re (merge())

	merge(Vector_1.begin(), Vector_1.end(), Vector_2.begin(), Vector_2.end(),Vector_4.begin(),ifSecondBiggerRe);
	//sort(Vector_4.begin(), Vector_4.end(), ifSecondBiggerRe);

	cout << "PIERWSZY VECTOR" << endl;
	for (int i = 0; i<Vector_1.size(); i++)
		cout << Vector_1[i].getRe() << "  " << Vector_1[i].getIm() << endl;

	cout << endl << endl;
	cout << "DRUGI VECTOR" << endl;
	for (int i = 0; i<Vector_2.size(); i++)
		cout << Vector_2[i].getRe() << "  " << Vector_2[i].getIm() << endl;

	cout << endl << endl;

	cout << "TRZECI VECTOR" << endl;
	for (int i = 0; i<Vector_3.size(); i++)
		cout << Vector_3[i].getRe() << "  " << Vector_3[i].getIm() << endl;

	cout << endl << endl;

	cout << "CZWARTY VECTOR" << endl;
	for (int i = 0; i<Vector_4.size(); i++)
		cout << Vector_4[i].getRe() << "  " << Vector_4[i].getIm() << endl;


	//--------------------------iteratory-------------------------//


	//Zadanie 1 Utw�rz Vector typu int i wype�nij go kolejno liczbami naturalnymi od 0 do 9.  

	vector<int> myVector;
	for (int i = 0; i < 10; ++i)
	{
		myVector.push_back(i);
	}

	//Zadanie 2 Utw�rz iterator i przy jego pomocy wy�wietl zawarto�� Vectora 

	vector<int>::iterator etMyVector;
	for (etMyVector = myVector.begin(); etMyVector != myVector.end(); ++etMyVector)
	{
		cout << *etMyVector << " ";
	}
	cout << endl;

	//Zadanie 3 Przy u�yciu odwr�conego iteratora(reverse_iterator) wy�wietl elementy od ko�ca 

	vector<int>::reverse_iterator etMyVector_Reverse;
	for (etMyVector_Reverse = myVector.rbegin(); etMyVector_Reverse != myVector.rend(); ++etMyVector_Reverse)
	{
		cout << *etMyVector_Reverse<<" ";
	}
	cout << endl;
	//Zadanie 4 Utw�rz trzeci iterator, kt�remu przypiszesz element o warto�ci 6(u�yj funkcji find()).
	//Nast�pnie wy�wietl elementy zaczynaj�c od tego iteratora do ko�ca Vectora.

	vector<int>::iterator find6 = find(myVector.begin(), myVector.end(), 6);
	cout << *find6 << endl;

	for (find6; find6 != myVector.end(); find6++)
		cout << *find6 << "  ";
	cout << endl;

	//Zadanie 5 Utw�rz pusty deque typu int. Przy pomocy odpowiednich iterator�w wstaw dwa elementy 
	//na pocz�tek i na koniec(front_insert_iterator / back_insert_iterator)

	deque<int> kolejka;
	front_insert_iterator<deque <int>> front_it(kolejka);
	back_insert_iterator<deque<int>> back_it(kolejka);
	*front_it = 20;
	*front_it = 25;
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); ++i)
	{
		cout << *i<<" ";
	}
	cout << endl;

	*back_it = 55;
	*back_it = 60;
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	//Zadanie 6 Przy pomocy odpowiedniego iteratora wstaw element na drug� pozycj� (insert_iterator) 
	insert_iterator<deque<int>> putin(kolejka, kolejka.begin() + 1);
	*putin = 69;
	for (deque<int>::iterator i = kolejka.begin(); i != kolejka.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;

	system("PAUSE >nul");
	return 0;
}