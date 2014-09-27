#pragma once
#include <string>
#include <sstream>
#include "Planet.h"

struct Location
{
	double latitude;
	double longtitude;
	Planet planet;

	Location(double latitude, double longtitude, Planet planet)
	{
		this->latitude = latitude;
		this->longtitude = longtitude;
		this->planet = planet;
	}

	std::string toString()
	{
		std::stringstream ss;

		ss << this->latitude << ", ";
		ss << this->longtitude << " - ";
		ss << this->GetPlanetName(this->planet);

		return ss.str();
	}

private:
	std::string GetPlanetName(Planet planet)
	{
		switch (planet)
		{
		case Mercury:
			return "Mercury";
			break;
		case Venus:
			return "Venus";
			break;
		case Earth:
			return "Earth";
			break;
		case Mars:
			return "Mars";
			break;
		case Jupiter:
			return "Jupiter";
			break;
		case Saturn:
			return "Saturn";
			break;
		case Uranus:
			return "Uranus";
			break;
		case Neptune:
			return "Neptune";
			break;
		default:
			return "Unknown";
			break;
		}
	}
};