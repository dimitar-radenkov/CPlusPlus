#ifndef POSITION_HPP
#define POSITION_HPP

struct Position
{
	int row;
	int col;

	Position(int row, int col)
		:row(row), col(col)
	{}

	bool isValid()
	{
		return (this->row < 0 || this->col < 0) ? false : true;
	}
};


#endif //POSITION_HPP