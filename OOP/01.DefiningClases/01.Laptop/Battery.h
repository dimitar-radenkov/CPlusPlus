#pragma once
#include <sstream>
#include <string>

class Battery
{
private:
	const int InitialLife = 100;

	int life;
public:
	Battery();

	virtual ~Battery();

	int getLife() const
	{
		return this->life;
	}

	void setLife(const int life)
	{
		this->life = life;
	}

	void operator =(Battery battery);

	std::string toString() const;
};

