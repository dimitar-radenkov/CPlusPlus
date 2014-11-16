#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include "Position.hpp"

static const int n = 6;
static const std::string startChar = "*";
static std::string ma3x[n][n]
{
	{ "0", "0", "0", "x", "0", "x" },
	{ "0", "x", "0", "x", "0", "x" },
	{ "0", "*", "x", "0", "x", "0" },
	{ "0", "x", "0", "0", "0", "0" },
	{ "0", "0", "0", "x", "x", "0" },
	{ "0", "0", "0", "x", "0", "x" },
};

void print()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << "  " << ma3x[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

Position getStartPosition()
{
	Position pos(-1, -1);

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (ma3x[i][j] == startChar)
			{
				pos.row = i;
				pos.col = j;
			}
		}		
	}

	return pos;
}

void markUnreachableCells()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (ma3x[i][j] == "0")
			{
				ma3x[i][j] = "u";
			}
		}
	}
}

std::vector<Position> getUnvisitedNeighbors(const Position& currentPos)
{
	std::vector<Position> neighbors;

	//try go left
	if (currentPos.col - 1 >= 0 &&
		ma3x[currentPos.row][currentPos.col - 1] == "0")
	{
		Position nextPos(currentPos.row, currentPos.col - 1);
		neighbors.push_back(nextPos);
	}

	//try go up
	if (currentPos.row - 1 >= 0 &&
		ma3x[currentPos.row - 1][currentPos.col] == "0")
	{
		Position nextPos(currentPos.row - 1, currentPos.col);
		neighbors.push_back(nextPos);
	}

	//try go right
	if (currentPos.col + 1 >= 0 &&
		ma3x[currentPos.row][currentPos.col + 1] == "0")
	{
		Position nextPos(currentPos.row, currentPos.col + 1);
		neighbors.push_back(nextPos);
	}

	//try go down
	if (currentPos.row + 1 >= 0 &&
		ma3x[currentPos.row + 1][currentPos.col] == "0")
	{
		Position nextPos(currentPos.row + 1, currentPos.col);
		neighbors.push_back(nextPos);
	}

	return neighbors;
}

void traverse(Position& startPos)
{
	int counter = 1;
	//traverse
	if (startPos.isValid())
	{
		std::queue<std::vector<Position>> listNeighbors;
		auto neighbors = getUnvisitedNeighbors(startPos);

		listNeighbors.push(neighbors);
		while (!listNeighbors.empty())
		{
			auto neighbors = listNeighbors.front();
			listNeighbors.pop();

			std::vector<Position> nextPoss;
			auto itPos = neighbors.begin();
			for (; itPos != neighbors.end(); ++itPos)
			{
				ma3x[(*itPos).row][(*itPos).col] = std::to_string(counter);

				auto unvisited = getUnvisitedNeighbors(*itPos);
				std::for_each(unvisited.begin(), unvisited.end(),
					[&](const Position& p){ nextPoss.push_back(p); });
			}

			if (!nextPoss.empty())
			{
				listNeighbors.push(nextPoss);
			}
			counter++;
		}
	}
}

int main()
{
	Position startPos = getStartPosition();

	//traverse
	traverse(startPos);

	//mark unreachable cells
	markUnreachableCells();

	//show ouput
	print();

	system("pause");
	return 0;
}