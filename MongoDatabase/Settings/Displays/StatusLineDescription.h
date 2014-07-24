/*
 * StatusLineDescription.h
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#ifndef STATUSLINEDESCRIPTION_H_
#define STATUSLINEDESCRIPTION_H_

#include <cstdint>

#include "Settings/Displays/Definitions/StatusLineType.h"
#include "Settings/Displays/Definitions/StatusLineTextProgramType.h"

/**
 */
struct StatusLineDescription
{
    /**
     */
    StatusLineDescription():
        type(NoneStatusLineType),
        appearProgramType(StaticTextProgramType),
        disappearProgramType(StaticTextProgramType),
        stayVisibleTime(1000),
        timeBetweenMessages(500),
        textsConfId(0)
    {
    }

    /**
     */
    StatusLineDescription(const StatusLineType type,
                          const StatusLineTextProgramType appearProgramType,
                          const StatusLineTextProgramType disappearProgramType,
                          const uint32_t stayVisibleTime,
                          const uint32_t timeBetweenMessages,
                          const uint16_t textsConfId):
        type(type),
        appearProgramType(appearProgramType),
        disappearProgramType(disappearProgramType),
        stayVisibleTime(stayVisibleTime),
        timeBetweenMessages(timeBetweenMessages),
        textsConfId(textsConfId)
    {
    }

    /**
     */
    StatusLineDescription(const StatusLineDescription & statusLineDesc):
        type(statusLineDesc.type),
        appearProgramType(statusLineDesc.appearProgramType),
        disappearProgramType(statusLineDesc.disappearProgramType),
        stayVisibleTime(statusLineDesc.stayVisibleTime),
        timeBetweenMessages(statusLineDesc.timeBetweenMessages),
        textsConfId(statusLineDesc.textsConfId)
    {
    }

    /**
     */
    bool operator== (const StatusLineDescription & statusLine)
    {
        return (type == statusLine.type) &&
               (appearProgramType == statusLine.appearProgramType) &&
               (disappearProgramType == statusLine.disappearProgramType) &&
               (stayVisibleTime == statusLine.stayVisibleTime) &&
               (timeBetweenMessages == statusLine.timeBetweenMessages) &&
               (textsConfId == statusLine.textsConfId);
    }

    /**
     */
    bool IsEqual (const StatusLineDescription & statusLine)
    {
        return (type == statusLine.type) &&
               (appearProgramType == statusLine.appearProgramType) &&
               (disappearProgramType == statusLine.disappearProgramType) &&
               (stayVisibleTime == statusLine.stayVisibleTime) &&
               (timeBetweenMessages == statusLine.timeBetweenMessages) &&
               (textsConfId == statusLine.textsConfId);
    }

    /**
     */
    StatusLineType type;

    /**
     */
    StatusLineTextProgramType appearProgramType;

    /**
     */
    StatusLineTextProgramType disappearProgramType;

    /**
     */
    uint32_t stayVisibleTime;

    /**
     */
    uint32_t timeBetweenMessages;

    /**
     */
    uint16_t textsConfId;
};


#endif /* STATUSLINEDESCRIPTION_H_ */
