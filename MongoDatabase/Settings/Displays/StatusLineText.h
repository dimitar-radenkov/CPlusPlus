/*
 * StatusLineText.h
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#ifndef STATUSLINETEXT_H_
#define STATUSLINETEXT_H_

#include <cstdint>
#include <string>
#include <map>

/**
 */
struct StatusLineText
{
    /**
     */
    StatusLineText(const uint16_t id = 0, std::string text = ""):
        uniqueId(id),
        messageText(text)
    {}

    /**
     */
    bool operator== (const StatusLineText & text)
    {
        return (uniqueId == text.uniqueId) &&
               (0 == messageText.compare(text.messageText));
    }

    /**
     */
    bool IsEqual(const StatusLineText & text)
    {
        return (0 == messageText.compare(text.messageText));
    }

    /**
     */
    uint16_t uniqueId;

    /**
     */
    std::string messageText;
};

/**
 */
typedef std::map<uint16_t,StatusLineText> StatusLineTextsList;

#endif /* STATUSLINETEXT_H_ */
