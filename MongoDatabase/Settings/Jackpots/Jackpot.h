/*
 * Jackpot.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef JACKPOT_H_
#define JACKPOT_H_

#include <memory>
#include <cstdint>
#include <map>
#include <set>
#include <string>

#include "Settings/Jackpots/Definitions/JackpotType.h"
#include "Settings/Jackpots/Definitions/ProtocolType.h"
#include "Settings/Jackpots/ProgressiveMultilevel.h"

class Jackpot
{
    /**
     * The default constructor is forbidden.
     */
    Jackpot();

public:
    /**
     */
    Jackpot(const JackpotType jackpotType,
            const uint16_t jackpotSubType,
            const std::string name,
            const uint16_t gameId,
            const ProtocolType protocolType,
            const uint16_t multilevelsLimit,
            const uint32_t internalId,
            const uint32_t externalId,
            const uint32_t sessionId,
            const uint32_t internalNetworkId,
            const uint32_t externalNetworkId);

    /**
     */
    ~Jackpot();

    /**
     */
    Jackpot & operator= (
          const Jackpot & group);

    /**
     */
    bool operator== (const Jackpot & group)
    {
        return (getType() == group.getType()) &&
               (getSubType() == group.getSubType()) &&
               (getName() == group.getName()) &&
               (getGameId() == group.getGameId()) &&
               (getProtocolType() == group.getProtocolType()) &&
               (getMultilevelsNumberLimit() == group.getMultilevelsNumberLimit()) &&
               (getInternalId() == group.getInternalId()) &&
               (getExternalId() == group.getExternalId()) &&
               (getSessionId() == group.getSessionId()) &&
               (getInternalNetworkId() == group.getInternalNetworkId()) &&
               (getExternalNetworkId() == group.getExternalNetworkId()) &&
               (getMultilevels() == group.getMultilevels()) &&
               (getAttachedMachinesGroupsIds() ==
                group.getAttachedMachinesGroupsIds());
    }

public:
    /**
     */
    void addMultilevel(const uint32_t number, const uint32_t multilevelId);

    /**
     */
    bool deleteMultilevelByNumber(const uint32_t num);

    /**
     */
    bool deleteMultilevelById(const uint32_t multilevelId);

    /**
     */
    void deleteAllMultilevels();

    /**
     */
    const std::map<uint32_t,uint32_t> & getMultilevelsList() const;

    /**
     */
    void attachMachinesGroup(const uint32_t machinesGroupId);

    /**
     */
    bool detachMachinesGroup(const uint32_t machinesGroupId);

    /**
     */
    void detachAllMachinesGroups();

    /**
     */
    std::string toString();

public:

    /**
     */
    const JackpotType getType() const;

    /**
     */
    uint16_t getSubType() const;

    /**
     */
    void setSubType(uint16_t subType);

    /**
     */
    const std::string& getName() const;

    /**
     */
    void setName(const std::string& name);

    /**
     */
    const ProtocolType& getProtocolType() const;

    /**
     */
    void setProtocolType(const ProtocolType protocolType);

    /**
     */
    uint16_t getGameId() const;

    /**
     */
    void setGameId(uint16_t gameId);

    /**
     */
    const uint16_t getMultilevelsNumberLimit() const;

    /**
     */
    uint32_t getInternalId() const;

    /**
     */
    void setInternalId(uint32_t externalId);

    /**
     */
    uint32_t getExternalId() const;

    /**
     */
    void setExternalId(uint32_t externalId);

    /**
     */
    uint32_t getSessionId() const;

    /**
     */
    void setSessionId(uint32_t sessionId);

    /**
     */
    uint32_t getInternalNetworkId() const;

    /**
     */
    void setInternalNetworkId(uint32_t internalNetworkId);

    /**
     */
    uint32_t getExternalNetworkId() const;

    /**
     */
    void setExternalNetworkId(uint32_t externalNetworkId);

    /**
     */
    const std::map<uint32_t, uint32_t>& getMultilevels() const;

    /**
     */
    const std::set<uint32_t>& getAttachedMachinesGroupsIds() const;


protected:

    /**
     */
    const JackpotType type;

    /**
     */
    uint16_t subType;

    /**
     */
    std::string name;

    /**
     */
    uint16_t gameId;

    /**
     */
    ProtocolType protocolType;

    /**
     */
    const uint16_t multilevelsNumberLimit;

    /**
     */
    uint32_t internalId;

    /**
     */
    uint32_t externalId;

    /**
     */
    uint32_t sessionId;

    /**
     */
    uint32_t internalNetworkId;

    /**
     */
    uint32_t externalNetworkId;

    /**
     */
    std::map<uint32_t, uint32_t> multilevels;

    /**
     */
    std::set<uint32_t> attachedMachinesGroups;
};

/**
 */
typedef std::map <uint32_t, std::shared_ptr<Jackpot> >
        JackpotList;

#endif /* JACKPOT_H_ */
