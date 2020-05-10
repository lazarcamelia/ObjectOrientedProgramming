#include "HtmlStorage.h"
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

HtmlStorage::HtmlStorage(const std::string& path) {
	this->path = path;
}

vector<Victim> HtmlStorage::readData() {
	std::ifstream fin(this->path);
	std::string lineInFile;

	Victim victimRead;

	int garbageLines = 4;

	vector<Victim> allVictims = vector<Victim>();

	string name, age, photoLink, placeOfOrigin;

	while (getline(fin, lineInFile))
	{
		if (lineInFile.substr(0, 7) == "\t\t\t<td>")
		{
			if (garbageLines)
				garbageLines--;
			else
			{
				int StartPosition = lineInFile.find('>') + 1;
				name = lineInFile.substr(StartPosition, lineInFile.rfind('<') - StartPosition);
				getline(fin, lineInFile);
				placeOfOrigin = lineInFile.substr(StartPosition, lineInFile.rfind('<') - StartPosition);
				getline(fin, lineInFile);
				age = lineInFile.substr(StartPosition, lineInFile.rfind('<') - StartPosition);
				getline(fin, lineInFile);
				photoLink = lineInFile.substr(StartPosition, lineInFile.rfind('<') - StartPosition);
				victimRead = Victim(name, placeOfOrigin, stoi(age), photoLink);
				allVictims.push_back(victimRead);
			}
		}
	}
	fin.close();

	return allVictims;
}

void HtmlStorage::writeData(vector<Victim> assistantListOfFiles) {
	std::string fileContent = "";
	fileContent += "<!DOCTYPE html>\n";
	fileContent += "<html>\n";
	fileContent += "\t<head>\n";
	fileContent += "\t\t<title>Assistant files of victims</title>\n";
	fileContent += "\t</head>\n";
	fileContent += "\t<body>\n";
	fileContent += "\t\t<table border=\"1\">\n";
	fileContent += "\t\t<tr>\n";
	fileContent += "\t\t\t<td>Name</td>\n";
	fileContent += "\t\t\t<td>Place of origin</td>\n";
	fileContent += "\t\t\t<td>Age</td>\n";
	fileContent += "\t\t\t<td>Photograph</td>\n";
	fileContent += "\t\t</tr>\n";
	for (auto victim : assistantListOfFiles)
	{
		fileContent += "\t\t<tr>\n";
		fileContent += "\t\t\t<td>" + victim.getName() + "</td>\n";
		fileContent += "\t\t\t<td>" + victim.getPlaceOfOrigin() + "</td>\n";
		fileContent += "\t\t\t<td>" + std::to_string(victim.getAge()) + "</td>\n";
		fileContent += "\t\t\t<td>" + victim.getPhotoLink() + "</td>\n";
		fileContent += "\t\t</tr>\n";
	}
	fileContent += "\t\t</table>\n";
	fileContent += "\t</body>\n";
	fileContent += "</html>\n";
	
	std::ofstream fout(this->path);

	fout << fileContent;

	fout.close();
}

void HtmlStorage::setPath(const string& path) {
	this->path = path;
}

bool HtmlStorage::findVictim(const Victim& victimToBeFound) {
	vector<Victim> assistantListOfFiles = this->readData();

	for (auto victim : assistantListOfFiles) {
		if (victim == victimToBeFound)
			return true;
	}
	return false;
}

void HtmlStorage::addVictim(const Victim& victim) {
	vector<Victim> assistantListOfFiles = this->readData();

	assistantListOfFiles.push_back(victim);

	this->writeData(assistantListOfFiles);
}

vector<Victim> HtmlStorage::getAll() {
	return this->readData();
}

void HtmlStorage::open() {
	string programPath = "\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\" " + this->path;
	system(programPath.c_str());
}
