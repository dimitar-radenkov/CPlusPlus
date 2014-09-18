#pragma once
#include <string>
#include <sstream>
#include "Battery.h"

class Laptop
{
private:
	std::string model;
	std::string manufacturer;
	std::string processor;
	std::string graphicsCard;
	Battery battery;
	double screenSize;
	double price;

public:
	Laptop(const std::string& model,
		   const std::string& manufacturer,
		   const std::string& processor,
		   const std::string& graphicsCard,
		   const Battery& battery,
		   const double screenSize = 0,
		   const double price = 0);

	virtual ~Laptop();

	std::string getModel() const
	{
		return this->model;
	}

	void setModel(const std::string& model)
	{
		this->model = model;
	}

	std::string getManufacturer() const
	{
		return this->manufacturer;
	}

	void setManufacturer(const std::string& model)
	{
		this->model = model;
	}

	std::string getProcessor() const
	{
		return this->processor;
	}

	void setProcessor(const std::string& processor)
	{
		this->processor = processor;
	}

	std::string getGraphicsCard() const
	{
		return this->graphicsCard;
	}

	void setGraphicsCard(const std::string& graphicsCard)
	{
		this->graphicsCard = graphicsCard;
	}

	Battery getBattery() const
	{
		return this->battery;
	}

	void setBattery(const Battery& battery)
	{
		this->battery = battery;
	}

	double getScreenSize() const
	{
		return this->screenSize;
	}

	double getPrice() const
	{
		return this->price;
	}

	std::string toString() const;
};

