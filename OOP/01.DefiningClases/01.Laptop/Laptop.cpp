#include "Laptop.h"

Laptop::Laptop(const std::string& model,
			   const std::string& manufacturer,
			   const std::string& processor,
			   const std::string& graphicsCard,
			   const Battery& battery,
			   const double screenSize,
			   const double price)
{
	this->model = model;
	this->manufacturer = manufacturer;
	this->processor = processor;
	this->graphicsCard = graphicsCard;
	this->battery = battery;
	this->screenSize = screenSize;
	this->price = price;
}


Laptop::~Laptop()
{
}

std::string Laptop::toString() const
{
	std::stringstream ss;

	ss << "LAPTOP INFO" << std::endl;
	ss << "Model : " << this->model << std::endl;
	ss << "manufacturer : " << this->manufacturer << std::endl;
	ss << "processor : " << this->processor << std::endl;
	ss << "graphicsCard : " << this->graphicsCard << std::endl;
	ss << "battery : " << this->battery.toString() << std::endl;
	ss << "screenSize : " << this->screenSize << "inch's" << std::endl;
	ss << "price : " << this->price << std::endl << std::endl;

	return ss.str();
}
