/**
 * Machine.h
 *
 * $id$
 *
 * Description: Definition of a Machine class. Describes the assigned
 *              serial number, max bet, number of lines and so on.
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef MACHINE_H
#define MACHINE_H

#include "GameInfo.h"

#include <memory>
#include <map>
#include <vector>
#include <sstream>

/**
 */
class Machine
{
    /**
     * The default constructor is forbidden.
     */
    Machine()
    {
    	this->_serialNumber = 0;
    	this->_name = "";
    	this->_networkAddress = 0;
    	this->_numberInCasino = 0;
    	this->_gamesInfo = std::vector<GameInfo>();
    	this->_suspended = true;
    	this->_online = false;
    }

public:
    /**
     */
    Machine(const uint64_t serialNumber,
            const std::string name,
            const uint16_t networkAddress,
            const uint16_t numberInCasino,
            const std::vector<GameInfo> gamesInfo,
            const bool suspended = false);

    /**
     */
    Machine(const Machine & machine);

    /**
     */
    ~Machine();

    /**
     */
    Machine & operator = (const Machine & machine);

    /**
     */
    bool operator== (const Machine & machine)
    {
        return (_serialNumber == machine.getSerialNumber()) &&
               (0 == _name.compare(machine.getName())) &&
               (_networkAddress == machine.getNetworkAddress()) &&
               (_numberInCasino == machine.getNumberInCasino()) &&
               (_gamesInfo == machine.getGamesInfoList()) &&
               (_suspended == machine.isSuspended());
    }


#ifdef EGT_DEBUG
    /**
     */
    void dumpValues();
#endif // EGT_DEBUG

public:
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
    const std::string & getName() const
    {
        return _name;
    }

    /**
     */
    void setName(const std::string name)
    {
        _name = name;
    }

    /**
     */
    const uint16_t & getNetworkAddress() const
    {
        return _networkAddress;
    }

    /**
     */
    const uint16_t & getNumberInCasino() const
    {
        return _numberInCasino;
    }

    /**
     */
    const std::vector<GameInfo> & getGamesInfoList() const
    {
        return _gamesInfo;
    }

    /**
     */
    void setGamesInfoList(const std::vector<GameInfo> & gameInfoList)
    {
        _gamesInfo = gameInfoList;
    }

    /**
     */
    void addGameInfo(const GameInfo gameInfo);

    /**
     */
    void clearGamesInfo();

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


    const std::string toString() const;

private:
    /**
     */
    uint64_t _serialNumber;

    /**
     */
    std::string _name;

    /**
     */
    uint16_t _networkAddress;

    /**
     */
    uint16_t _numberInCasino;

    /**
     */
    std::vector<GameInfo> _gamesInfo;

    /**
     */
    bool _suspended;

    /**
     */
    bool _online;
};

/**
 */
typedef std::map < uint64_t, std::shared_ptr<Machine> > MachinesList;

#endif // MACHINE_H
