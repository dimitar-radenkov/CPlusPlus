#pragma once
#include <iostream>
#include <exception>

struct ReadNumbersException : public std::exception
{
private:
	std::string message;

public:
	ReadNumbersException(const std::string& message)
	{
		this->message = message;
	}

	virtual ~ReadNumbersException()
	{
	}

	virtual const char* what() const throw() override
	{
		return this->message.c_str();
	}
};


