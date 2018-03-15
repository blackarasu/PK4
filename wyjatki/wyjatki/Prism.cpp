#include "Prism.h"

const char* wrongHeight::what() const throw() {
	return "Invalid height\n";
}

void Prism::setHeight(double _height) {
	if(_height>0)
	height = _height;
	else throw wrongHeight();
}

Prism::Prism(double _height) {
setHeight(_height);
}
 

Prism::Prism()
{
}


Prism::~Prism()
{
}
