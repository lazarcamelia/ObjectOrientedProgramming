#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "UI.h"
#include "Exceptions.h"

#include <string>
#include <exception>
#include <cstring>
#include <sstream>
#include <regex>


using namespace std;

UI::UI() {
	this->service = NULL;
}

void UI::run() {
	string input;

	int typeOfExit;

	string myListPath = "";
	string filesPath = "";

	ListStorage* storageType = nullptr;

	while (true) {
		cin >> input;
		if (myListPath != "" && filesPath != "") {
			smatch foundMatches;
			regex extension(".csv");
			ListStorage* storageType = nullptr;


			if (regex_search(myListPath, foundMatches, extension)) {
				storageType = new CsvStorage(myListPath);
				FileRepository* repo = new FileRepository(storageType, filesPath);
				this->service = new Service(repo);
			}
			else {
				storageType = new HtmlStorage(myListPath);
				FileRepository* repo = new FileRepository(storageType, filesPath);
				this->service = new Service(repo);
			}
		}

		if (input == "fileLocation")
			filesPath = this->readFileLocation();
		else if (input == "mylistLocation") {
			myListPath = this->readMyListFileLocation();
		}
		else if (input == "mode") {
			cin >> input;
			if (input == "A") {
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
			else {
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
		}
		else if (input == "exit")
			return;
		else {
			cin >> input;
		}
	}
}

string UI::readFileLocation() {
	stringstream input;
	string fileLocation;
	cin.get();
	getline(cin, fileLocation);
	return fileLocation;
}

string UI::readMyListFileLocation() {
	string Location;
	cin.get();
	getline(cin, Location);

	return Location;
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
		catch (StoringException& exception) {
			cout << exception.what() << "\n";
			cin.clear();
		}
		catch (ValidatorException& exception) {
			cout << exception.what() << "\n";
			cin.clear();
		}
		catch (exception) {
			cin.clear();
		}
	}
	if (inputCommand == "exit") {
		cin.clear();
		return 0;
	}
	return 0;
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
		catch (StoringException& exception) {
			cout << exception.what() << "\n";
			cin.clear();
		}
		catch (ValidatorException& exception) {
			cout << exception.what() << "\n";
			cin.clear();
		}
		catch (exception) {
			cin.clear();
		}
	}
	if (inputCommand == "exit") {
		cin.clear();
		return 0;
	}
	return 0;
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
	cin >> ignoreChar;
	cin >> photoLink;
	this->service->addVictim(name, placeOfOrigin, age, photoLink);
}

void UI::updateCommandMenu() {
	string newName, newPlaceOfOrigin, newPhotoLink, ignoreChar;
	int newAge;
	cin >> newName;
	newName.pop_back();
	cin >> newPlaceOfOrigin;
	newPlaceOfOrigin.pop_back();
	cin >> newAge;
	cin >> ignoreChar;
	cin >> newPhotoLink;
	this->service->updateVictim(newName, newPlaceOfOrigin, newAge, newPhotoLink);
}

void UI::deleteCommandMenu() {
	string name;
	cin >> name;

	this->service->deleteVictim(name);
}

void UI::listCommandMenu() {
	std::vector<Victim> allVictims = this->service->getAllVictims();

	for (auto victim : allVictims) {
		cout << victim.toString() << "\n";
	}
}

void UI::nextCommandMenuB() {
	Victim victim = this->service->getTheNextFile();
	
	cout << victim.toString() << "\n";
}

void UI::saveCommandMenuB() {
	string nameOfVictim;
	cin >> nameOfVictim;
	this->service->saveVictimToAssistantListOfVictims(nameOfVictim);
}

void UI::listCommandMenuB() {
	string placeOfOrigin;
	int age;
	cin >> placeOfOrigin;
	placeOfOrigin.pop_back();
	cin >> age;

	vector<Victim> filteredListOfVictims = this->service->getFiteredListOfVictimFiles(placeOfOrigin, age);

	for (auto victim :  filteredListOfVictims) {
		cout << victim.toString() << "\n";
	}
}

void UI::mylistCommandMenuB() {
	this->service->openMyList();
	std::vector<Victim> assistantListOfVictims = this->service->getTheAssistantListOfVictims();

	for (auto victim : assistantListOfVictims) {
		cout << victim.toString() << "\n";
	}
}
