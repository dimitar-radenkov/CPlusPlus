/**
 * GameInfo.h
 *
 * $id$
 *
 * Description: Definition of a GameInfo structure
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <string>

/**
 */
struct GameInfo
{
    /**
     */
    GameInfo():
        gameId(0),
        denominationId(0),
        minBetPerLine(0),
        maxBetPerLine(0),
        minNumberOfLines(0),
        numberOfLines(0),
        theoreticalPercentage(0)
    {}

    /**
     */
    unsigned short gameId;
    /**
     */
    std::string gameVersion;
    /**
     */
    unsigned short denominationId;
    /**
     */
    unsigned int minBetPerLine;
    /**
     */
    unsigned int maxBetPerLine;
    /**
     */
    unsigned short minNumberOfLines;
    /**
     */
    unsigned short numberOfLines;
    /**
     */
    unsigned short theoreticalPercentage;

    /**
     */
    bool match(const GameInfo & gameInfo) const
    {
        // check only the base game identifiers
        return ( gameInfo.gameId == gameId &&
                 gameInfo.denominationId == denominationId &&
                 gameInfo.maxBetPerLine == maxBetPerLine );
    }

    /**
     */
    bool operator == (const GameInfo & gameInfo) const
    {
        return ( gameInfo.gameId == gameId &&
                 gameInfo.denominationId == denominationId &&
                 gameInfo.minBetPerLine == minBetPerLine &&
                 gameInfo.maxBetPerLine == maxBetPerLine &&
                 gameInfo.minNumberOfLines == minNumberOfLines &&
                 gameInfo.numberOfLines == numberOfLines &&
                 theoreticalPercentage == gameInfo.theoreticalPercentage);
    }

    /**
     */
    GameInfo & operator = (const GameInfo & gameInfo)
    {
        gameId = gameInfo.gameId;
        gameVersion = gameInfo.gameVersion;
        denominationId = gameInfo.denominationId;
        minBetPerLine = gameInfo.minBetPerLine;
        maxBetPerLine = gameInfo.maxBetPerLine;
        minNumberOfLines = gameInfo.minNumberOfLines;
        numberOfLines = gameInfo.numberOfLines;
        theoreticalPercentage = gameInfo.theoreticalPercentage;

        return *this;
    }
};

#endif // GAME_INFO_H

