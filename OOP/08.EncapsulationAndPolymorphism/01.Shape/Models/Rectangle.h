#pragma once
#include "Models/Contracts/BasicShape.h"

class Rectangle : public BasicShape
{
public:
	Rectangle(const double width,
		const double height);

	virtual ~Rectangle();

	virtual double CalculateArea() const override
	{
		return this->width * this->height;
	}

	virtual double CalculatePerimeter() const override
	{
		return 2 * (width + height);
	}
};

