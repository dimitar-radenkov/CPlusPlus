/*
 * Jackpot.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "Jackpot.h"

Jackpot::Jackpot() :
    type(JackpotType::UnknownJackpot),
    subType(0),
    name("No name"),
    gameId(0),
    protocolType(ProtocolType::Unknown),
    multilevelsNumberLimit(0),
    internalId(0),
    externalId(0),
    sessionId(0),
    internalNetworkId(0),
    externalNetworkId(0)
{
    // TODO Auto-generated constructor stub
}

Jackpot::Jackpot(
        const JackpotType jackpotType,
        const uint16_t jackpotSubType,
        const std::string name,
        const uint16_t gameId,
        const ProtocolType protocolType,
        const uint16_t multilevelsLimit,
        const uint32_t internalId,
        const uint32_t externalId,
        const uint32_t sessionId,
        const uint32_t internalNetworkId,
        const uint32_t externalNetworkId) :
    type(jackpotType),
    subType(jackpotSubType),
    name(name),
    gameId(gameId),
    protocolType(protocolType),
    multilevelsNumberLimit(multilevelsLimit),
    internalId(internalId),
    externalId(externalId),
    sessionId(sessionId),
    internalNetworkId(internalNetworkId),
    externalNetworkId(externalNetworkId)
{
    // TODO Auto-generated constructor stub
}

Jackpot::~Jackpot()
{
    // TODO Auto-generated destructor stub
}

void Jackpot::addMultilevel(const uint32_t number,
                            const uint32_t multilevelId)
{
    std::map<uint32_t, uint32_t>::iterator miltilevelIt =
        multilevels.begin();
    // check about duplication
    for ( ; multilevels.end() != miltilevelIt; ++miltilevelIt )
    {
        if ( miltilevelIt->first == number ||
             miltilevelIt->second == multilevelId )
        {
            // multilevel number or id already exist in the group
            throw utils::CommonException("The multilevel already exist in that "
                                  "progressive jackpot group.", 0);
        }
    }

    if ( multilevels.size() >= multilevelsNumberLimit )
    {
        // we can't add anymore multilevels
        throw utils::CommonException("Multilevels number limit overflow.", 0);
    }

    // insert current multilevel into the progressive jackpot group
    multilevels.insert(std::make_pair(number, multilevelId));
}

bool Jackpot::deleteMultilevelByNumber(const uint32_t num)
{
    std::map<uint32_t, uint32_t>::iterator multilevel;

    multilevel = multilevels.find(num);
    if ( multilevels.end() != multilevel )
    {
        // delete the multilevel
        multilevels.erase(multilevel);

        return true;
    }
    // the multilevel wasn't found
    return false;
}

void Jackpot::deleteAllMultilevels()
{
    this->multilevels.clear();
}

bool Jackpot::deleteMultilevelById(const uint32_t multilevelId)
{
    std::map<uint32_t, uint32_t>::iterator multilevel =
        multilevels.begin();

    for ( ; multilevels.end() != multilevel; ++multilevel )
    {
        if ( multilevelId == multilevel->second )
        {
            // delete the multilevel
            multilevels.erase(multilevel);

            return true;
        }
    }
    // the multilevel wasn't found
    return false;
}

void Jackpot::attachMachinesGroup(const uint32_t machinesGroupId)
{
    attachedMachinesGroups.insert(machinesGroupId);
}

bool Jackpot::detachMachinesGroup(const uint32_t machinesGroupId)
{
    std::set<uint32_t>::iterator machinesGroupIt =
        attachedMachinesGroups.find(machinesGroupId);
    if ( attachedMachinesGroups.end() != machinesGroupIt )
    {
        // remove current machine group from the list
        attachedMachinesGroups.erase(machinesGroupIt);

        return true;
    }

    // machines group doesn't exist in the list
    return false;
}

void Jackpot::detachAllMachinesGroups()
{
    this->attachedMachinesGroups.clear();
}

std::string Jackpot::toString()
{
    std::stringstream ss;

    ss << "##############################################" << std::endl;
    ss << "########### JACKPOT (" << internalId << ", " <<
        externalId << ") ###########" << std::endl;
    ss << "##############################################" << std::endl;
    ss << std::endl;
    ss << "Type: " << type << std::endl;
    ss << "Name: " << name << std::endl;
    ss << "Multilevels number limit: " <<
        multilevelsNumberLimit << std::endl;
    ss << "Internal Network ID: " << getInternalNetworkId() << std::endl;
    ss << "External Network ID: " << getExternalNetworkId() << std::endl;
    ss << std::endl;

    ss << "Multilevels : ";
    auto multilevelIt = multilevels.begin();
    for ( ; multilevels.end() != multilevelIt; multilevelIt++ )
    {
        ss << "  " << multilevelIt->second;
    }

    ss << std::endl;
    ss << "##############################################" << std::endl;
    ss << std::endl;

    return ss.str();
}

const JackpotType Jackpot::getType() const
{
    return this->type;
}

uint16_t Jackpot::getSubType() const
{
    return this->subType;
}

void Jackpot::setSubType(uint16_t subType)
{
    this->subType = subType;
}

const std::string& Jackpot::getName() const
{
    return this->name;
}

void Jackpot::setName(const std::string& name)
{
    this->name = name;
}

uint16_t Jackpot::getGameId() const
{
    return this->gameId;
}

void Jackpot::setGameId(uint16_t gameId)
{
    this->gameId = gameId;
}

const ProtocolType& Jackpot::getProtocolType() const
{
    return this->protocolType;
}

void Jackpot::setProtocolType(const ProtocolType protocolType)
{
    this->protocolType = protocolType;
}

const uint16_t Jackpot::getMultilevelsNumberLimit() const
{
    return this->multilevelsNumberLimit;
}

uint32_t Jackpot::getInternalId() const
{
    return this->internalId;
}

void Jackpot::setInternalId(uint32_t internalId)
{
    this->internalId = internalId;
}

uint32_t Jackpot::getExternalId() const
{
    return this->externalId;
}

void Jackpot::setExternalId(uint32_t externalId)
{
    this->externalId = externalId;
}

uint32_t Jackpot::getSessionId() const
{
    return this->sessionId;
}

void Jackpot::setSessionId(uint32_t sessionId)
{
    this->sessionId = sessionId;
}

uint32_t Jackpot::getInternalNetworkId() const
{
    return this->internalNetworkId;
}

void Jackpot::setInternalNetworkId(uint32_t internalNetworkId)
{
    this->internalNetworkId = internalNetworkId;
}

uint32_t Jackpot::getExternalNetworkId() const
{
    return this->externalNetworkId;
}

void Jackpot::setExternalNetworkId(uint32_t externalNetworkId)
{
    this->externalNetworkId = externalNetworkId;
}

const std::map<uint32_t, uint32_t>& Jackpot::getMultilevels() const
{
    return this->multilevels;
}

const std::set<uint32_t>& Jackpot::getAttachedMachinesGroupsIds() const
{
    return this->attachedMachinesGroups;
}


