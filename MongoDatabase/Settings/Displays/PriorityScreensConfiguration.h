/*
 * PriorityScreensConfiguration.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef PRIORITYSCREENSCONFIGURATION_H_
#define PRIORITYSCREENSCONFIGURATION_H_

#include <cstdint>
#include <map>
#include <vector>

#include "Settings/Displays/ScreenDescription.h"

/**
 */
struct PriorityScreensConfiguration
{
    /**
     */
    PriorityScreensConfiguration():
        configurationId(0)
    {}

    /**
     */
    bool operator== (const PriorityScreensConfiguration & configuration)
    {
        return (configurationId == configuration.configurationId) &&
               (screensIds == configuration.screensIds);
    }

    /**
     */
    bool IsEqual (const PriorityScreensConfiguration & configuration)
    {
        return (screensIds == configuration.screensIds);
    }

    /**
     */
    int16_t configurationId;

    /**
     */
    std::vector<uint16_t> screensIds;
};

/**
 */
typedef std::map<const uint16_t,ScreenDescription> \
        PriorityScreensList;

/**
 */
typedef std::map<const uint16_t,PriorityScreensConfiguration> \
        PriorityScreensConfList;


#endif /* PRIORITYSCREENSCONFIGURATION_H_ */
