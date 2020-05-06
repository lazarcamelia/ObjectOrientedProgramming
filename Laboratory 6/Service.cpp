#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>


#include "Service.h"

DynamicVector<Victim> Service::getAllVictims() const
{
	return this->repo.getAllVictims();
}

void Service::addVictim(const std::string& name, const std::string& placeOforigin, int age, const std::string& photoLink) {
	Victim victimToBeAddedToRepo = Victim(name, placeOforigin, age, photoLink);
	if (!this->repo.isVictim(victimToBeAddedToRepo))
		this->repo.addVictim(victimToBeAddedToRepo);
	else
		throw std::exception("Invalid operation!");
}

void Service::deleteVictim(const std::string& name) {
	Victim victimToBeDeleted = Victim(name);
	if (this->repo.isVictim(victimToBeDeleted))
		this->repo.deleteVictim(victimToBeDeleted);
	else
		throw std::exception("Invalid operation!");
}

void Service::updateVictim(const std::string& name, const std::string& newPlaceOforigin, int newAge, const std::string& newPhotoLink) {
	Victim victimToBeUpdated = Victim(name, newPlaceOforigin, newAge, newPhotoLink);
	if (this->repo.isVictim(victimToBeUpdated))
		this->repo.updateVictim(victimToBeUpdated);
	else
		throw std::exception("Invalid input!");
}

Victim Service::getTheNextFile()
{
	return this->repo.getNextFile();
}

void Service::saveVictimToAssistantListOfVictims(const std::string& nameOfVictim) {
	Victim victim = Victim(nameOfVictim);
	if (this->repo.isVictim(victim) && !this->repo.isVictimInAssistantFile(victim))
		this->repo.addVictimToAssistantFile(victim);
}

DynamicVector<Victim> Service::getFiteredListOfVictimFiles(const std::string& placeOfOrigin, int age) {
	DynamicVector<Victim> allVictims = repo.getAllVictims();
	if (placeOfOrigin == "")
		return allVictims;
	
	DynamicVector<Victim> filteredVictims = DynamicVector<Victim>();

	for (int i = 0; i < allVictims.getSize(); i++) {
		Victim victim = allVictims.getElementOnPosition(i);
		if (victim.getPlaceOfOrigin() == placeOfOrigin && victim.getAge() < age)
			filteredVictims.addElement(victim);
	}
	return filteredVictims;
}

DynamicVector<Victim> Service::getTheAssistantListOfVictims() {
	return this->repo.getAllAssistantSavedFiles();
}


