#include "SeniorTrainer.h"

SeniorTrainer::SeniorTrainer(const std::string& firstName,
							 const std::string& lastName,
							 const int age)
	:Trainer(firstName, lastName, age, TrainerType::Senior)
{
}

SeniorTrainer::~SeniorTrainer()
{
}

void SeniorTrainer::DeleteCourse(const std::string& courseName)
{
	std::cout << "Course " << courseName << " deleted !" << std::endl;
}
