#pragma once
#include <string>
#include <iostream>

class Victim {
private:
	std::string name;
	std::string placeOfOrigin;
	int age;
	std::string photoLink;
public:
	//constructors
	Victim(std::string name = "");
	Victim(const std::string& name, const std::string& placeOfOrigin, int age, const std::string photo);
	//overwrite the equality operator
	bool operator==(const Victim& victim);
	/*
	getter for name
	returns the name of the victim
	*/
	std::string getName() const;
	/*
	getter for place of origin
	returns the place of origin of the victim
	*/
	std::string getPlaceOfOrigin() const;
	/*
	getter for age
	returns the age of the victim
	*/
	int getAge() const;
	/*
	getter for photo link
	returns the photo link of the victim
	*/
	std::string getPhotoLink() const;
	/*
	convert vicitm to string
	reurns a string containing the victim fields
	*/
	std::string toString();


	friend std::ostream& operator<<(std::ostream&, Victim&);
	friend std::istream& operator>>(std::istream&, Victim&);
};
