#include "JuniorTrainer.h"

JuniorTrainer::JuniorTrainer(const std::string& firstName,
							 const std::string& lastName,
							 const int age)
	:Trainer(firstName, lastName, age, TrainerType::Junior)
{
}

JuniorTrainer::~JuniorTrainer()
{
}

void JuniorTrainer::CreateCourse(const std::string& courseName)
{
	std::cout << "Course " << courseName << " created !" <<  std::endl;
}
