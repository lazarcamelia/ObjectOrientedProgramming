#pragma once

#include "Service.h"
#include <iostream>

class UI {
private:
	Service* service;
public:
	UI();

	void run();

private:
	//run the menu in Mode A
	int runModeA();
	//run the menu in Mode B
	int runModeB();

	string readFileLocation();

	string readMyListFileLocation();

	//menu for the add command in mode A
	void addCommandMenu();
	//menu for update command in mode A
	void updateCommandMenu();
	//menu for delete command in mode A
	void deleteCommandMenu();
	//menu for list command in mode A
	void listCommandMenu();
	
	//menu for next command in menu B
	void nextCommandMenuB();
	//menu for save command in menu B
	void saveCommandMenuB();
	//menu for filtered list command in menu B
	void listCommandMenuB();
	//menu for printing assistant list in menu B
	void mylistCommandMenuB();
};