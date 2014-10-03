#pragma once

class IShape
{
protected:
	IShape()
	{}

public:
	virtual ~IShape()
	{}

	virtual double CalculateArea() const = 0;

	virtual double CalculatePerimeter() const = 0;
};

