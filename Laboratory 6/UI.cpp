#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "UI.h"

#include <string>
#include <exception>

using namespace std;

void UI::run() {
	string programMode;
	getline(cin, programMode);
	int typeOfExit;

	while (true) {
		if (!programMode.compare("mode A")) {
			while (true) {
				typeOfExit = runModeA();
				if (typeOfExit == 0)
					return;
				else {
					runModeB();
					return;
				}

			}
		}
		else if (!programMode.compare("mode B")) {
			while (true) {
				typeOfExit = runModeB();
				if (typeOfExit == 0)
					return;
				else {
					runModeA();
					return;
				}
			}
		}
		else if (!programMode.compare("exit"))
			return;
		else {
			getline(cin, programMode);
		}
	}
}

int UI::runModeA() {
	string inputCommand = "";
	while (inputCommand.compare("exit")) {
		try {
			cin >> inputCommand;
			if (!inputCommand.compare(0, 3, "add")) {
				this->addCommandMenu();
			}
			else if (!inputCommand.compare(0, 6, "update")) {
				this->updateCommandMenu();
			}
			else if (!inputCommand.compare(0, 6, "delete")) {
				this->deleteCommandMenu();
			}
			else if (!inputCommand.compare(0, 4, "list")) {
				this->listCommandMenu();
			}
			else if (!inputCommand.compare(0, 4, "mode")) {
				cin >> inputCommand;
				return 1;
			}
		}
		catch (exception) {
			cin.clear();
		}
	}
	if (inputCommand == "exit") {
		cin.clear();
		return 0;
	}
}

int UI::runModeB() {
	string inputCommand = "";

	while (inputCommand != "exit") {
		try {
			cin >> inputCommand;
			if (inputCommand == "next") {
				this->nextCommandMenuB();
			}
			else if (inputCommand == "save") {
				this->saveCommandMenuB();
			}
			else if (inputCommand == "list") {
				this->listCommandMenuB();
			}
			else if (inputCommand == "mylist") {
				this->mylistCommandMenuB();
			}
			else if (inputCommand == "mode") {
				cin >> inputCommand;
				return 1;
			}
		}
		catch (exception) {
			cin.clear();
		}
	}
	if (inputCommand == "exit") {
		cin.clear();
		return 0;
	}
}

void UI::addCommandMenu() {
	exception invalid_exception;
	string name, placeOfOrigin, photoLink, ignoreChar;
	int age;
	cin >> name;
	name.pop_back();
	cin >> placeOfOrigin;
	placeOfOrigin.pop_back();
	cin >> age;
	if (age == 0) {
		throw exception("Invalid input!");
	}
	cin >> ignoreChar;
	cin >> photoLink;
	this->service.addVictim(name, placeOfOrigin, age, photoLink);
}

void UI::updateCommandMenu() {
	string newName, newPlaceOfOrigin, newPhotoLink, ignoreChar;
	int newAge;
	cin >> newName;
	newName.pop_back();
	cin >> newPlaceOfOrigin;
	newPlaceOfOrigin.pop_back();
	cin >> newAge;
	if (newAge == 0) {
		throw exception("Invalid input!");
	}
	cin >> ignoreChar;
	cin >> newPhotoLink;
	this->service.updateVictim(newName, newPlaceOfOrigin, newAge, newPhotoLink);
}

void UI::deleteCommandMenu() {
	string name;
	cin >> name;

	this->service.deleteVictim(name);
}

void UI::listCommandMenu() {
	DynamicVector<Victim> allVictims = this->service.getAllVictims();

	for (int i = 0; i < allVictims.getSize(); i++) {
		Victim victim = allVictims.getElementOnPosition(i);
		cout << victim.toString() << "\n";
	}
}

void UI::nextCommandMenuB() {
	Victim victim = this->service.getTheNextFile();
	
	cout << victim.toString() << "\n";
}

void UI::saveCommandMenuB() {
	string nameOfVictim;
	cin >> nameOfVictim;
	this->service.saveVictimToAssistantListOfVictims(nameOfVictim);
}

void UI::listCommandMenuB() {
	string placeOfOrigin;
	int age;
	cin >> placeOfOrigin;
	placeOfOrigin.pop_back();
	cin >> age;

	if (age == 0)
		throw exception("Invalid age!");
	DynamicVector<Victim> filteredListOfVictims = this->service.getFiteredListOfVictimFiles(placeOfOrigin, age);

	for (int i = 0; i < filteredListOfVictims.getSize(); i++) {
		Victim victim = filteredListOfVictims.getElementOnPosition(i);
		cout << victim.toString() << "\n";
	}
}

void UI::mylistCommandMenuB() {
	DynamicVector<Victim> assistantListOfVictims = this->service.getTheAssistantListOfVictims();

	for (int i = 0; i < assistantListOfVictims.getSize(); i++) {
		Victim victim = assistantListOfVictims.getElementOnPosition(i);
		cout << victim.toString() << "\n";
	}
}
