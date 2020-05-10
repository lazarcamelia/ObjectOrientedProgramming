#pragma once
#include "Repository.h"
class SqlRepository : public Repository {
private:
	string fileLocation;
	int positionOfTheCurrent;

	ListStorage* myListStorage;
public:
	SqlRepository();
	SqlRepository(ListStorage* myListStorage, const string& fileLocation);
	/*
		add a new victim file to the repository
		victim - Victim, const by reference
		Precondition: the victim doesn't already exist in the repository
	*/
	void addVictim(const Victim& victim);
	void updateVictim(const Victim& victim);
	/*
		delete a victim file from the repository
		victim - Victim, const by reference
		Precondition: the victim  already exist in the repository
	*/
	void deleteVictim(const Victim& victim);
	/*
		check if a given Victim file exist into the repository
		victim - Victim, const by reference
		returns true if the file exist, false otherwise
	*/
	bool isVictim(const Victim& victim);
	/*
		check if a given Victim file exist into the assistant repository
		victim - Victim, const by reference
		returns true if the file exist, false otherwise
	*/
	bool isVictimInAssistantFile(const Victim& victim);
	/*
		function which returns all the Victim files from the repository stored into a DynamicArray
	*/
	std::vector<Victim> getAllVictims();
	/*
		function which get the next file into the repoitory
		return: the the next Victim file
	*/
	Victim getNextFile();
	/*
		add a new victim file to the assistant repository
		victim - Victim, const by reference
		Precondition: the victim doesn't already exist in the assistant repository
	*/
	void addVictimToAssistantFile(const Victim& victim);
	/*
		function which returns all the Victim files from the assistant repository stored into a DynamicArray
	*/
	std::vector<Victim> getAllAssistantSavedFiles();

	void setFileLocation(const string& fileLocation);

	void openMyList();
private:
	vector<Victim> readData();
};

