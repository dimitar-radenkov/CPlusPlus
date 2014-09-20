#include "Computer.h"


Computer::Computer(const std::string& name,
				   const std::shared_ptr<Component> processor,
				   const std::shared_ptr<Component> motherBoard,
				   const std::shared_ptr<Component> graphicCard)
{
	this->name = name;
	this->processor = processor;
	this->motherBoard = motherBoard;
	this->graphicCard = graphicCard;
}

Computer::~Computer()
{
}

std::string Computer::toString() const
{
	std::stringstream ss;

	ss << "-- Computer -- " << std::endl;
	ss << "Name : " << this->name << std::endl;
	ss << "Price : " << this->getPriceAsString() << std::endl;

	return ss.str();
}

double Computer::getPrice() const
{
	double price = 0;

	price += this->processor->getPrice();
	price += this->motherBoard->getPrice();
	price += this->graphicCard->getPrice();

	return price;
}

std::string Computer::getPriceAsString() const
{
	double price = 0;

	price += this->processor->getPrice();
	price += this->motherBoard->getPrice();
	price += this->graphicCard->getPrice();

	std::string priceString = std::to_string(price) + " BGN";

	return priceString;
}
