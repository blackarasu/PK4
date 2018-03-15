#pragma once
#include <exception>
#include <iostream>
using namespace std;

class wrongHeight : public exception {
	virtual const char* what() const throw();
};

class Prism
{
private:
	double height;
public:
	void setHeight(double _height);
	double getHeight() { return height; }
	Prism(double _height);
	Prism();
	~Prism();
};

