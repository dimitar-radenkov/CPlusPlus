/**
 * UniqueNumberGenerator.h
 *
 * $id$
 *
 * Description: Generator of unique numbers in specified range
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef UNIQUE_NUMBER_GENERATOR
#define UNIQUE_NUMBER_GENERATOR

#include "Utils/CommonException.h"

#include <set>
#include <stdint.h>

namespace utils
{
/**
 */
class UniqueNumberGenerator
{
public:
    /**
     */
	UniqueNumberGenerator(uint64_t rangeStart = 1, uint64_t rangeEnd = 65535):
        _rangeStart (rangeStart),
        _rangeEnd (rangeEnd),
        _nextAvailabeNumber (rangeStart)
    {
        if ( _rangeStart > _rangeEnd )
        {
            // error! start number shouldn't be bigger than end number
            throw utils::CommonException("Invalid unique numbers range.",0);
        }
        _unusedNumbers.clear();
    }

    /**
     */
    ~UniqueNumberGenerator() {}

    /**
     */
    void reset()
    {
        _nextAvailabeNumber = _rangeStart;
        _unusedNumbers.clear();
    }

    /**
     */
    uint64_t getNumber()
    {
        // check for already released numbers
        if ( _unusedNumbers.size() )
        {
            // retrieve first free number
            uint64_t retrievedNumber = *(_unusedNumbers.begin());
            // remove it from the set
            _unusedNumbers.erase(_unusedNumbers.begin());

            return retrievedNumber;
        }

        // check if we have any numbers left
        if ( _nextAvailabeNumber > _rangeEnd )
        {
            // error! all available numbers were given
            throw utils::CommonException("All available unique numbers were given.",0);
        }

        // retrieve next available number
        return _nextAvailabeNumber++;
    }

    void reserveNumber(uint64_t number)
    {
        // check if the number is out of range
        if ( number > _rangeEnd || number < _rangeStart)
        {
            // error! invalid number to be reserved
            throw utils::CommonException("Reserving invalid unique number.", 0);
        }

        if ( number >= _nextAvailabeNumber)
        {
            while ( _nextAvailabeNumber < number)
            {
                // remember the number for future use
                _unusedNumbers.insert(_nextAvailabeNumber++);
            }
            // just skip the current number
            _nextAvailabeNumber++;
        }
        else
        {
            std::set<uint64_t>::iterator numIt = _unusedNumbers.find(number);

            if ( _unusedNumbers.end() == numIt )
            {
                // requested number was already reserved
                throw utils::CommonException("Already reserved unique number.", 0);
            }
            // reserve unused number
            _unusedNumbers.erase(numIt);
        }
    }

    /**
     */
    void releaseNumber(uint64_t number)
    {
        // validate the number
        if ( _rangeStart <= number && number < _nextAvailabeNumber )
        {
            // remember the number for future use
            _unusedNumbers.insert(number);
        }
    }

    /**
     */
    bool isReserved(uint64_t number)
    {
        if ( number >= _nextAvailabeNumber )
        {
            // the number is not reserved yet
            return false;
        }

        // check the unused numbers
        return (_unusedNumbers.end() == _unusedNumbers.find(number));
    }

private:
    /**
     */
    const uint64_t _rangeStart;

    /**
     */
    const uint64_t _rangeEnd;

    /**
     */
    uint64_t _nextAvailabeNumber;

    /**
     */
	std::set<uint64_t> _unusedNumbers;
};

}//namespace utils

#endif // UNIQUE_NUMBER_GENERATOR
