#include "Exceptions.h"

StoringException::StoringException(const std::string& exceptionMsg) {
	this->exceptionMessage = exceptionMsg;
}

const char* StoringException::what() const noexcept
{
	return this->exceptionMessage.c_str();
}

ValidatorException::ValidatorException(const std::string& exceptionMsg) {
	this->exceptionMessage = exceptionMsg;
}

const char* ValidatorException::what() const noexcept
{
	return this->exceptionMessage.c_str();
}
