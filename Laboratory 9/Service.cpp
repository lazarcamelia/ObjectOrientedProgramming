#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>
#include <algorithm>
#include <vector>
#include "Service.h"
#include "Exceptions.h"
#include "Validator.h"

using namespace std;

vector<Victim> Service::getAllVictims() const
{
	return this->repo->getAllVictims();
}

void Service::addVictim(const string& name, const string& placeOforigin, int age, const string& photoLink) {
	Victim victimToBeAddedToRepo = Victim(name, placeOforigin, age, photoLink);
	Validator::validateVictim(victimToBeAddedToRepo);
	this->repo->addVictim(victimToBeAddedToRepo);
}

void Service::deleteVictim(const string& name) {
	Victim victimToBeDeleted = Victim(name);
	Validator::validateVictim(name);
	if (this->repo->isVictim(victimToBeDeleted))
		this->repo->deleteVictim(victimToBeDeleted);
	else
		throw StoringException("Invalid input!");
}

void Service::updateVictim(const string& name, const string& newPlaceOforigin, int newAge, const string& newPhotoLink) {
	Victim victimToBeUpdated = Victim(name, newPlaceOforigin, newAge, newPhotoLink);
	Validator::validateVictim(victimToBeUpdated);
	if (this->repo->isVictim(victimToBeUpdated))
		this->repo->updateVictim(victimToBeUpdated);
	else
		throw StoringException("Invalid input!");
}

Victim Service::getTheNextFile()
{
	return this->repo->getNextFile();
}

void Service::saveVictimToAssistantListOfVictims(const string& nameOfVictim) {
	Victim victim = Victim(nameOfVictim);
	//Validator::validateVictim(victim);
	if (this->repo->isVictim(victim) && !this->repo->isVictimInAssistantFile(victim))
		this->repo->addVictimToAssistantFile(victim);
	else
		throw StoringException("Invalid file!");
}


vector<Victim> Service::getFiteredListOfVictimFiles(const string& placeOfOrigin, int age) {
	Validator::validateAge(age);

	vector<Victim> allVictims = repo->getAllVictims();
	if (placeOfOrigin == "")
		return allVictims;

	vector<Victim> filteredVictims(allVictims.size());

	auto filteredFunction = [&placeOfOrigin, &age](const Victim& victim) {
		return victim.getPlaceOfOrigin() == placeOfOrigin && victim.getAge() < age;
	};

	auto it = copy_if(allVictims.begin(), allVictims.end(), filteredVictims.begin(), filteredFunction);
	filteredVictims.resize(distance(filteredVictims.begin(), it));

	return filteredVictims;
}


vector<Victim> Service::getTheAssistantListOfVictims() {
	return this->repo->getAllAssistantSavedFiles();
}

void Service::openMyList() {
	this->repo->openMyList();
}

