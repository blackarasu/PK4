#include <regex>
#include <string>
#include <iostream>

/*ZADANIE 1
-W klasie Validation stwórz prywatnie pole 'regex'. Klasa ta będzie implementowała mechanizm walidacji danych.
-Następnie zdefiniuj konstruktor jednoargumentowy, który przyjmuje wzorzec.
-Napisz metodę check(), przyjmującą za argument string, zwracającą true lub false
w zależności od zgodności ze wzorcem.
-Napisz metodę search() tak aby zwracała w stringu zawartość danej grupy */


class Validation
{
private:
	std::regex pattern;
public:
	Validation() = default;
	~Validation() = default;
	Validation(const std::regex &pattern) :pattern(pattern) {}
	bool check(std::string input)
	{
		return std::regex_match(input, this->pattern);
	}

	std::string search(std::string input, int group)
	{
		std::smatch result;
		if (std::regex_search(input, result, pattern))
		{
			return result[group];
		}
		return "Nie znaleziono grupy";
	}

};
/*ZADANIE 2
-Napisz wzorzec (majlepiej w głównej funkcji main) dla prostych obliczeń liczb zespolonych (dodawanie, odejmowanie, mnożenie, dzielnie)
o budowie ((-)a1 +/- b1i ) +/-/* /: ((-)a2 + / -b2i) (𝑎1, 𝑎2, 𝑏1, 𝑏2∈𝑍 / {0}.
-Dany wzorzec pogrupuj, aby po użyciu metody search() z numerem grupy 1 została zwrócona
pierwsza liczba działania, a po podaniu grupy 2 została zwrócona druga liczba. Uwzględnij
możliwość nie pasujących danych wejściowych do metody search().
- W funkcji 'zad2' utwórz obiekt klasy Validation i przetestuj działanie metody check() oraz search()
dla podanych danych z funkcji main*/

void zad2(std::string in, std::regex pattern)
{
	Validation validate(pattern);
	std::cout << in << " ";
	std::cout << validate.check(in) << " " << validate.search(in, 0) << " " << validate.search(in, 1) << " " << validate.search(in, 2) << std::endl;
}

/*ZADANIE 3
-Napisz wzorzec (majlepiej w głównej funkcji main) dla poprawnej daty
w formacie: ROK\3_PIERWSZE_LITERY_MIES\NR_DNIA. Wykorzystaj powtórzenia ( {n}, {m, n}, {m, } ), grupy bez odwołania oraz ich alternatywy.
Dla uproszczenia możesz przyjąć, że rok posiada trzy miesiące.
- W następnej kolejności za pomocą funkcji 'zad3' sprawdź poprawność utworzonego wyrażenia obiektem klasy Validation dla przykładowych
danych zawartych w funkcji main

Zwróć uwagę na dowolność wielkości liter i znak " \ ".
*/

void zad3(std::string in, std::regex pattern)
{
	Validation validate(pattern);
	std::cout << in << " ";
	std::cout << validate.check(in) << std::endl << std::endl;
}

int main()
{
	std::regex ComplexPattern("(\\(-?[0-9]+[+-][0-9]+i\\))[*\\+-](\\(-?[0-9]+[+-][0-9]+i\\))"); //->uzupelnic ((-)a1 +/- b1i ) +/-/* /: ((-)a2 + / -b2i)
	//tu utwórz wzorzec 'ComplexPattern' z ZADANIA 2

	std::string worda = "(5+20i)+(2+5i)";
	std::string wordb = "(5+20i)-(2i+5)";
	std::string wordc = "(-60+3i)\\(-40+3i)";
	std::string wordd = "(-99)*(3+4i)";

	zad2(worda, ComplexPattern);
	zad2(wordb, ComplexPattern);
	zad2(wordc, ComplexPattern);
	zad2(wordd, ComplexPattern);

	//tu utwórz wzorzec 'DatePattern' z ZADANIA 3
	//std::regex DatePattern("([1-9]?[[:digit:]]{1,3})\\\\((?:[sS][tT][yY])|(?:[lL][uU][tT])|(?:[mM][aA][rR]))\\\\([1-9]|[1-2][[:digit:]]|3[01])");;
	std::regex DatePattern("([1-9]?[[:digit:]]{1,3})\\\\((?:[sS][tT][yY])|(?:[lL][uU][tT])|(?:[mM][aA][rR])|(?:[kK][wW][iI])|(?:[mM][aA][jJ])|(?:[cC][zZ][wW])|(?:[lL][iI][pP])|(?:[sS][iI][eE])|(?:[wW][rR][zZ])|(?:[pP][aA][zZ])|(?:[lL][iI][sS])|(?:[gG][rR][uU]))\\\\([1-9]|[1-2][[:digit:]]|3[01])"); //ROK\3_PIERWSZE_LITERY_MIES\NR_DNIA
	//std::regex DatePattern("([1-9]?[:digit:]{1,3})\\\\((?:[sS][tT][yY])|(?:[lL][uU][tT])|(?:[mM][aA][rR])|(?:[kK][wW][iI])|(?:[mM][aA][jJ])|(?:[cC][zZ][wW])|(?:[lL][iI][pP])|(?:[sS][iI][eE])|(?:[wW][rR][zZ])|(?:[pP][aA][zZ])|(?:[lL][iI][sS])|(?:[gG][rR][uU]))\\\\([1-9]|[1-2][[:digit:]]|3[01])"); //ROK\3_PIERWSZE_LITERY_MIES\NR_DNIA
	std::string worde = "1999\\MAR\\31";
	std::string wordf = "2016\\Sty\\0";
	std::string wordg = "1\\LuT\\8";
	std::string wordh = "966\\mar\\64";

	zad3(worde, DatePattern);
	zad3(wordf, DatePattern);
	zad3(wordg, DatePattern);
	zad3(wordh, DatePattern);

	/*ZADANIE 4
	Używając funkcji regex_replace zmodyfikuj pierwszy przykład z zadania 3 tak, aby uzyskać następujące rezultaty:
	a) 1999-MAR-31 (przykładowo zrobiony)
	b) 31.MAR.1999
	c) <B>1999</B>\MAR\<B>31</B>*/

	std::regex zad5_a("\\\\");
	std::cout << std::regex_replace(worde, zad5_a, "-") << std::endl << std::endl;
	std::regex zad5_b("([[:alnum:]]+)\\\\([[:alnum:]]+)\\\\([[:alnum:]]+)");
	std::cout << std::regex_replace(worde, zad5_b, "$3.$2.$1") << std::endl;
	std::regex zad5_c("([[:alnum:]]+)");
	std::cout << std::regex_replace(worde, zad5_c, "<B>$&</B>") << std::endl;
	return 0;
}