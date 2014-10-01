#pragma once
#include "Contracts\Cat.h"

class Kitten : public Cat
{
public:
	Kitten(const std::string& name,
		   const int age);

	virtual ~Kitten();
};

