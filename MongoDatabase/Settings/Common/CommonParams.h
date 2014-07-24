/*
 * CommonParams.h
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#ifndef COMMONPARAMS_H_
#define COMMONPARAMS_H_

#include <cstdint>
#include <string>

/**
 */
struct CommonParams
{
private:
    static const uint16_t AUTO_LOG_TIME = 1440;

public:

    /**
     */
    CommonParams():
        jurisdictionLimit(0),
        casinoName(""),
        casinoLocation("") ,
        currencyCode(""),
        automaticOverflow(false) ,
        autoLogValuesTime(AUTO_LOG_TIME) {}

    /**
     */
    CommonParams(const uint16_t jurisdictionLimit,
                 const std::string casinoName,
                 const std::string casinoLocation,
                 const std::string currencyCode,
                 bool automaticOverflow,
                 const uint16_t autoLogValuesTime = AUTO_LOG_TIME):
        jurisdictionLimit(jurisdictionLimit),
        casinoName(casinoName),
        casinoLocation(casinoLocation),
        currencyCode(currencyCode),
        automaticOverflow(automaticOverflow),
        autoLogValuesTime(autoLogValuesTime)

    {

    }

    /**
     */
    CommonParams & operator = (const CommonParams & params)
    {
        jurisdictionLimit = params.jurisdictionLimit;
        casinoName = params.casinoName;
        casinoLocation = params.casinoLocation;
        currencyCode = params.currencyCode;
        automaticOverflow = params.automaticOverflow;
        autoLogValuesTime = params.autoLogValuesTime;

        return *this;
    }

    /**
     */
    bool operator == (const CommonParams & params)
    {
        return ( jurisdictionLimit == params.jurisdictionLimit &&
                 0 == casinoName.compare(params.casinoName) &&
                 0 == casinoLocation.compare(params.casinoLocation) &&
                 0 == currencyCode.compare(params.currencyCode) &&
                 automaticOverflow == params.automaticOverflow &&
                 autoLogValuesTime == params.autoLogValuesTime );
    }

    /**
     */
    bool operator != (const CommonParams & params)
    {
        return !(*this == params);
    }

    /**
     */
    uint16_t jurisdictionLimit;

    /**
     */
    std::string casinoName;

    /**
     */
    std::string casinoLocation;

    /**
     */
    std::string currencyCode;

    /**
     */
    bool automaticOverflow;

    /**
     */
    uint16_t autoLogValuesTime;
};

#endif /* COMMONPARAMS_H_ */
