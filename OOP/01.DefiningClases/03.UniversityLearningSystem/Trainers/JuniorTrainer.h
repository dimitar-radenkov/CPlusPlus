#pragma once
#include <iostream>
#include "Contracts/Trainer.h"

class JuniorTrainer : public Trainer
{
public:
	JuniorTrainer(const std::string& firstName,
				  const std::string& lastName,
				  const int age);

	virtual ~JuniorTrainer();

	void CreateCourse(const std::string& courseName);
};

