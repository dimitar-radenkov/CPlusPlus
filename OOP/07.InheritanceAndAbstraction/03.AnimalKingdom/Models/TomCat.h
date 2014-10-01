#pragma once
#include "Contracts\Cat.h"

class TomCat : public Cat
{
public:
	TomCat(const std::string& name,
		   const int age);

	virtual ~TomCat();
};

