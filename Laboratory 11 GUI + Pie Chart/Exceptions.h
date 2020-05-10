#pragma once
#include <string>
#include <exception>

class StoringException : public std::exception{
private:
	std::string exceptionMessage;

public:
	StoringException(const std::string& exceptionMsg);
	const char* what() const noexcept override;	
};

class ValidatorException : public std::exception {
private:
	std::string exceptionMessage;

public:
	ValidatorException(const std::string& exceptionMsg);
	const char* what() const noexcept override;
};