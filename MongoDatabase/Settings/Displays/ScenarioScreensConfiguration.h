/*
 * ScenarioScreensConfiguration.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef SCENARIOSCREENSCONFIGURATION_H_
#define SCENARIOSCREENSCONFIGURATION_H_

#include <cstdint>
#include <map>
#include <vector>

#include "Settings/Displays/ScreenDescription.h"

/**
 */
struct ScenarioScreensConfiguration
{
    /**
     */
    ScenarioScreensConfiguration():
        configurationId(0)
    {}

    /**
     */
    bool operator== (const ScenarioScreensConfiguration & configuration)
    {
        return (configurationId == configuration.configurationId) &&
               (screensIds == configuration.screensIds);
    }

    /**
     */
    bool IsEqual (const ScenarioScreensConfiguration & configuration)
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
        ScenarioScreensList;

/**
 */
typedef std::map<const uint16_t,ScenarioScreensConfiguration> \
        ScenarioScreensConfList;



#endif /* SCENARIOSCREENSCONFIGURATION_H_ */
