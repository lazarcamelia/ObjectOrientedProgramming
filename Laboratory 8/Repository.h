#pragma once

#include <vector>
#include "Victim.h"

class Repository {

public:
	/*
		add a new victim file to the repository
		victim - Victim, const by reference
		Precondition: the victim doesn't already exist in the repository
	*/
	virtual void addVictim(const Victim& victim) = 0;
	/*
		update a victim file to the repository
		victim - Victim, const by reference
		Precondition: the victim  already exist in the repository
	*/
	virtual void updateVictim(const Victim& victim) = 0;
	/*
		delete a victim file from the repository
		victim - Victim, const by reference
		Precondition: the victim  already exist in the repository
	*/
	virtual void deleteVictim(const Victim& victim) = 0;
	/*
		check if a given Victim file exist into the repository
		victim - Victim, const by reference
		returns true if the file exist, false otherwise
	*/
	virtual bool isVictim(const Victim& victim) = 0;
	/*
		check if a given Victim file exist into the assistant repository
		victim - Victim, const by reference
		returns true if the file exist, false otherwise
	*/
	virtual bool isVictimInAssistantFile(const Victim& victim) = 0;
	/*
		function which returns all the Victim files from the repository stored into a DynamicArray
	*/
	virtual std::vector<Victim> getAllVictims() = 0;
	/*
		function which get the next file into the repoitory
		return: the the next Victim file
	*/
	virtual Victim getNextFile() = 0;
	/*
		add a new victim file to the assistant repository
		victim - Victim, const by reference
		Precondition: the victim doesn't already exist in the assistant repository
	*/
	virtual void addVictimToAssistantFile(const Victim& victim) = 0;
	/*
		function which returns all the Victim files from the assistant repository stored into a DynamicArray
	*/
	virtual std::vector<Victim> getAllAssistantSavedFiles() = 0;
};
