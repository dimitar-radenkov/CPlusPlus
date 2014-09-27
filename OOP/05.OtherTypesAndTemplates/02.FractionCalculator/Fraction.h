#pragma once
#include <string>
#include <sstream>

struct Fraction
{
private:
	double numerator;
	double denominator;

public:

	Fraction(double numerator, double denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}

	double getNumerator() const
	{
		return this->numerator;
	}

	double getDenominator() const
	{
		return this->denominator;
	}

	Fraction operator+(const Fraction& fraction)
	{
		double n = this->numerator + fraction.getNumerator();
		double d = this->denominator + fraction.getDenominator();

		return Fraction(n, d);
	}

	Fraction operator-(const Fraction& fraction)
	{
		double n = this->numerator - fraction.getNumerator();
		double d = this->denominator - fraction.getDenominator();

		return Fraction(n, d);
	}

	std::string toString()
	{
		double res = this->numerator / this->denominator;

		return std::to_string(res);
	}
};

