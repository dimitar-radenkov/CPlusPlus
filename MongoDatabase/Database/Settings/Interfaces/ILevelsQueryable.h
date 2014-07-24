/*
 * ILevelsQueryable.h
 *
 *  Created on: May 20, 2014
 *      Author: root
 */

#ifndef ILEVELSQUERYABLE_H_
#define ILEVELSQUERYABLE_H_

#include <cstdint>
#include "Settings/Jackpots/ProgressiveLevel.h"

namespace database
{

/*
 * this class will allow 'CRUD' operation over progressive levels collection
 */
class ILevelsQueryable
{
public:

    ILevelsQueryable()
    {

    }

    virtual ~ILevelsQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add(const std::shared_ptr<ProgressiveLevel> level) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<ProgressiveLevel> get(
            const uint32_t internalId) const = 0;

    virtual std::shared_ptr<ProgressiveLevel> get(
            const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void update(
            const uint32_t internalId,
            const std::shared_ptr<ProgressiveLevel> updatedLevel) const = 0;

    virtual void update(
            const std::string& objectId,
            const std::shared_ptr<ProgressiveLevel> updatedLevel) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint32_t internalId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all levels
     */
    virtual std::vector<std::shared_ptr<ProgressiveLevel>> getAll() const = 0;

    /*
     Remove all levels
     */
    virtual void removeAll() const = 0;
};

}

#endif /* ILEVELSQUERYABLE_H_ */
