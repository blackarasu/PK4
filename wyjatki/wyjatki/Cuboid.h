#pragma once
#include "Prism.h"
#include <math.h>

class wrongLength : public exception {
	virtual const char* what() const throw();
};

class wrongWidth : public exception {
	virtual const char* what() const throw();
};

class Cuboid : public Prism
{
private:
	double length, width;
public:
	double getLength() { return length; }
	double getWidth() { return width;}
	void setLength(double _length);
	void setWidth(double _width);

	double getArea();
	double getVolume();
	double getDiagonal();

	Cuboid(double _length, double _width, double _height);
	Cuboid();
	~Cuboid();

};

