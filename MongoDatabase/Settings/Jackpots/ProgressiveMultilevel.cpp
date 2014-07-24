
/**
 * ProgressiveMultilevel.cpp
 *
 * $id$
 *
 * Description: Implementation of ProgressiveMultilevel class
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#include "ProgressiveMultilevel.h"

ProgressiveMultilevel::ProgressiveMultilevel(
                       const MultilevelType type,
                       const uint16_t levelsLimit,
                       const uint32_t internalId,
                       const uint32_t externalId,
                       const uint32_t sessionId):
    type(type),
    levelsNumberLimit(levelsLimit),
    internalId(internalId),
    externalId(externalId),
    sessionId(sessionId)
{
    this->levels.clear();
}

ProgressiveMultilevel::~ProgressiveMultilevel()
{
}

ProgressiveMultilevel & ProgressiveMultilevel::operator= (
                        const ProgressiveMultilevel & multilevel)
{
    this->name = multilevel.getName();

    return *this;
}

void ProgressiveMultilevel::resetLevels()
{
    levels.clear();
}

void ProgressiveMultilevel::addLevel(const uint32_t internalId)
{
    if ( this->levelsNumberLimit <= this->levels.size() )
    {
        // error! the multilevel is full
        throw utils::CommonException("Attempt to add level in a full multilevel.", 0);
    }

    std::set<uint32_t>::iterator levelIt = this->levels.begin();
    if ( this->levels.end() != this->levels.find(internalId) )
    {
        // error! the multilevel contains level with the same internal id
        throw utils::CommonException("Level with the same internal id already"
                              "exists in the multilevel.", 0);
    }
    // we can add the level into the multilevel now
    this->levels.insert(internalId);
}

bool ProgressiveMultilevel::deleteLevel(const uint32_t internalId)
{
    std::set<uint32_t>::iterator levelIt = this->levels.find(internalId);

    if ( this->levels.end() == levelIt )
    {
        // level with the specified internal id wasn't found in this multilevel
        return false;
    }

    // delete the level from the list
    this->levels.erase(levelIt);

    return true;
}

const std::string ProgressiveMultilevel::toString() const
{
    std::stringstream ss;

    ss << "########### MULTILEVEL (" << this->internalId << ", " <<
        this->externalId << ") ###########" << std::endl;
    ss << "##############################################" << std::endl;
    ss << std::endl;
    switch (this->type)
    {
        case MultilevelType::InternalMultilevel:
            ss << "Type: internal multilevel" << std::endl;
            break;
        case MultilevelType::ExternalMultilevel:
            ss << "Type: external multilevel" << std::endl;
            break;
        default:
            ss << "Type: unknown multilevel" << std::endl;
    }
    ss << "Levels number limit: " << this->levelsNumberLimit << std::endl;
    ss << "Name: " << this->name << std::endl;
    ss << std::endl;

    ss << "Levels : " ;
    auto levelIt = this->levels.begin();
    for ( ; this->levels.end() != levelIt; ++levelIt )
    {
        ss << "  " << *levelIt;
    }

    ss << "##############################################" << std::endl;
    ss << std::endl;

    return ss.str();
}

uint32_t ProgressiveMultilevel::getExternalId() const
{
    return this->externalId;
}

void ProgressiveMultilevel::setExternalId(uint32_t externalId)
{
    this->externalId = externalId;
}

uint32_t ProgressiveMultilevel::getInternalId() const
{
    return this->internalId;
}

void ProgressiveMultilevel::setInternalId(uint32_t internalId)
{
    this->internalId = internalId;
}

const std::set<uint32_t>& ProgressiveMultilevel::getLevelsList() const
{
    return this->levels;
}

void ProgressiveMultilevel::setLevelsList(const std::set<uint32_t>& levels)
{
    this->levels = levels;
}

const uint16_t ProgressiveMultilevel::getLevelsNumberLimit() const
{
    return this->levelsNumberLimit;
}

const std::string& ProgressiveMultilevel::getName() const
{
    return this->name;
}

void ProgressiveMultilevel::setName(const std::string& name)
{
    this->name = name;
}

uint32_t ProgressiveMultilevel::getSessionId() const
{
    return this->sessionId;
}

void ProgressiveMultilevel::setSessionId(uint32_t sessionId)
{
    this->sessionId = sessionId;
}

const MultilevelType ProgressiveMultilevel::getType() const
{
    return this->type;
}
