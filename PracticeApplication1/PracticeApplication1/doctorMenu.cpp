#include "doctorMenu.h"
#include "Patient.h"

doctorMenu::doctorMenu()
{
}

doctorMenu::~doctorMenu()
{
}


// Menu Display
int doctorMenu::displayMainMenu()
{
	int menuChoice;
	bool repeat = true;

	do
	{
		cout << "Welcome to doctor's Assistant! Please select from the following options below:" << endl <<
			"\t1. View Patient Information" << endl <<
			"\t2. Modify Patient Information" << endl <<
			"\t3. Add Patient" << endl <<
			"\t4. Remove Patient" << endl <<
			"\t0. Quit program" << endl << endl;

		cin >> menuChoice;
		cin.get();

		switch (menuChoice) 
		{
		case(1):
			cout << endl;
			displayInfo();
			break;
		case(2):
			cout << endl;
			displayMPIMenu();
			break;
		case(3):
			cout << endl;
			addPatient();
			break;
		case(4):
			cout << endl;
			removePatient();
			break;
		case(0):
			repeat = false;
			return 0;
		default:
			cout << "Invalid selection. ";
			break;
		}
	} while (repeat == true);
}
void doctorMenu::displayMPIMenu()
{
	int patientChoice;
	int menuChoice;
	int size = patientVector.size();

	cout << "Modify Patient Information" << endl;
	cout << "Which patient would you like to modify?" << endl;

	// Display all Patients
	for (int index = 0; index < size; index++)
	{
		cout << '\t' << (index + 1) << ". " << patientVector[index].getName() << endl;
	}
	cout << "\t0. Return to last page" << endl;
	cin >> patientChoice;
	cin.get();

	if (patientChoice == 0)
		return;
	else
	{
		patientChoice -= 1;
		cout << "Currently modifying: " << patientVector[patientChoice].getName() << endl <<
			"\t1. Edit Name" << endl <<
			"\t2. Edit Sex" << endl <<
			"\t3. Edit Height" << endl <<
			"\t4. Edit Weight" << endl <<
			"\t0. return to Patient List" << endl;
		cin >> menuChoice;
		cin.get();

		switch (menuChoice) 
		{
		case(1):
			cout << endl;
			editName(patientChoice);
			break;
		case(2):
			cout << endl;
			editSex(patientChoice);
			break;
		case(3):
			cout << endl;
			editHeight(patientChoice);
			break;
		case(4):
			cout << endl;
			editWeight(patientChoice);
			break;
		case(0):
			cout << endl;
			return;
		default:
			cout << "Invalid Selection" << endl << endl;
			return;
		}
	}
}


// Patient modification
void doctorMenu::addPatient()
{
	// Variable list
	string name, sex;
	char repeatyn;
	int height;
	double weight;
	bool repeat = true;

	// Do while loops allows user to enter one or more Patients into the vector
	do {
		cout << "Please enter the patient's name: ";
		getline(cin, name);
		cout << "Please enter the patient's sex: ";
		getline(cin, sex);
		cout << "Please enter the patient's height: ";
		cin >> height;
		cout << "Please enter the patient's weight: ";
		cin >> weight;

		// Creates new Patient with user information then pushes it to the back of the vector
		Patient newPatient(name, sex, height, weight);
		patientVector.push_back(newPatient);

		cout << "Patient added!" << endl << endl;
		cout << "Would you like to enter another patient? Y/N: ";
		cin >> repeatyn;
		cin.get();
		if (toupper(repeatyn) == 'N')
		{
			repeat = false;
		}
	} while (repeat == true);

	cout << endl;

	// Returns to Main Menu (exit stack) once user is done inputting Patients
	return;
}

void doctorMenu::removePatient()
{
	int patientChoice;
	int size = patientVector.size();

	// Display all Patients stored in system
	cout << "Please enter the name of the patient you would like to remove:\n";
	for (int index = 0; index < size; index++)
	{
		cout << '\t' << (index + 1) << ". " << patientVector[index].getName() << endl;
	}
	cout << "\t0. Exit" << endl;
	cin >> patientChoice;
	cin.get();

	if (patientChoice == 0)
		return;
	else
	{
		// If the user chooses to remove a patient, the number representing the patient (patientChoice) is lowered by 1 (to match indexes)
		// And then the corresponding vector index is removed. Default constructor deletes Patient object associated.
		patientChoice -= 1;
		patientVector[patientChoice].~Patient();
		patientVector.erase(patientVector.begin()+patientChoice);
	}

	return;
}

void doctorMenu::displayInfo()
{
	int patientChoice;
	char mChoice;
	int size = patientVector.size();
	do
	{
		cout << endl << "Please enter the name of the patient whose information you would like to view:" << endl;
		for (int index = 0; index < size; index++)
		{
			cout << '\t' << (index + 1) << ". " << patientVector[index].getName() << endl;
		}
		cout << "\t0. Exit" << endl;
		cin >> patientChoice;
		cin.get();

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (patientChoice == 0) 
		{
			return;
		}
		else if (patientChoice > size || patientChoice < 0)
		{
			cout << "\nInvalid selection. \n\n";
			return;
		}

			// Display selected Patient's information
		cout << "Patient name:\t" << patientVector[patientChoice - 1].getName() << endl <<
			"Patient Sex:\t" << patientVector[patientChoice - 1].getSex() << endl <<
			"Patient Height:\t" << patientVector[patientChoice - 1].getHeight() << endl <<
			"Patient Weight:\t" << patientVector[patientChoice - 1].getWeight() << endl <<
			"Patient BMI:\t" << patientVector[patientChoice - 1].getBMI() << endl;

	
		cout << endl << "Would you like to view another Patient's information? Y/N ";
		cin >> mChoice;
		cin.get();
		cout << endl;


		if (toupper(mChoice) == 'N')
			return;
		else if (toupper(mChoice == 'Y'))
			break;
		else
			cout << "Invalid Selection.\n";
	} while (mChoice != 'Y' && mChoice != 'N');
}

void doctorMenu::editName(int patientChoice)
{
	string choice;
	cout << "Enter patient's name: ";
	getline(cin, choice);
	// patient should represent current patient since it is global variable and was last called in MPI menu to get to this function
	patientVector[patientChoice].setName(choice);
	cout << "\nPatient name added.\n";
	return;
}

void doctorMenu::editSex(int patientChoice)
{
	int choice;
	cout << "\t1. Male" << endl <<
		"\t2. Female" << endl <<
		"\t3. Other" << endl;
	cout << "Enter patient's Sex: ";
	cin >> choice;
	cin.get();

	// patient should represent current patient since it is global variable and was last called in MPI menu to get to this function
	switch (choice) {
	case(1):
		patientVector[patientChoice].setSex("Male");
		break;
	case(2):
		patientVector[patientChoice].setSex("Female");
		break;
	case(3):
		patientVector[patientChoice].setSex("Other");
		break;
	default:
		cout << "That is not a valid selection. Returning to Modify Patient Information Menu." << endl;
		break;
	}

	cout << "\nPatient Sex added.\n";
	return;
}

void doctorMenu::editHeight(int patientChoice)
{
	int height = 0;
	cout << "Please enter the patient's height in inches: ";
	cin >> height;
	cin.get();

	patientVector[patientChoice].setHeight(height);
	cout << "Patient height added.";
	return;
}

void doctorMenu::editWeight(int patientChoice)
{
	double weight = 0.0;
	cout << "Please enter the patient's weight in pounds: ";
	cin >> weight;
	cin.get();

	patientVector[patientChoice].setWeight(weight);
	cout << "\n\nPatient weight added.\n\n";
	return;
}

