#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "Victim.h"
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>


using namespace std;

Victim::Victim(std::string name) {
	this->name = name;
	this->placeOfOrigin = "";
	this->age = 0;
	this->photoLink = "";
}

Victim::Victim(const std::string& name, const std::string& placeOfOrigin, int age, std::string photo) {
	this->name = name;
	this->placeOfOrigin = placeOfOrigin;
	this->age = age;
	this->photoLink = photo;
}

bool Victim::operator==(const Victim& victim)
{
	if (this->name == victim.name)
		return true;
	return false;
}

std::string Victim::toString()
{
	return this->getName() + "," + this->getPlaceOfOrigin() + "," + std::to_string(this->getAge()) + "," + this->getPhotoLink();
}

std::string Victim::getName() const {
	return this->name;
}

std::string Victim::getPlaceOfOrigin() const {
	return this->placeOfOrigin;
}

int Victim::getAge() const {
	return this->age;
}

std::string Victim::getPhotoLink() const {
	return this->photoLink;
}

std::ostream& operator<<(std::ostream& outputStream, Victim& victim)
{
	// TODO: insert return statement here
	outputStream << victim.getName() << "," << victim.getPlaceOfOrigin() << "," << victim.getAge() << "," << victim.getPhotoLink() << "\n";
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Victim& victim)
{
	// TODO: insert return statement here
	std::string victimRead;
	inputStream >> victimRead;
	stringstream stringVictim(victimRead);
	std::string fieldOfVictim;
	vector<std::string> victimAtributes;
	char Delimiter = ',';

	while (getline(stringVictim, fieldOfVictim, Delimiter))
		victimAtributes.push_back(fieldOfVictim);

	if (victimAtributes.size() == 0)
		return inputStream;

	victim = Victim(victimAtributes[0], victimAtributes[1], stoi(victimAtributes[2]), victimAtributes[3]);
	return inputStream;
}