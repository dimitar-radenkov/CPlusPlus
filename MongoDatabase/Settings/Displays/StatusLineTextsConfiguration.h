/*
 * StatusLineTextConfiguration.h
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#ifndef STATUSLINETEXTCONFIGURATION_H_
#define STATUSLINETEXTCONFIGURATION_H_

#include <map>
#include <vector>
#include <cstdint>

/**
 */
struct StatusLineTextsConfiguration
{
    /**
     */
    bool operator== (const StatusLineTextsConfiguration & configuration)
    {
        return (uniqueId == configuration.uniqueId) &&
               (messagesIds == configuration.messagesIds);
    }

    /**
     */
    bool IsEqual (const StatusLineTextsConfiguration & configuration)
    {
        return (messagesIds == configuration.messagesIds);
    }

    /**
     */
    uint16_t uniqueId;

    /**
     */
    std::vector<uint16_t> messagesIds;
};

/**
 */
typedef std::map<uint16_t,StatusLineTextsConfiguration> StatusLineTextsConfList;

#endif /* STATUSLINETEXTCONFIGURATION_H_ */
