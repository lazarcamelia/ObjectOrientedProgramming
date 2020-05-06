#include "InmemoryRepository.h"

using namespace std;

InmemoryRepository::InmemoryRepository() {
	this->positionOfTheCurrent = 0;
}

void InmemoryRepository::addVictim(const Victim& victim)
{

	this->victimFiles.addElement(victim);
}

void InmemoryRepository::updateVictim(const Victim& victim)
{
	this->victimFiles.updateElement(victim);
	if (this->assistantSavedFiles.existElement(victim))
		this->assistantSavedFiles.updateElement(victim);
}

void InmemoryRepository::deleteVictim(const Victim& victim)
{
	this->victimFiles.deleteElement(victim);
	if (this->assistantSavedFiles.existElement(victim))
		this->assistantSavedFiles.deleteElement(victim);
}

bool InmemoryRepository::isVictim(const Victim& victim)
{
	if (this->victimFiles.existElement(victim))
		return true;
	return false;
}

bool InmemoryRepository::isVictimInAssistantFile(const Victim& victim)
{
	if (this->assistantSavedFiles.existElement(victim))
		return true;
	return false;
}

vector<Victim> InmemoryRepository::getAllVictims() const
{
	return victimFiles;
}

Victim InmemoryRepository::getNextFile()
{
	if (this->positionOfTheCurrent == this->victimFiles.getSize())
		this->positionOfTheCurrent = 0;
	return this->victimFiles[positionOfTheCurrent++];
}

void InmemoryRepository::addVictimToAssistantFile(const Victim& victim)
{
	Victim newVictimToBeAdded = this->victimFiles.getElementEqual(victim);
	this->assistantSavedFiles.addElement(newVictimToBeAdded);
}

vector<Victim> InmemoryRepository::getAllAssistantSavedFiles()
{
	return assistantSavedFiles;
}
