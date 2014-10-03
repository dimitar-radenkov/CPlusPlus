#pragma once
#include <cmath>
#include "Models/Contracts/BasicShape.h"

class Triangle : public BasicShape
{
public:
	Triangle(const double a,
		const double b);

	virtual ~Triangle();

	virtual double CalculateArea() const override
	{
		return (this->width * this->height) / 2;
	}

	virtual double CalculatePerimeter() const override
	{
		double firstSidePow = std::pow(this->height, 2);
		double secondSidePow = std::pow(this->width, 2);

		double thirdSide = std::sqrt(firstSidePow + secondSidePow);

		return this->height + this->width + thirdSide;
	}
};

