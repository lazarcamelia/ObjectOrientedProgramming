#include "FileRepository.h"
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

FileRepository::FileRepository(const std::string& filename) {
	this->filename = filename;
	this->positionOfTheCurrent = 0;
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
	auto it = find(this->assistantFiles.begin(), this->assistantFiles.end(), victim);

	if (it != this->assistantFiles.end())
		return true;
	return false;
}

vector<Victim> FileRepository::getAllVictims() {
	vector<Victim> victims = this->readFromFile();
	return victims;
}

Victim FileRepository::getNextFile() {
	vector<Victim> victims = this->readFromFile();
	if (this->positionOfTheCurrent >= victims.size())
		this->positionOfTheCurrent = 0;
	return victims[this->positionOfTheCurrent++];
}

void FileRepository::addVictimToAssistantFile(const Victim& victim) {
	vector<Victim> victims = this->readFromFile();
	
	for (auto victimInAllVictims : victims)
		if (victimInAllVictims == victim) {
			this->assistantFiles.push_back(victimInAllVictims);
			break;
		}
}

vector<Victim> FileRepository::getAllAssistantSavedFiles() {
	return this->assistantFiles;
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
	std::string victim;

	ifstream fin;
	fin.open(this->filename);

	vector<std::string> Victims;
	vector<Victim> allVictims;
	Victim newReadVictim;

	while (fin >> victim) {
		Victims = this->convertLine(victim, ',');
		newReadVictim = Victim(Victims[0], Victims[1], stoi(Victims[2]), Victims[3]);
		allVictims.push_back(newReadVictim);
	}

	fin.close();
	return allVictims;
}

void FileRepository::writeToFile(std::vector<Victim> victims) {
	ofstream fout(this->filename);
	for (auto victim : victims) {
		fout << victim.toString() << "\n";
	}

	fout.close();
}
