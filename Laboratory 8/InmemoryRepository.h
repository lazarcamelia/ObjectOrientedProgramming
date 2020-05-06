#pragma once
#include "Repository.h"
#include <vector>
#include "Victim.h"

using namespace std;

class InmemoryRepository : public Repository {
private:
	vector<Victim> victimFiles{};
	vector<Victim> assistantSavedFiles{};
	int positionOfTheCurrent;

public:
	InmemoryRepository();
	void addVictim(const Victim& victim);
	void updateVictim(const Victim& victim);
	void deleteVictim(const Victim& victim);
	bool isVictim(const Victim& victim);
	bool isVictimInAssistantFile(const Victim& victim);
	vector<Victim> getAllVictims() const;
	Victim getNextFile();
	void addVictimToAssistantFile(const Victim& victim);
	vector<Victim> getAllAssistantSavedFiles();
};

