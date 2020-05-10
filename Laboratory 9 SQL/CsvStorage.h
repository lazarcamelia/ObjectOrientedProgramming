#pragma once
#include "ListStorage.h"

class CsvStorage : public ListStorage {
private:
	std::string path;
public:
	CsvStorage(const std::string& path);
	void setPath(const string& path) override;
	bool findVictim(const Victim& victimToBeFound) override;
	void addVictim(const Victim& victim) override;
	vector<Victim> getAll() override;
	void open() override;
private:
	vector<Victim> readData() override;
	void writeData(vector<Victim> assistantListOfFiles) override;
};

