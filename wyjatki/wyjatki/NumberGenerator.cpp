#include "NumberGenerator.h"


void NumberGenerator::odd() {
	int less0 = 0;
	int zeros = 0;
	int more0 = 0;
	int randNumber;

	for (int i = 0; i < howMany;) {
		randNumber = rand() % (end - start + 1) + start;
		try {

			if (randNumber % 2 == 0) throw 1;

			i++;
			cout << randNumber << " ";
		}

		catch (int) {
			try {
				if (randNumber < 0)
					throw 'u';
				else if (randNumber > 0)
					throw 2;
				else throw "aa";
			}

			catch (char) {
				less0++;
			}
			catch (int) {
				more0++;
			}
			catch (...) {
				cout << "sdfds";
				zeros++;
			}

		}
	}

	cout << "\nWystapienia liczb parzystych ujemnych: " << less0 << endl;
	cout << "Wystapienia liczb parzystych dodatnich: " << more0 << endl;
	cout << "Wystpiania zer: " << zeros << endl;
}


NumberGenerator::NumberGenerator(unsigned int _howMany, int _start, int _end) {
	howMany = _howMany;
	start = _start;
	end = _end;
}


NumberGenerator::~NumberGenerator()
{
}
