#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sstream>

void printSecondsFromStart() {
	int secondCounter = 0;
	while (secondCounter <= 30) {
		std::string secondsText = "\nSeconds from start: " + std::to_string(secondCounter) + "\n";
		std::cout << secondsText;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		secondCounter++;
	}
}

// Zadanie 1
// Stworzyc wektor, a nastepnie dodac do niego:
//        4 watki, gdzie kazdy wypisuje inna litere po 10 razy (napisac potrzebna funkcje).
//        1 watek, ktory wypisuje co sekunde liczbe sekund ktore minely od stworzenia tego watku ( funkcja "printSecondsFromStart").
//            Ten jeden watek ma dzialac nieprzerwanie az do konca programu. Lub mozna ustawic na 30s.
//            Zamienic ten watek z innym losowym watkiem znajdujacym sie w wektorze.

//    Wypisac id watkow znajdujacych sie w wektorze oraz id watka glownego. Przed zamiana watkow oraz po.

void wypisz(char znak)
{
	for (int i = 0; i < 10; i++)
		std::cout<<znak<<" ";
}
void Zadanie1() {
	std::vector<std::thread> threads;
	char znak = 'a';
	for (int i = 0; i < 4; ++i)
	{
		threads.push_back(std::thread(std::ref(wypisz), znak));
		++znak;
	}
	for (auto i = 0; i < threads.size(); ++i)
	{
		if (threads[i].joinable())
		{
			threads[i].join();
		}
	}
	
	threads.push_back(std::thread(printSecondsFromStart));
	threads[4].detach();
	for (auto i = 0; i < threads.size(); ++i)
	{
		std::cout << std::endl << "Id: " << threads[i].get_id() << std::endl;
	}
	threads[4].swap(threads[rand() % 4]);
	std::cout << "ID po zmianie: " << std::endl;
	for (auto i = 0; i < threads.size(); ++i)
	{
		std::cout << "ID: " << i << " " << threads[i].get_id()<<std::endl;
	}
	std::cout << "ID glownego watka: " << threads[4].get_id() << std::endl;
	for (auto i = 0; i < threads.size(); ++i)
	{
		if (threads[i].joinable())
		{
			threads[i].join();
		}
	}
	
	
}



class ScrewsFactory {
	int screws;
	std::mutex mutex;
public:
	int getNumberOfScrews() { return screws; }
	void produceScrews(int toProduce) {
		for (int i = 0; i < toProduce; i++) {
			mutex.lock();
			screws++;
			mutex.unlock();
		}
	}

	ScrewsFactory() : screws(0) {}
};


// Zadanie 2
// Stworzyc wektor oraz dodac do niego 5 watkow, ktorych zadaniem jest produkcja srub przy pomocy metody ScrewsFactory::produceScrews(int i).
// Wszystkie watki korzystaja z jednego obiektu klasy ScrewsFactory.
// Liczba produkowanych srub przez jeden watek wynosi 100000.
// Po zakonczeniu produkcji nalezy sprawdzic, czy liczba wyprodukowanych srub jest rowna (5 * 100000).
// W zadaniu wykorzystac mutex, w celu zabezpieczenia zmiennej "screws" przed niewlasciwym dostepem.

void Zadanie2() {
	int productionSize = 500000;

	ScrewsFactory screwsFactory;


	// . . .
	std::vector<std::thread> threads;
	for (auto i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread(&ScrewsFactory::produceScrews, &screwsFactory, productionSize));
	}
	for (auto i = 0; i < threads.size(); ++i)
	{
		if (threads[i].joinable())
		{
			threads[i].join();
		}
	}
	if (screwsFactory.getNumberOfScrews() == 5 * productionSize)
		std::cout << "Zliczono bez problemow. Liczba srub: " << screwsFactory.getNumberOfScrews() << std::endl;
	else
		std::cout << "Zliczona liczba sie nie zgadza. Zliczono: " << screwsFactory.getNumberOfScrews() << std::endl;
}


// Zadanie 3
// Zsumowac elementy w wektorze "std::vector<int> numbers" o podanej wielkosci i losowych elementach.
// Sumowanie ma polegac na:
// Napisac funkcje sumujaca elementy w podanym przedziale (void sumNumbers ...).
// Stworzyc 5 watkow, ktore beda sumowac w odpowiednich zakresach przy uzyciu funkcji "sumNumbers".
// Zmierzyc czas sumowania, a nastepnie porownac czas z sumowaniem w jednym watku.
// Porownac uzyskane wyniki sumowan w celu potwierdzenia poprawnosci dzialania.
// W zadaniu wykorzystac atomic w celu sumowania.


void sumNumbers(std::atomic<unsigned long long>&sum, std::vector<int>&numbers, int begin, int end)
{
	for (int i = begin; i < end; ++i)
	{
		sum += numbers[i];
	}
}

void Zadanie3() {
	int numberOfNumbersInThread = 200000;
	std::vector<int> numbers(numberOfNumbersInThread * 5);

	for (int i = 0; i < numbers.size(); i++)
		numbers[i] = rand() % 100;
	std::vector<std::thread> threads;
	std::atomic<unsigned long long>sum=0;
	int start = std::clock();
	// . . .
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(std::thread(sumNumbers, std::ref(sum), std::ref(numbers), numberOfNumbersInThread*i, numberOfNumbersInThread*(i + 1)));
	}
	for (auto i = 0; i < threads.size();++i)
	{
		if (threads[i].joinable())
		{
			threads[i].join();
		}
	}
	int counter = std::clock() - start;
	start = std::clock();
	unsigned long long sumSecond = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		sumSecond += numbers[i];
	}
	int counterSecond = std::clock()-start;
	if (sum == sumSecond)
		std::cout << "With threads: " << counter << std::endl << "Without threads: " << counterSecond << std::endl;
	else
		std::cout << "Sums are not matching " << std::endl;
}

int main() {
	srand(time(NULL));

	std::cout << "Zadanie 1\n" << std::endl;
		Zadanie1();

	// Zadania nalezy powtorzyc kilka razy, poniewaz mozemy otrzymac dobry wynik, przy blednym rozwiazaniu zadania.
	// Na przyklad moze sie zdazyc, ze wyscig nie wystapi przy pierwszym uruchomieniu.
	std::cout << "\n\nZadanie 2\n" << std::endl;
	for (int i = 0; i < 5; i++)
		Zadanie2();

	std::cout << "\n\nZadanie 3\n" << std::endl;
	for (int i = 0; i < 5; i++)
		Zadanie3();


	std::cin.get();

	return 0;

}
