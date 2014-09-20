#pragma once
#include <string>
#include <sstream>
#include <memory>
#include "Component.h"

class Computer
{
private:
	std::string name;
	std::shared_ptr<Component> processor;
	std::shared_ptr<Component> motherBoard;
	std::shared_ptr<Component> graphicCard;

public:
	Computer(const std::string& name, 
			 const std::shared_ptr<Component> processor,
			 const std::shared_ptr<Component> motherBoard,
			 const std::shared_ptr<Component> graphicCard);
		
	~Computer();

	std::string toString() const;

	double Computer::getPrice() const;

	std::string getPriceAsString() const;

};

