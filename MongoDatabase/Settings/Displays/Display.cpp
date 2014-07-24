/*
 * Display.cpp
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#include "Display.h"


Display::Display(
        const uint16_t networkAddress,
        const uint64_t serialNumber,
        const uint16_t numberInCasino,
        const uint16_t generalOptionsConfId,
        const uint16_t priorityScreensConfId,
        const uint16_t scenarioScreensConfId,
        const bool suspended) :
    _networkAddress(networkAddress),
    _serialNumber(serialNumber),
    _numberInCasino(numberInCasino),
    _generalOptionsConfId(generalOptionsConfId),
    _priorityScreensConfId(priorityScreensConfId),
    _scenarioScreensConfId(scenarioScreensConfId),
    _suspended(suspended),
    _online(false)
{

}

Display::Display(const Display & display)
{
    *this = display;
}

Display::~Display()
{

}

Display & Display::operator = (const Display & display)
{
    _networkAddress = display.getNetworkAddress();
    _serialNumber = display.getSerialNumber();
    _numberInCasino = display.getNumberInCasino();
    _generalOptionsConfId = display.getGeneralOptionsConfId();
    _priorityScreensConfId = display.getPriorityScreensConfId();
    _scenarioScreensConfId = display.getScenarioScreensConfId();
    _suspended = display.isSuspended();
    _online = display.isOnline();

    return *this;
}

const std::string Display::getSerialNumberAsString()
{
    std::stringstream streamSerial;
    std::string strSerial;
    const uint16_t serialNumberLength = 10;

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

const std::string Display::toString()
{
    std::stringstream ss;

    ss << "### DISPLAY " << _numberInCasino << " ###" << std::endl;
    ss << std::endl;
    ss << "Serial number: " << getSerialNumberAsString() << std::endl;
    ss << "Suspended: " <<
        (isSuspended() ? "true": "false") << std::endl;
    ss << "Online: " <<
        (isOnline() ? "true": "false") << std::endl;
    ss << "Network address: " << _networkAddress << std::endl;
    ss << "General options conf id: " << _generalOptionsConfId
        << std::endl;
    ss << "Priority screens conf id: " << _priorityScreensConfId
        << std::endl;
    ss << "Scenario screens conf id: " << _scenarioScreensConfId
        << std::endl;

    ss << "##########################" << std::endl;

    return ss.str();
}

