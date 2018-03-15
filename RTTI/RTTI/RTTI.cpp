// RTTI.cpp : Defines the entry point for the console application.
//

/*
*      PK4 RTTI
*
*      Zadania dotycz� wykorzystania mechanizm�w RTTI w j�zyku C++
*      Zalecanie jest wykonywanie ich po kolei od zadania 1 do 3
*
* */


#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <conio.h>
#include <typeinfo>
const int NUMBER_OF_ANIMALS = 10;

class Animal {
public:
	virtual ~Animal() {}
	virtual void speak() const = 0;

	/* ZADANIE 1 */

	// dodaj metod� className zwracaj�c� nazw� klasy
	// odkomentuj wywo�anie funkcji getAnimalsClassNames znajduj�ce si� w funkcji main aby sprawdzi� dzia�anie metody
	//
	// PS: mozliwe ze przed nazw� klasy b�dzie si� wy�wietla� tajemnicza cyfra, zale�y to od implementacji klasy type_info w r�nych �rodowiskach
	const char* className();
};

const char * Animal::className()
{
	return typeid(*this).name();
}

class Cat : public Animal {
public:
	void speak() const { std::cout << "Meow!" << std::endl; }
	void tryToRuleTheWorld() const {
		/* ZADANIE 2 */

		// poniewa� tylko prawdziwe koty mog� opanowa� �wiat, a inne zwierz�ta dziedzicz�ce po nich nie s� w stanie tego zrobi�...
		// u�yj odpowiedniego operatora mechanizmu RTTI aby tylko dla obiekt�w klasy Cat (wykluczaj�c klasy pochodne) na standardowe wyj�cie by�o wypisywane:
		// "humans are my servants because I am a " + nazwa klasy przy u�yciu metody className zaimplementowanej wcze�niej
		// natomiast na obiektach klas pochodnych od klasy Cat powinna by� u�ywana medota speak
		//
		// aby przetestowa� dzia�anie metody odkomentuj wywo�anie funkcji oneCatExample w funkcji main
		if (typeid(Cat) == typeid(*this))
		{
			std::cout << "humans are my servants because I am a " << typeid(*this).name() << std::endl;
		}
		else
		{
			this->speak();
		}
	};
};

class Dog : public Animal {
public:
	void speak() const { std::cout << "Hau!" << std::endl; }
};

class Tiger : public Cat {
public:
	void speak() const { std::cout << "mraU!" << std::endl; }
};

class Nyan : public Cat {
public:
	void speak() const { std::cout << "nyan!" << std::endl; }
};

Animal* randomAnimal() {
	switch (rand() % 4) {
	case 0:
		return new Cat();
	case 1:
		return new Dog();
	case 2:
		return new Tiger();
	case 3:
		return new Nyan();
	}
	return nullptr;
}

void randomAnimals(Animal *animals[]) {

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
		animals[i] = randomAnimal();
	}
}

void getAnimalsClassNames(Animal *animals[]) {
	std::cout << "\nAnimals class names:" << std::endl;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		std::cout << animals[i]->className() << std::endl;
	std::cout << std::endl;
}

void oneCatExample() {
	std::cout << "One cat trying to rule the world says: " << std::endl;
	Cat *cat = new Cat();
	cat->tryToRuleTheWorld();
	std::cout << std::endl;
}

void letTheCatsOut(Animal *animals[]) {

	/* ZADANIE 3 */
	// u�ywaj�c operatora dynamic_cast uzupe�nij warunek, tak aby metoda speak wykonywa�a si� dla klasy Cat oraz ka�dej jej klasy pochodnej
	//
	// aby przetestowa� dzia�anie funkcji odkomentuj jej wywo�anie w funkcji main

	
	for(int i =0; i < NUMBER_OF_ANIMALS; i++){
		Cat *cat = dynamic_cast<Cat *>(animals[i]);
		if(cat!=nullptr){
			cat->tryToRuleTheWorld();
		}
	}
	
}


int main() {
	srand(time(NULL));
	Animal *animals[NUMBER_OF_ANIMALS];
	randomAnimals(animals);

	 getAnimalsClassNames(animals);
	//
	// powinno wypisac w konsoli 10 nazw klas zwierz�t


	oneCatExample();
	//
	// powinno wypisa� w konsoli "One cat trying to rule the world says: humans are my servants because I am a Cat"
	// ostatnie s�owo Cat mo�e zawiera� w sobie jak�� cyfr� lub r�ni� si� w inny spos�b


	 letTheCatsOut(animals);
	//
	// dla wszystkich obiekt�w klasy Cat powinno wypisa� zdanie "humans are my servants because I am a Cat"
	// dla obiekt�w klas jej pochodnych (Tiger, Nyan) powinno wypisa� s�owo zdefiniowane w wirtualnej metodzie speak
	// (liczb� obiekt�w klasy cat i pochodnych mo�na prosto zweryfikowa� z wynikiem wywo�ania getAnimalsClassNames z zadania 1)
	 _getch();
	return 0;
}

