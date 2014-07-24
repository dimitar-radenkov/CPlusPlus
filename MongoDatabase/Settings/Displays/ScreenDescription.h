/*
 * ScreenDescription.h
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#ifndef SCREENDESCRIPTION_H_
#define SCREENDESCRIPTION_H_

#include <cstdint>
#include <string>
#include <sstream>

#include "Settings/Displays/StatusLineDescription.h"
#include "Settings/Displays/Definitions/ScreenType.h"

/**
 */
class ScreenDescription
{
private:
    /**
     * The default constructor is forbidden.
     */
    ScreenDescription():
        _uniqueId(0),
        _type(UnknownScreenType),
        _jackpotGroupId(0),
        _index(0),
        _stayVisibleTime(0),
        _repeatSoundInterval(0),
        _volumeLevel(-1)
    {}

public:
    /**
     */
    ScreenDescription(const uint16_t uniqueId,
                      const ScreenType type,
                      const std::string label,
                      const uint16_t jackpotGroupId,
                      const uint16_t index,
                      const uint32_t stayVisibleTime,
                      const uint32_t repeatSoundInterval,
                      const int16_t volumeLevel,
                      const StatusLineDescription statusLine);
    /**
     */
    ScreenDescription(const uint16_t uniqueId,
                      const ScreenType type,
                      const std::string label,
                      const uint16_t jackpotGroupId,
                      const uint16_t index,
                      const uint32_t stayVisibleTime,
                      const uint32_t repeatSoundInterval,
                      const int16_t volumeLevel);

    /**
     */

    ScreenDescription(const ScreenDescription & screenDescription);

    /**
     */
    ScreenDescription(
            const uint16_t uniqueId,
            const ScreenType type);

    /**
     */
    ~ScreenDescription();

    /**
     */
    bool operator== (const ScreenDescription & screen)
    {
        return (_uniqueId == screen.uniqueId()) &&
               (_type == screen.type()) &&
               (0 == _label.compare(screen.label())) &&
               (_jackpotGroupId == screen.jackpotGroupId()) &&
               (_index == screen.index()) &&
               (_stayVisibleTime == screen.stayVisibleTime()) &&
               (_repeatSoundInterval == screen.repeatSoundInterval()) &&
               (_volumeLevel == screen.volumeLevel()) &&
               (_statusLine == screen.statusLine());
    }

    /**
     */
    bool IsEqual (const ScreenDescription & screen)
    {
        return (_type == screen.type()) &&
               (0 == _label.compare(screen.label())) &&
               (_jackpotGroupId == screen.jackpotGroupId()) &&
               (_index == screen.index()) &&
               (_stayVisibleTime == screen.stayVisibleTime()) &&
               (_repeatSoundInterval == screen.repeatSoundInterval()) &&
               (_volumeLevel == screen.volumeLevel()) &&
               (_statusLine == screen.statusLine());
    }

    /**
     */
    const uint16_t & uniqueId() const;

    /**
     */
    const ScreenType & type() const;

    /**
     */
    const std::string & label() const;

    /**
     */
    const uint16_t & jackpotGroupId() const;

    /**
     */
    const uint16_t & index() const;

    /**
     */
    const uint32_t & stayVisibleTime() const;

    /**
     */
    const uint32_t & repeatSoundInterval() const;

    /**
     */
    const int16_t & volumeLevel() const;

    /**
     */
    const StatusLineDescription & statusLine() const;


    std::string toString() const
    {

        std::stringstream ss;

        ss << "@@@@@    SCREEN DESCRIPTION     @@@@@"
            << std::endl << "Screen Id:" << _uniqueId << std::endl << "Type:"
            << _type << std::endl << "Label: " << _label << std::endl
            << "Jackpot Group Id:" << _jackpotGroupId
            << std::endl << "Index:" << _index << std::endl
            << "Stay Visible Time:" << _stayVisibleTime << std::endl
            << "Repeat Sound Interval:" << _repeatSoundInterval << std::endl
            << "Volume Level:" << _volumeLevel << std::endl
            << "Status Line Appearance:" << _statusLine.appearProgramType
            << std::endl << "Status Line Disappearance:"
            << _statusLine.disappearProgramType << std::endl
            << "Status Line Visible Time:" << _statusLine.stayVisibleTime
            << std::endl << "Status Line Time between messages:"
            << _statusLine.timeBetweenMessages << std::endl
            << "Status Line Text Configuration:" << _statusLine.textsConfId
            << std::endl;

        return ss.str();
    }

private:
    /**
     */
    uint16_t _uniqueId;

    /**
     */
    ScreenType _type;

    /**
     */
    std::string _label;

    /**
     */
    uint16_t _jackpotGroupId;

    /**
     */
    uint16_t _index;

    /**
     */
    uint32_t _stayVisibleTime;

    /**
     */
    uint32_t _repeatSoundInterval;

    /**
     */
    int16_t _volumeLevel;

    /**
     */
    StatusLineDescription _statusLine;
};
#endif /* SCREENDESCRIPTION_H_ */
