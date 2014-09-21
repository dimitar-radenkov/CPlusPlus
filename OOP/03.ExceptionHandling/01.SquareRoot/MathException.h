#pragma once
#include <iostream>
#include <exception>

struct MathException : public std::exception
{
private:
	std::string message;

public:
	MathException(const std::string& message)
	{
		this->message = message;
	}

	virtual ~MathException()
	{
	}

	virtual const char* what() const throw() override
	{
		return this->message.c_str();
	}
};


