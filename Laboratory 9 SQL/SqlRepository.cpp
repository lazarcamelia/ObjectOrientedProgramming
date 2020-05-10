#include "SqlRepository.h"
#include "Exceptions.h"
#include "sqlite3.h"
#include <algorithm>

SqlRepository::SqlRepository() {
	this->positionOfTheCurrent = 0;
	this->fileLocation = "";
}

SqlRepository::SqlRepository(ListStorage* myListStorage, const string& fileLocation) {
	this->positionOfTheCurrent = 0;
	this->myListStorage = myListStorage;
	this->fileLocation = fileLocation;
}

vector<Victim> SqlRepository::readData() {
	sqlite3* victimDatabase;
	int successful;
	std::vector<Victim*> victims;
	Victim* victim;
	
	successful = sqlite3_open(this->fileLocation.c_str(), &victimDatabase);
	if (successful != 0)
		throw StoringException("Could not open database!");
	
	std::string SqlToGetElements = "SELECT * FROM Victims";
	char* SqlErrorMessage;
	
	auto Func = [](void* VoidTemporaryStorage, int ColumnCount, char** Row, char** Column) {
		const int nameOfVictim = 0, placeOfOrigin = 1, age = 2, photolink = 3;
		std::vector<Victim*>* victims = (std::vector<Victim*>*) VoidTemporaryStorage;
		Victim* victim = new Victim(std::string(Row[nameOfVictim]), std::string(Row[placeOfOrigin]), std::stoi(std::string(Row[age])), std::string(Row[photolink]));
		victims->push_back(victim);
		return 0; 
	};

	successful = sqlite3_exec(victimDatabase, SqlToGetElements.c_str(), Func, &victims, &SqlErrorMessage);

	sqlite3_close(victimDatabase);

	if (successful != SQLITE_OK)
		throw StoringException((std::string("Could not retrieve data!") + std::string(SqlErrorMessage)).c_str());

	vector<Victim> staticVictims;

	for (auto it = victims.begin(); it != victims.end(); it++) {
		victim = *it;
		Victim staticVictim = Victim(victim->getName(), victim->getPlaceOfOrigin(), victim->getAge(), victim->getPhotoLink());
		delete victim;
		staticVictims.push_back(staticVictim);
	}

	return staticVictims;
}

void SqlRepository::addVictim(const Victim& victim) {
	sqlite3* victimDatabase;
	int successful;

	successful = sqlite3_open(this->fileLocation.c_str(), &victimDatabase);
	if (successful != 0)
		throw StoringException("Could not open database!");
	

	std::string sqlCommandToAddVictim;
	sqlCommandToAddVictim = "INSERT INTO Victims (Name, PlaceOfOrigin, Age, Photolink) VALUES('";
	sqlCommandToAddVictim += victim.getName() + "', '" + victim.getPlaceOfOrigin() + "', '" + std::to_string(victim.getAge()) + "', '" + victim.getPhotoLink() + "');";
	char* SqlErrorMessage;
	successful = sqlite3_exec(victimDatabase, sqlCommandToAddVictim.c_str(), NULL, 0, &SqlErrorMessage);
	sqlite3_close(victimDatabase);

	if (successful != SQLITE_OK)
		throw StoringException((std::string("Could not add to database! ") + std::string(SqlErrorMessage)).c_str());
}

void SqlRepository::updateVictim(const Victim& victim) {
	sqlite3* Database;
	int successful;
	successful = sqlite3_open(this->fileLocation.c_str(), &Database);
	if (successful != 0)
	{
		throw StoringException("Could not open database!");
	}
	std::string sqlCommandToUpdateVictim;
	sqlCommandToUpdateVictim = "UPDATE Victims SET PlaceOfOrigin='";
	sqlCommandToUpdateVictim += victim.getPlaceOfOrigin() + "', Age='" + std::to_string(victim.getAge()) + "', Photolink='" + victim.getPhotoLink() + "' WHERE Name = '" +  victim.getName() + "';";


	char* SqlErrorMessage;
	successful = sqlite3_exec(Database, sqlCommandToUpdateVictim.c_str(), NULL, 0, &SqlErrorMessage);
	sqlite3_close(Database);

	if (successful != SQLITE_OK)
		throw StoringException((std::string("Could not update database! ") + std::string(SqlErrorMessage)).c_str());
}

void SqlRepository::deleteVictim(const Victim& victim) {
	sqlite3* victimDatabase;
	int successfull;
	successfull = sqlite3_open(this->fileLocation.c_str(), &victimDatabase);
	if (successfull != 0)
		throw StoringException("Could not open database!");

	std::string sqlCommandToDeleteVictim = "DELETE FROM Victims WHERE Name='" + victim.getName() + "';";
	char* SqlErrorMessage;
	
	successfull = sqlite3_exec(victimDatabase, sqlCommandToDeleteVictim.c_str(), NULL, 0, &SqlErrorMessage);
	
	sqlite3_close(victimDatabase);
	if (successfull != SQLITE_OK)
		throw StoringException((std::string("Could not delete from database! ") + std::string(SqlErrorMessage)).c_str());
	delete SqlErrorMessage;
}

bool SqlRepository::isVictim(const Victim& victim) {
	vector<Victim> allVictims = this->readData();

	for (auto readVictim : allVictims) {
		if (readVictim == victim)
			return true;
	}
	return false;
}

bool SqlRepository::isVictimInAssistantFile(const Victim& victim) {
	return this->myListStorage->findVictim(victim);
}

std::vector<Victim> SqlRepository::getAllVictims() {
	vector<Victim> allVictims = this->readData();

	return allVictims;
}

Victim SqlRepository::getNextFile() {
	vector<Victim> allVictims = this->readData();

	if (this->positionOfTheCurrent == allVictims.size())
		this->positionOfTheCurrent = 0;
	return allVictims[this->positionOfTheCurrent++];
}

void SqlRepository::addVictimToAssistantFile(const Victim& victim) {
	vector<Victim> victims = this->readData();

	for (auto victimInAllVictims : victims)
		if (victimInAllVictims == victim) {
			this->myListStorage->addVictim(victimInAllVictims);
			break;
		}
}

std::vector<Victim> SqlRepository::getAllAssistantSavedFiles() {
	return this->myListStorage->getAll();
}

void SqlRepository::setFileLocation(const string& fileLocation)
{
	this->fileLocation = fileLocation;
}

void SqlRepository::openMyList() {
	this->myListStorage->open();
}