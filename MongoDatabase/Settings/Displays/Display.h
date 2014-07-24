/*
 * Display.h
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <sstream>
#include <cstdint>
#include <string>
#include <map>
#include <memory>

class Display
{
    /**
     * The default constructor is forbidden.
     */
    Display() :
        _networkAddress(0),
        _serialNumber(0),
        _numberInCasino(0),
        _generalOptionsConfId(0),
        _priorityScreensConfId(0),
        _scenarioScreensConfId(0),
        _suspended(true),
        _online(false)
    {}

public:
    /**
     */
    Display(const uint16_t networkAddress,
            const uint64_t serialNumber,
            const uint16_t numberInCasino,
            const uint16_t generalOptionsConfId = 0,
            const uint16_t priorityScreensConfId = 0,
            const uint16_t scenarioScreensConfId = 0,
            const bool suspended = true);

    /**
     */
    Display(const Display & display);

    /**
     */
    ~Display();

    /**
     */
    Display & operator = (const Display & display);

    /**
     */
    bool operator== (const Display & display)
    {
        return (_serialNumber == display.getSerialNumber()) &&
               (_networkAddress == display.getNetworkAddress()) &&
               (_numberInCasino == display.getNumberInCasino()) &&
               (_generalOptionsConfId == display.getGeneralOptionsConfId()) &&
               (_priorityScreensConfId == display.getPriorityScreensConfId()) &&
               (_scenarioScreensConfId == display.getScenarioScreensConfId()) &&
               (_suspended == display.isSuspended());
    }

public:

    /**
     */
    const std::string toString();

    /**
     */
    const uint64_t & getSerialNumber() const
    {
        return _serialNumber;
    }

    /**
     */
    const std::string getSerialNumberAsString();

    /**
     */
    void setSerialNumber(uint64_t serialNumber)
    {
        _serialNumber = serialNumber;
    }

    /**
     */
    bool isSuspended() const
    {
        return _suspended;
    }

    /**
     */
    void setSuspended(bool suspended)
    {
        _suspended = suspended;
    }

    /**
     */
    bool isOnline() const
    {
        return _online;
    }

    /**
     */
    void setOnline(bool online)
    {
        _online = online;
    }

    /**
     */
    const uint16_t & getNetworkAddress() const
    {
        return _networkAddress;
    }

    /**
     */
    void setNetworkAddress(uint16_t networkAddress)
    {
        _networkAddress = networkAddress;
    }

    /**
     */
    const uint16_t & getNumberInCasino() const
    {
        return _numberInCasino;
    }

    /**
     */
    void setNumberInCasino(uint16_t numberInCasino)
    {
        _numberInCasino = numberInCasino;
    }

    /**
     */
    const uint16_t & getGeneralOptionsConfId() const
    {
        return _generalOptionsConfId;
    }

    /**
     */
    void setGeneralOptionsConfId(uint16_t configurationId)
    {
        _generalOptionsConfId = configurationId;
    }

    /**
     */
    const uint16_t & getPriorityScreensConfId() const
    {
        return _priorityScreensConfId;
    }

    /**
     */
    void setPriorityScreensConfId(uint16_t configurationId)
    {
        _priorityScreensConfId = configurationId;
    }

    /**
     */
    const uint16_t & getScenarioScreensConfId() const
    {
        return _scenarioScreensConfId;
    }

    /**
     */
    void setScenarioScreensConfId(uint16_t configurationId)
    {
        _scenarioScreensConfId = configurationId;
    }

private:

    /**
     */
    uint16_t _networkAddress;

    /**
     */
    uint64_t _serialNumber;

    /**
     */
    uint16_t _numberInCasino;

    /**
     */
    uint16_t _generalOptionsConfId;

    /**
     */
    uint16_t _priorityScreensConfId;

    /**
     */
    uint16_t _scenarioScreensConfId;

    /**
     */
    bool _suspended;

    /**
     */
    bool _online;
};

/**
 */
typedef std::map <uint64_t, std::shared_ptr <Display> > DisplaysList;

#endif /* DISPLAY_H_ */
