#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>

class GUI : public QWidget {
private:
	Service& service;
	//grahical elements
	QListWidget* victimListWidget;
	QLineEdit* fileLocationLineEdit, *nameVictimLineEdit, * placeOfOriginLineEdit, * ageVictimLineEdit, * photoLinkVictimLineEdit;
	QPushButton* fileLocationButton, *  addVictimButton, * deleteVictimButton, * updateVictimButton, *chartButton;
public:
	GUI(Service& _service);
private:
	void initializeGUI();
	void populateListOfVictims();
	void makeConnectionBetweenSignalsAndSlots();

	int getSelectedIndexFromList() const; 
	void addVictim();
	void deleteVictim();
	void updateVictim();
	void setFileLocation();
	void showChart();
};

