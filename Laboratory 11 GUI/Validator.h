#pragma once
#include "Exceptions.h"
#include "Victim.h"
#include <string>

class Validator {
public:
	static void validateInput(const std::string& input);
	static void validateAge(int age);
	static void validateVictim(const Victim& victim);
};

