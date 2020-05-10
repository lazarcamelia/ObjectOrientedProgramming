#include "Validator.h"


void Validator::validateInput(const std::string& input){
	if (input == "")
		throw ValidatorException("Invalid input!");
}

void Validator::validateAge(int age) {
	if (age == 0)
		throw ValidatorException("Invaid age!");
}

void Validator::validateVictim(const Victim& victim) {
	validateInput(victim.getName());
}
