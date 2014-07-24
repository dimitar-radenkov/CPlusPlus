/*
 * ScreenDescription.cpp
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#include "ScreenDescription.h"

ScreenDescription::ScreenDescription(
                  const uint16_t uniqueId,
                  const ScreenType type,
                  const std::string label,
                  const uint16_t jackpotGroupId,
                  const uint16_t index,
                  const uint32_t stayVisibleTime,
                  const uint32_t repeatSoundInterval,
                  const int16_t volumeLevel,
                  const StatusLineDescription statusLine):
        _uniqueId(uniqueId),
        _type(type),
        _label(label),
        _jackpotGroupId(jackpotGroupId),
        _index(index),
        _stayVisibleTime(stayVisibleTime),
        _repeatSoundInterval(repeatSoundInterval),
        _volumeLevel(volumeLevel),
        _statusLine(statusLine)
{

}

ScreenDescription::ScreenDescription(
                  const uint16_t uniqueId,
                  const ScreenType type,
                  const std::string label,
                  const uint16_t jackpotGroupId,
                  const uint16_t index,
                  const uint32_t stayVisibleTime,
                  const uint32_t repeatSoundInterval,
                  const int16_t volumeLevel):
        _uniqueId(uniqueId),
        _type(type),
        _label(label),
        _jackpotGroupId(jackpotGroupId),
        _index(index),
        _stayVisibleTime(stayVisibleTime),
        _repeatSoundInterval(repeatSoundInterval),
        _volumeLevel(volumeLevel)
{

}

ScreenDescription::ScreenDescription(
        const ScreenDescription & screenDescription):
    _uniqueId(screenDescription.uniqueId()),
    _type(screenDescription.type()),
    _label(screenDescription.label()),
    _jackpotGroupId(screenDescription.jackpotGroupId()),
    _index(screenDescription.index()),
    _stayVisibleTime(screenDescription.stayVisibleTime()),
    _repeatSoundInterval(screenDescription.repeatSoundInterval()),
    _volumeLevel(screenDescription.volumeLevel()),
    _statusLine(screenDescription.statusLine())
{

}

ScreenDescription::ScreenDescription(
        const uint16_t uniqueId,
        const ScreenType type):
     _uniqueId(uniqueId),
     _type(type),
     _label("Unknown Screen"),
     _jackpotGroupId(0),
     _index(0),
     _stayVisibleTime(0),
     _repeatSoundInterval(0),
     _volumeLevel(-1)
 {

 }

ScreenDescription::~ScreenDescription()
{
    // TODO Auto-generated destructor stub
}

const uint16_t & ScreenDescription::uniqueId() const
{
    return _uniqueId;
}

/**
 */
const ScreenType & ScreenDescription::type() const
{
    return _type;
}

/**
 */
const std::string & ScreenDescription::label() const
{
    return _label;
}

/**
 */
const uint16_t & ScreenDescription::jackpotGroupId() const
{
    return _jackpotGroupId;
}

/**
 */
const uint16_t & ScreenDescription::index() const
{
    return _index;
}

/**
 */
const uint32_t & ScreenDescription::stayVisibleTime() const
{
    return _stayVisibleTime;
}

/**
 */
const uint32_t & ScreenDescription::repeatSoundInterval() const
{
    return _repeatSoundInterval;
}

/**
 */
const int16_t & ScreenDescription::volumeLevel() const
{
    return _volumeLevel;
}

/**
 */
const StatusLineDescription & ScreenDescription::statusLine() const
{
    return _statusLine;
}



