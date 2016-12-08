#pragma once
#include <stdio.h>
#include <string>

using namespace std;

#ifndef PATIENT_H
#define PATIENT_H

class Patient
{
public:
	// Default constructor
	Patient();

	// Overloaded constructor
	Patient(string, string, int, double);

	// Default destructor
	~Patient();

	// Accessor functions
	string getName() const;
	string getSex() const;
	int getHeight() const;
	double getWeight() const;
	double getBMI() const;

	// Mutator functions
	void setName(string);
	void setSex(string);
	void setHeight(int);
	void setWeight(double);


private:
	// member values
	string name;
	string sex;
	int height;
	double weight;
};

#endif