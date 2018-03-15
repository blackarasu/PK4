#include "Cuboid.h"

const char* wrongLength::what() const throw(){
	return "Invalid length\n";
}

const char* wrongWidth::what() const throw() {
	return "Invalid width\n";
}

double Cuboid::getArea() {
	double tmp = getHeight();
	return (2 * tmp*length + 2 * tmp*width + 2 * width*length);
}

double Cuboid::getVolume() {
	return (getHeight()*width*length);
}
double Cuboid::getDiagonal() {
	double tmp = (width*width + length*length);
	double tmp2 = getHeight();
	return sqrt(tmp + tmp2*tmp2);
}

void Cuboid::setLength(double _length){
	if(_length>0)
	length = _length;
	else throw wrongLength();
}

void Cuboid::setWidth(double _width) {
	if(_width>0)
	width = _width;
	else throw wrongWidth();
}

Cuboid::Cuboid(double _length, double _width, double _height) :length(_length), width(_width), Prism(_height) {

}
Cuboid::Cuboid()
{
}


Cuboid::~Cuboid()
{
}
