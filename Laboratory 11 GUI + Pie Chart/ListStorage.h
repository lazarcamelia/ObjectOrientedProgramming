#pragma once
#include "Victim.h"
#include <string>
#include <vector>

using namespace std;

class ListStorage{
private:
	std::string path;
public:
	virtual void setPath(const string& path) = 0;
	virtual bool findVictim(const Victim& victim) = 0;
	virtual void addVictim(const Victim& victim) = 0;
	virtual  vector<Victim> getAll() = 0;
	virtual void open() = 0;
private:
	virtual vector<Victim> readData() = 0;
	virtual void writeData(vector<Victim> assistantListOfFiles) = 0;
};

