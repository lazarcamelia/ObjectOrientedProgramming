#include "CsvStorage.h"
#include <fstream>
#include <Windows.h>

CsvStorage::CsvStorage(const std::string& path) {
	this->path = path;
}

vector<Victim> CsvStorage::readData() {
	 vector<Victim> assistantSavedFiles;

	 std::ifstream fin(this->path);
	 Victim victim;

	 while (fin >> victim) {
		 assistantSavedFiles.push_back(victim);
	 }
	 fin.close();
	

	 return assistantSavedFiles;
}

void CsvStorage::writeData(vector<Victim> assistantListOfFiles) {
	std::ofstream fout(this->path);

	for (auto victim : assistantListOfFiles) {
		fout << victim << "\n";
	}

	fout.close(); 
}

void CsvStorage::setPath(const string& path) {
	this->path = path;
}

bool CsvStorage::findVictim(const Victim& victimToBeFound) {
	vector<Victim> assistantListOfFiles = this->readData();

	for (auto victim : assistantListOfFiles) {
		if (victim == victimToBeFound)
			return true;
	}
	return false;
}

void CsvStorage::addVictim(const Victim& victim) {
	vector<Victim> assistantListOfFiles = this->readData();
	
	assistantListOfFiles.push_back(victim);

	this->writeData(assistantListOfFiles);
}

vector<Victim> CsvStorage::getAll()
{
	return this->readData();
}

void CsvStorage::open() {
	string programPath = "\"C:\\Program Files\\Microsoft Office\\Office16\\EXCEL.EXE\" " + path;
	system(programPath.c_str());
}
