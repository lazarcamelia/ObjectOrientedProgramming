#include "FileRepository.h"
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

FileRepository::FileRepository() {
	this->positionOfTheCurrent = 0;
	this->fileLocation = "";
}

FileRepository::FileRepository(ListStorage* myListStorage, const string& fileLocation)
{
	this->positionOfTheCurrent = 0;
	this->myListStorage = myListStorage;
	this->fileLocation = fileLocation;
}

void FileRepository::addVictim(const Victim& victim) {
	vector<Victim> victims = this->readFromFile();
	victims.push_back(victim);
	this->writeToFile(victims);
}

void FileRepository::updateVictim(const Victim& victim) {
	vector<Victim> victims = this->readFromFile();

	vector<Victim>::iterator it = find(victims.begin(), victims.end(), victim);

	if (it != victims.end()) {
		*it = victim;
	}

	this->writeToFile(victims);
	
}

void FileRepository::deleteVictim(const Victim& victim) {
	vector<Victim> victims = this->readFromFile();

	auto it = find(victims.begin(), victims.end(), victim);

	if (it != victims.end()) {

		victims.erase(it);
	}

	this->writeToFile(victims);
}

bool FileRepository::isVictim(const Victim& victim) {
	vector<Victim> victims = this->readFromFile();
	
	auto it = find(victims.begin(), victims.end(), victim);

	if (it != victims.end())
		return true;
	return false;
}

bool FileRepository::isVictimInAssistantFile(const Victim& victim) {
	return this->myListStorage->findVictim(victim);
}

vector<Victim> FileRepository::getAllVictims() {
	vector<Victim> victims = this->readFromFile();
	return victims;
}

Victim FileRepository::getNextFile() {
	vector<Victim> victims = this->readFromFile();
	if (this->positionOfTheCurrent == victims.size())
		this->positionOfTheCurrent = 0;
	return victims[this->positionOfTheCurrent++];
}

void FileRepository::addVictimToAssistantFile(const Victim& victim) {
	vector<Victim> victims = this->readFromFile();
	
	for (auto victimInAllVictims : victims)
		if (victimInAllVictims == victim) {
			this->myListStorage->addVictim(victimInAllVictims);
			break;
		}
}

vector<Victim> FileRepository::getAllAssistantSavedFiles() {
	return this->myListStorage->getAll();
}

void FileRepository::setFileLocation(const string& fileLocation)
{
	this->fileLocation = fileLocation;
}

void FileRepository::openMyList() {
	this->myListStorage->open();
}

vector<string> FileRepository::convertLine(std::string Victim, char Delimiter)
{
	stringstream stringVictim(Victim);
	std::string fieldOfVictim;
	vector<std::string> victim;

	while (getline(stringVictim, fieldOfVictim, Delimiter))
		victim.push_back(fieldOfVictim);
	return victim;
}

std::vector<Victim> FileRepository::readFromFile() {
	ifstream fin;
	fin.open(this->fileLocation);

	vector<Victim> allVictims;
	Victim newReadVictim;

	while (fin >> newReadVictim) {
		allVictims.push_back(newReadVictim);
	}

	fin.close();
	return allVictims;
}

void FileRepository::writeToFile(std::vector<Victim> victims) {
	ofstream fout(this->fileLocation);
	for (auto victim : victims) {
		fout << victim << "\n";
	}

	fout.close();
}

