#pragma once
#include "Models/Contracts/IShape.h"

class BasicShape : public IShape
{
protected:
	double width;
	double height;

	BasicShape(double width, double height)
	{
		this->width = width;
		this->height = height;
	}

	BasicShape(double radius)
	{
		this->height = radius;
	}

public:

	virtual ~BasicShape()
	{}

	virtual double CalculateArea() const = 0;

	virtual double CalculatePerimeter() const = 0;
};

