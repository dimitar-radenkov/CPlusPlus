#pragma once
#include <iostream>
#include "Contracts\Trainer.h"

class SeniorTrainer : public Trainer
{
public:
	SeniorTrainer(const std::string& firstName,
				  const std::string& lastName,
				  const int age);

	virtual ~SeniorTrainer();

	void DeleteCourse(const std::string& courseName);
};

