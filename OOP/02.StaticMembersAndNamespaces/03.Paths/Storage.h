#pragma once
#include <fstream>
#include <algorithm>
#include <vector>
#include "Path3D.h"

class Storage
{
private:
	static std::string filename;
	Storage()
	{}

public:

	static void Load(Path3D& path)
	{		
		std::ifstream infile;
		infile.open(filename);

		std::string line;
		while (std::getline(infile, line))
		{
			//parse line
			std::vector<std::string> splits;
			char* cline = new char[line.length() + 1];
			std::strcpy(cline, line.c_str());

			std::string delims = " {,}";
			char* token = std::strtok(cline, delims.c_str());
			while (token != nullptr)
			{
				splits.push_back(token);
				token = std::strtok(nullptr, delims.c_str());				
			}

			double x = std::atof(splits[1].c_str());
			double y = std::atof(splits[2].c_str());
			double z = std::atof(splits[3].c_str());

			Point3D p(x,y,z);
			path.AddPoint(p);
		}

		infile.close();
	}

	static void Save(const Path3D& path)
	{
		std::ofstream outfile;
		outfile.open(filename);

		std::vector<Point3D> points = path.getPoints();

		std::for_each(points.begin(), 
					  points.end(), 
					  [&outfile](Point3D point)
		{
			outfile << point.toString();
		});

		outfile.close();
	}

	~Storage()
	{}
};

std::string Storage::filename = "Storage.pth";