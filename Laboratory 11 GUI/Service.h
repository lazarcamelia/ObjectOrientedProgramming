#pragma once
#include "FileRepository.h"
#include "Victim.h"

using namespace std;

class Service {
private:
	FileRepository* repo;

public:
	//constructor
	Service(FileRepository* repo) : repo{ repo } {}
	/*
		unction which returns all the Victim files from the repository stored into a DynamicArray
	*/
	vector<Victim> getAllVictims() const;
	/*
		function which add a new victim to the repository
		name = const string sent by reference
		place of origin = const string sent by reference
		age = intger, positive number
		photoLink = const string sent by reference
	*/
	void addVictim(const string& name, const string& placeOforigin, int age, const string& photoLink);
	/*
		function which updates a victim from the repository having the name equal to the given name
		name = const string sent by reference
	 */
	void deleteVictim(const string& name);
	/*
		function which delete a new victim to the repository waving the name name
		name = const string sent by reference
		newPlaceOfOnrigin = const string sent by reference
		newAge = intger, positive number
		newPhotoLink = const string sent by reference
	*/
	void updateVictim(const string& name, const string& newPlaceOforigin, int newAge, const string& newPhotoLink);
	void setFileLocation(const string& fileLocation);
	/*
		function which returns the next Victim file from the assistant repository
	*/
	Victim getTheNextFile();
	/*
		save a victim havin the name equal to the nameOfVictim from the repository to the assistant repository
	*/
	void saveVictimToAssistantListOfVictims(const string& nameOfVictim);
	/*
		function which returns the Victims file from the assistant repository having 2 constraints:
		1. the place of origin is equal to the given placeOfOrigin
		2. the age is strictly smaller than the given age
	*/
	vector<Victim> getFiteredListOfVictimFiles(const string& placeOfOrigin, int age);
	/*
		function which returns all the viles from the assistant repository stored into a Dynamic Vector
	*/
	vector<Victim> getTheAssistantListOfVictims();

	void openMyList();
};