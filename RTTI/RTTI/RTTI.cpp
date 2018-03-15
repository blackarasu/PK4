// RTTI.cpp : Defines the entry point for the console application.
//

/*
*      PK4 RTTI
*
*      Zadania dotycz¹ wykorzystania mechanizmów RTTI w jêzyku C++
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

	// dodaj metodê className zwracaj¹c¹ nazwê klasy
	// odkomentuj wywo³anie funkcji getAnimalsClassNames znajduj¹ce siê w funkcji main aby sprawdziæ dzia³anie metody
	//
	// PS: mozliwe ze przed nazw¹ klasy bêdzie siê wyœwietlaæ tajemnicza cyfra, zale¿y to od implementacji klasy type_info w ró¿nych œrodowiskach
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

		// poniewa¿ tylko prawdziwe koty mog¹ opanowaæ œwiat, a inne zwierzêta dziedzicz¹ce po nich nie s¹ w stanie tego zrobiæ...
		// u¿yj odpowiedniego operatora mechanizmu RTTI aby tylko dla obiektów klasy Cat (wykluczaj¹c klasy pochodne) na standardowe wyjœcie by³o wypisywane:
		// "humans are my servants because I am a " + nazwa klasy przy u¿yciu metody className zaimplementowanej wczeœniej
		// natomiast na obiektach klas pochodnych od klasy Cat powinna byæ u¿ywana medota speak
		//
		// aby przetestowaæ dzia³anie metody odkomentuj wywo³anie funkcji oneCatExample w funkcji main
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
	// u¿ywaj¹c operatora dynamic_cast uzupe³nij warunek, tak aby metoda speak wykonywa³a siê dla klasy Cat oraz ka¿dej jej klasy pochodnej
	//
	// aby przetestowaæ dzia³anie funkcji odkomentuj jej wywo³anie w funkcji main

	
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
	// powinno wypisac w konsoli 10 nazw klas zwierz¹t


	oneCatExample();
	//
	// powinno wypisaæ w konsoli "One cat trying to rule the world says: humans are my servants because I am a Cat"
	// ostatnie s³owo Cat mo¿e zawieraæ w sobie jak¹œ cyfrê lub ró¿niæ siê w inny sposób


	 letTheCatsOut(animals);
	//
	// dla wszystkich obiektów klasy Cat powinno wypisaæ zdanie "humans are my servants because I am a Cat"
	// dla obiektów klas jej pochodnych (Tiger, Nyan) powinno wypisaæ s³owo zdefiniowane w wirtualnej metodzie speak
	// (liczbê obiektów klasy cat i pochodnych mo¿na prosto zweryfikowaæ z wynikiem wywo³ania getAnimalsClassNames z zadania 1)
	 _getch();
	return 0;
}

