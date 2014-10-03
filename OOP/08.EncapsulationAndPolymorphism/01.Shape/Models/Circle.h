#pragma once
#include <cmath>
#include "Models/Contracts/BasicShape.h"

#define PI 3.14159265358979323846  /* pi */

class Circle : public BasicShape
{
public:
	Circle(const double radius);

	virtual ~Circle();

	virtual double CalculateArea() const override
	{
		return PI * std::pow(BasicShape::height, 2);
	}

	virtual double CalculatePerimeter() const override
	{		
		return 2 * PI * BasicShape::height;
	}
};

