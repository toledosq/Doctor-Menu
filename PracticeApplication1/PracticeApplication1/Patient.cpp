#include "Patient.h"

Patient::Patient()
{
	height = 0;
	weight = 0.0;
}

// Overloaded constructor
Patient::Patient(string n, string s, int h, double w)
{
	name = n;
	height = h;
	weight = w;
	sex = s;
}

// Default decunstructor
Patient::~Patient()
{
}

// Accessor functions
string Patient::getName() const
{
	return name;
}
string Patient::getSex() const
{
	return sex;
}
int Patient::getHeight() const
{
	return height;
}
double Patient::getWeight() const
{
	return weight;
}
double Patient::getBMI() const
{
	return ((weight * 703) / (height * height));
}

// Mutator functions
void Patient::setName(string n)
{
	name = n;
}
void Patient::setSex(string s)
{
	sex = s;
}
void Patient::setHeight(int h)
{
	height = h;
}
void Patient::setWeight(double w)
{
	weight = w;
}