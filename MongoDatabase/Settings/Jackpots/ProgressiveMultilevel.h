/**
 * ProgressiveMultilevel.h
 *
 * $id$
 *
 * Description: Base class definition of a progressive multilevel. Represents
 *              the real meaning of the term "level" (including all its
 *              denominations).
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef PROGRESSIVE_MULTILEVEL_H
#define PROGRESSIVE_MULTILEVEL_H


#include <memory>
#include <set>

#include "ProgressiveLevel.h"
#include "Utils/CommonException.h"
#include "Definitions/MultilevelType.h"

/**
 */
class ProgressiveMultilevel
{
    /**
     * The default constructor is forbidden.
     */
    ProgressiveMultilevel():
        type(MultilevelType::UnknownMultilevel),
        levelsNumberLimit(0),
        internalId(0),
        externalId(0),
        sessionId(0)
    {}



public:
    /**
     */
    ProgressiveMultilevel(const MultilevelType type,
                          const uint16_t levelsLimit,
                          const uint32_t internalId,
                          const uint32_t externalId,
                          const uint32_t sessionId);

    /**
     */
    virtual ProgressiveMultilevel & operator= (
                                    const ProgressiveMultilevel & multilevel);

    /**
     */
    virtual bool operator== (const ProgressiveMultilevel & multilevel)
    {
        return (type == multilevel.getType()) &&
               (levelsNumberLimit == multilevel.getLevelsNumberLimit()) &&
               (internalId == multilevel.getInternalId()) &&
               (externalId == multilevel.getExternalId()) &&
               (sessionId == multilevel.getSessionId()) &&
               (0 == name.compare(multilevel.getName())) &&
               (levels == multilevel.getLevelsList());
    }

    /**
     */
    virtual ~ProgressiveMultilevel();

    /**
     */
    void resetLevels();

    /**
     */
    void addLevel(const uint32_t internalId);

    /**
     */
    bool deleteLevel(const uint32_t internalId);

    /**
     */
    const std::string toString() const;

public:

    /**
     */
    const MultilevelType getType() const;

    /**
     */
    uint32_t getExternalId() const;

    /**
     */
    void setExternalId(uint32_t externalId);

    /**
     */
    uint32_t getInternalId() const;

    /**
     */
    void setInternalId(uint32_t internalId);

    /**
     */
    const std::set<uint32_t>& getLevelsList() const;

    /**
     */
    void setLevelsList(const std::set<uint32_t>& levels);

    /**
     */
    const uint16_t getLevelsNumberLimit() const;

    /**
     */
    const std::string& getName() const;

    /**
     */
    void setName(const std::string& name);

    /**
     */
    uint32_t getSessionId() const;

    /**
     */
    void setSessionId(uint32_t sessionId);


protected:
    /**
     */
    const MultilevelType type;

    /**
     */
    const uint16_t levelsNumberLimit;

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
    std::string name;

    /**
     */
    std::set<uint32_t> levels;

};

/**
 */
typedef std::map <unsigned int, std::shared_ptr <ProgressiveMultilevel> >
                 ProgressiveMultilevelsList;

#endif // PROGRESSIVE_MULTILEVEL_H
