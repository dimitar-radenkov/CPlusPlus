/*
 * GeneralOptionsConfiguration.h
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#ifndef GENERALOPTIONSCONFIGURATION_H_
#define GENERALOPTIONSCONFIGURATION_H_

#include <string>
#include <cstdint>
#include <map>

/**
 */
struct GeneralOptionsConfiguration
{
    /**
     */
    GeneralOptionsConfiguration():
        configurationId(0),
        decimalPoint(1),
        thousandSeparator(1),
        languageId(0),
        defaultVolumeLevel(80),
        currencyCode("EUR"),
        showAllWins(0)
    {}

    /**
     */
    GeneralOptionsConfiguration(
                  const GeneralOptionsConfiguration & generalOptions):
        configurationId(generalOptions.configurationId),
        decimalPoint(generalOptions.decimalPoint),
        thousandSeparator(generalOptions.thousandSeparator),
        languageId(generalOptions.languageId),
        defaultVolumeLevel(generalOptions.defaultVolumeLevel),
        currencyCode(generalOptions.currencyCode),
        showAllWins(generalOptions.showAllWins)
    {}

    /**
     */
    GeneralOptionsConfiguration(const int16_t configurationId,
                                const uint8_t decimalPoint,
                                const uint8_t thousandSeparator,
                                const uint16_t languageId,
                                const uint8_t defaultVolumeLevel,
                                const std::string currencyCode,
                                const uint8_t showAllWins = 0):
        configurationId(configurationId),
        decimalPoint(decimalPoint),
        thousandSeparator(thousandSeparator),
        languageId(languageId),
        defaultVolumeLevel(defaultVolumeLevel),
        currencyCode(currencyCode),
        showAllWins(showAllWins)
    {}

    /**
     */
    bool operator== (const GeneralOptionsConfiguration & configuration)
    {
        return (configurationId == configuration.configurationId) &&
               (decimalPoint == configuration.decimalPoint) &&
               (thousandSeparator == configuration.thousandSeparator) &&
               (languageId == configuration.languageId) &&
               (defaultVolumeLevel == configuration.defaultVolumeLevel) &&
               (0 == currencyCode.compare(configuration.currencyCode) &&
               (showAllWins == configuration.showAllWins));
    }

    bool IsEqual(const GeneralOptionsConfiguration & configuration)
    {
        return (decimalPoint == configuration.decimalPoint) &&
            (thousandSeparator == configuration.thousandSeparator) &&
            (languageId == configuration.languageId) &&
            (defaultVolumeLevel == configuration.defaultVolumeLevel) &&
            (0 == currencyCode.compare(configuration.currencyCode) &&
            (showAllWins == configuration.showAllWins));
    }

    /**
     */
    int16_t configurationId;

    /**
     */
    uint8_t decimalPoint;

    /**
     */
    uint8_t thousandSeparator;

    /**
     */
    uint16_t languageId;

    /**
     */
    uint8_t defaultVolumeLevel;

    /**
     */

    std::string currencyCode;

    /**
     */
    uint8_t showAllWins;
};

/**
 */
typedef std::map <const uint16_t,GeneralOptionsConfiguration> \
        GeneralOptionsConfList;

#endif /* GENERALOPTIONSCONFIGURATION_H_ */
