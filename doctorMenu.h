#pragma once
#ifndef DOCTORMENU_H
#define DOCTORMENU_H

#include <iostream>
#include <vector>
#include "Patient.h"

using namespace std;

class doctorMenu
{
public:
	doctorMenu();
	// doctorMenu - Default constructor - no actions

	~doctorMenu();
	// ~doctorMenu - Defualt deconstructor


	/*******************************************
	MENU DISPLAY - Displays different menus
	********************************************/

	int displayMainMenu();
	// displayMainMenu - Displays main menu

	void displayMPIMenu();
	// displayMPIMenu - Displays Modify Patient Information menu

	void displayInfo();
	// displayInfo


	/*******************************************
	PATIENT MODIFICATIONS
	********************************************/

	void addPatient();
	// addPatient - adds a patient to end of vector

	void removePatient();
	// removePatient - removes a patient from the vector and deletes index

	void editName(int);
	// editName - Changes the name of the patient
	// @param int - The patient number (correlates to vector index)

	void editSex(int);
	// editSex - Changes the sex of the patient
	// @param int - The patient number (correlates to vector index)

	void editHeight(int);
	// editHeight - Changes the height of the patient
	// @param int - The patient number (correlates to vector index)

	void editWeight(int);
	// editWeight - Changes the weight of the patient
	// @param int - The patient number (correlates to vector index)


private:
	// Menu choice
	Patient currentPatient;
	vector<Patient> patientVector;
};

#endif
