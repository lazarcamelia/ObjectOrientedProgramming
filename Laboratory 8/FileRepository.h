#pragma once
#include "Repository.h"
#include "Victim.h"
#include <string>

using namespace std;

class FileRepository : public Repository {
private:
	string filename;
	vector<Victim> assistantFiles;
	int positionOfTheCurrent;
public:
	//constructor
	FileRepository(const string& filename);
	/*
		add a new victim file to the repository
		victim - Victim, const by reference
		Precondition: the victim doesn't already exist in the repository
	*/
	void addVictim(const Victim& victim);
	/*
		update a victim file to the repository
		victim - Victim, const by reference
		Precondition: the victim  already exist in the repository
	*/
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
	vector<Victim> getAllVictims();
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
	vector<Victim> getAllAssistantSavedFiles();
private:
	/*
	auxiliary function which convert a line read from the file into the vector of string atributes of a victim
	*/
	vector<string> convertLine(string Victim, char Delimiter);
	/*
		read all victims from the file
		returns: a vector of victims containing all the victims in the file
	*/
	vector<Victim> readFromFile();
	/*
		write all the victims to file
		victims - vector containing all the victims to be written
	*/
	void writeToFile(vector<Victim> victims);
};

