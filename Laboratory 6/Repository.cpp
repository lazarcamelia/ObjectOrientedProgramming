#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>
#include <exception>
#include "Repository.h"

Repository::Repository() {
	this->positionOfTheCurrent = 0;
}

void Repository::addVictim(const Victim& victim) {
	this->victimFiles.addElement(victim);	
}

void Repository::updateVictim(const Victim& victim) {
	this->victimFiles.updateElement(victim);
	if (this->assistantSavedFiles.existElement(victim))
		this->assistantSavedFiles.updateElement(victim);
}

void Repository::deleteVictim(const Victim& victim) {
	this->victimFiles.deleteElement(victim);
	if (this->assistantSavedFiles.existElement(victim))
		this->assistantSavedFiles.deleteElement(victim);
}

bool Repository::isVictim(const Victim& victim) {
	if (this->victimFiles.existElement(victim))
		return true;
	return false;
}

bool Repository::isVictimInAssistantFile(const Victim& victim)
{
	if (this->assistantSavedFiles.existElement(victim))
		return true;
	return false;
}

DynamicVector<Victim> Repository::getAllVictims() const {
	return victimFiles;
}


Victim Repository::getNextFile() {
	if (this->positionOfTheCurrent == this->victimFiles.getSize())
		this->positionOfTheCurrent = 0;
	return this->victimFiles[positionOfTheCurrent++];
}

void Repository::addVictimToAssistantFile(const Victim& victim) {
	Victim newVictimToBeAdded = this->victimFiles.getElementEqual(victim);
	this->assistantSavedFiles.addElement(newVictimToBeAdded);
}

DynamicVector<Victim> Repository::getAllAssistantSavedFiles() {
	return assistantSavedFiles;
}

