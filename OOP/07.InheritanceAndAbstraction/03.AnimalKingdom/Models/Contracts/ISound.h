#pragma once

//interface
class ISound
{
public:

	ISound()
	{
	}

	virtual ~ISound()
	{
	}

	virtual void ProduceSound() const = 0;
};

