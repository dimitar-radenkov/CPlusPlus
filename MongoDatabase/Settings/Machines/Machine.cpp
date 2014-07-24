/**
 * Machine.cpp
 *
 * $id$
 *
 * Description: Implementation of Machine class
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#include "Machine.h"

Machine::Machine(const uint64_t serialNumber,
                 const std::string name,
                 const uint16_t networkAddress,
                 const uint16_t numberInCasino,
                 const std::vector<GameInfo> gamesInfo,
                 const bool suspended):
    _serialNumber(serialNumber),
    _name(name),
    _networkAddress(networkAddress),
    _numberInCasino(numberInCasino),
    _gamesInfo(gamesInfo),
    _suspended(suspended),
    _online(false)
{
}

Machine::Machine(const Machine & machine)
{
    *this = machine;
}

Machine::~Machine()
{
}

Machine & Machine::operator = (const Machine & machine)
{
    _serialNumber = machine.getSerialNumber();
    _name.assign(machine.getName());
    _networkAddress = machine.getNetworkAddress();
    _numberInCasino = machine.getNumberInCasino();
    _gamesInfo = machine.getGamesInfoList();
    _suspended = machine.isSuspended();
    _online = machine.isOnline();

    return *this;
}

#ifdef EGT_DEBUG
void Machine::dumpValues()
{
    std::cout << "### MACHINE " << _numberInCasino << " ###" << std::endl;
    std::cout << std::endl;
    std::cout << "Serial number: " << getSerialNumberAsString() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Suspended: " <<
        (isSuspended() ? "true": "false") << std::endl;
    std::cout << "Online: " <<
        (isOnline() ? "true": "false") << std::endl;
    std::cout << "Network address: " << _networkAddress <<
        std::endl << std::endl;

    std::cout << "Games number: " << _gamesInfo.size() <<
        std::endl << std::endl;

    std::vector<GameInfo>::iterator gameIt = _gamesInfo.begin();
    for ( ; _gamesInfo.end() != gameIt; ++gameIt )
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Game Id: " << gameIt->gameId << std::endl;
        std::cout << "Game Version: " << gameIt->gameVersion << std::endl;
        std::cout << "Base Denomination: " << ((std::string)
            DenominationsList::getInstance().getMoney(gameIt->denominationId)) <<
            std::endl;
        std::cout << "Min Bet Per line: " << gameIt->minBetPerLine << std::endl;
        std::cout << "Max Bet Per line: " << gameIt->maxBetPerLine << std::endl;
        std::cout << "Min Number of lines: " <<
            gameIt->minNumberOfLines << std::endl;
        std::cout << "Max Number of lines: " <<
            gameIt->numberOfLines << std::endl;
        std::cout << "Theoretical Percentage: " <<
            ((std::string) Percent((int64_t)gameIt->theoreticalPercentage*10)) <<
            std::endl;

        std::cout << std::endl;
    }
    std::cout << "##########################" << std::endl;
}
#endif // EGT_DEBUG

const std::string Machine::getSerialNumberAsString()
{
    std::stringstream streamSerial;
    std::string strSerial;
    const unsigned int serialNumberLength = 10;

    streamSerial << _serialNumber;
    strSerial = streamSerial.str();

    if ( serialNumberLength > strSerial.size() )
    {
        // fill the missing digits in the string with zeroes
        strSerial.insert(0, serialNumberLength - strSerial.size(), '0');
    }

    // insert a dash between the digits
    strSerial.insert(strSerial.size() - serialNumberLength/2, 1, '-');

    return strSerial;
}

void Machine::addGameInfo(const GameInfo gameInfo)
{
    _gamesInfo.push_back(gameInfo);
}

void Machine::clearGamesInfo()
{
    _gamesInfo.clear();
}

const std::string Machine::toString() const
{
    std::stringstream ss;
    ss << "Machine " << this->_serialNumber << std::endl;
    ss << "name " << this->_name << std::endl;
    ss << "network address " << this->_networkAddress << std::endl;
    ss << "number in casino " << this->_numberInCasino << std::endl;
    ss << "suspended " << (this->_suspended ? "true" : "false") << std::endl;
    ss << std::endl;

    auto itGameInfo = this->_gamesInfo.begin();
    for( ; itGameInfo != this->_gamesInfo.end(); ++itGameInfo)
    {
        ss << "game id " << itGameInfo->gameId << std::endl;
        ss << "denomination id " << itGameInfo->denominationId << std::endl;
        ss << "min bet per line " << itGameInfo->minBetPerLine << std::endl;
        ss << "max bet per line " << itGameInfo->maxBetPerLine << std::endl;
        ss << "min number of lines " << itGameInfo->minNumberOfLines << std::endl;
        ss << "number of lines " << itGameInfo->numberOfLines << std::endl;
        ss << "theoretical percentage " << itGameInfo->theoreticalPercentage << std::endl;
        ss << std::endl;
    }

    return ss.str();
}
