#pragma once

template<typename TClock>
class Stopwatch
{
	TClock _clock;
	std::chrono::time_point<TClock> _start;
	std::chrono::time_point<TClock> _end;

public:
	Stopwatch()
	{}

	void start()
	{
		_start = _clock.now();
	}

	void stop()
	{
		_end = _clock.now();
	}

	template<typename TRetType>
	TRetType elapsed()
	{	
		if (_start.time_since_epoch() != TRetType{ 0 } )
		{
			if (_end.time_since_epoch() != TRetType{ 0 })
			{
				//has been stoped
				return std::chrono::duration_cast<TRetType>(_end - _start);
			}
			else
			{
				//still running
				return std::chrono::duration_cast<TRetType>(_clock.now() - _start);
			}
		}

		//not started
		return TRetType{ 0 };
	}

	void reset()
	{
		_start = _end;
	}
};