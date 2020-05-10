#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include "Victim.h"
#include <vector>
#include <string>

using namespace std;

GUI::GUI(Service& _service) : service{ _service } {
	this->initializeGUI();
	this->populateListOfVictims();
	this->makeConnectionBetweenSignalsAndSlots();
}

void GUI::initializeGUI() {
	this->fileLocationLineEdit = new QLineEdit();
	this->fileLocationButton = new QPushButton("Set file location");
	this->victimListWidget = new QListWidget();
	this->nameVictimLineEdit = new QLineEdit();
	this->placeOfOriginLineEdit = new QLineEdit();
	this->ageVictimLineEdit = new QLineEdit();
	this->photoLinkVictimLineEdit = new QLineEdit();
	this->addVictimButton = new QPushButton("Add victim");
	this->deleteVictimButton = new QPushButton("Delete victim");
	this->updateVictimButton = new QPushButton("Update victim");

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	//add the filelocation layout
	QFormLayout* fileLocationLayout = new QFormLayout{};
	fileLocationLayout->addRow("File Location",this->fileLocationLineEdit);
	fileLocationLayout->addWidget(this->fileLocationButton);
	mainLayout->addLayout(fileLocationLayout);
	//add the layout for the victims' list
	mainLayout->addWidget(this->victimListWidget);

	//add the layout for victim data
	QFormLayout* victimData = new QFormLayout{};
	victimData->addRow("Name", this->nameVictimLineEdit);
	victimData->addRow("Place of origin", this->placeOfOriginLineEdit);
	victimData->addRow("Age", this->ageVictimLineEdit);
	victimData->addRow("Photolink", this->photoLinkVictimLineEdit);

	mainLayout->addLayout(victimData);

	//adding buttons

	QGridLayout* buttonsLayout = new QGridLayout();

	buttonsLayout->addWidget(this->addVictimButton, 0, 0);
	buttonsLayout->addWidget(this->deleteVictimButton, 0, 1);
	buttonsLayout->addWidget(this->updateVictimButton, 0, 2);
	mainLayout->addLayout(buttonsLayout);
}

void GUI::populateListOfVictims() {
	this->victimListWidget->clear();

	vector<Victim> allVictims = this->service.getAllVictims();

	for (auto victim : allVictims) {
		this->victimListWidget->addItem(QString::fromStdString(victim.toString()));
	}
}

void GUI::makeConnectionBetweenSignalsAndSlots() {
	QObject::connect(this->victimListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndexFromList();

		if (selectedIndex < 0) {
			return;
		}
		Victim victim = this->service.getAllVictims()[selectedIndex];
		this->nameVictimLineEdit->setText(QString::fromStdString(victim.getName()));
		this->placeOfOriginLineEdit->setText(QString::fromStdString(victim.getPlaceOfOrigin()));
		this->ageVictimLineEdit->setText(QString::fromStdString(to_string(victim.getAge())));
		this->photoLinkVictimLineEdit->setText(QString::fromStdString(victim.getPhotoLink()));
	});

	QObject::connect(this->fileLocationButton, &QPushButton::clicked, this, &GUI::setFileLocation);
	QObject::connect(this->addVictimButton, &QPushButton::clicked, this, &GUI::addVictim);
	QObject::connect(this->deleteVictimButton, &QPushButton::clicked, this, &GUI::deleteVictim);
	QObject::connect(this->updateVictimButton, &QPushButton::clicked, this, &GUI::updateVictim); 
}

int GUI::getSelectedIndexFromList() const {
	QModelIndexList selectedIndexes = this->victimListWidget->selectionModel()->selectedIndexes();

	if (selectedIndexes.size() != 0) {
		int selectIndex = selectedIndexes.at(0).row();
		return selectIndex; 
	}
	else {
		this->nameVictimLineEdit->clear();
		this->placeOfOriginLineEdit->clear();
		this->ageVictimLineEdit->clear();
		this->photoLinkVictimLineEdit->clear();
		return -1;
	}
}

void GUI::addVictim() {
	string nameOfVictim = this->nameVictimLineEdit->text().toStdString();
	string placeOfOrigin = this->placeOfOriginLineEdit->text().toStdString();
	int age = stoi(this->ageVictimLineEdit->text().toStdString());
	string photolink = this->photoLinkVictimLineEdit->text().toStdString();

	this->service.addVictim(nameOfVictim, placeOfOrigin, age, photolink);

	this->populateListOfVictims();

	int lastElement = this->service.getAllVictims().size() - 1;
	this->victimListWidget->setCurrentRow(lastElement);
}

void GUI::deleteVictim() {
	string nameOfVictim = this->nameVictimLineEdit->text().toStdString();

	this->service.deleteVictim(nameOfVictim);

	this->populateListOfVictims();

	int lastElement = this->service.getAllVictims().size() - 1;
	this->victimListWidget->setCurrentRow(lastElement);
}

void GUI::updateVictim() {
	string nameOfVictim = this->nameVictimLineEdit->text().toStdString();
	string placeOfOrigin = this->placeOfOriginLineEdit->text().toStdString();
	int age = stoi(this->ageVictimLineEdit->text().toStdString());
	string photolink = this->photoLinkVictimLineEdit->text().toStdString();

	this->service.updateVictim(nameOfVictim, placeOfOrigin, age, photolink);

	this->populateListOfVictims();

	vector<Victim> victims = this->service.getAllVictims();
	
	for (int i = 0; i < victims.size(); i++) {
		if (victims[i].getName() == nameOfVictim) {
			this->victimListWidget->setCurrentRow(i);
			break;
		}
	} 

}

void GUI::setFileLocation() {
	string path = this->fileLocationLineEdit->text().toStdString();

	this->service.setFileLocation(path);

	this->populateListOfVictims();
}
