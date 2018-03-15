#include <iostream>
#include "Cuboid.h"
#include "Prism.h"
#include "NumberGenerator.h"
#include <time.h>

int main() {
	srand(time(0));

	Cuboid c1;
	try {
		c1.setHeight(-110);
		c1.setLength(14);
		c1.setWidth(5);

		cout << "\nPole powierzchni: " << c1.getArea() << "\nObjetosc: " << c1.getVolume() << "\nPrzekatna: " << c1.getDiagonal() << "\n";
	}
	catch (exception& tmp) {
		cout << tmp.what();
	}
	
	NumberGenerator gen1(100,-10,50);
	gen1.odd();

	return 0;
}