/*
 * IJackpotQueryable.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef IJACKPOTQUERYABLE_H_
#define IJACKPOTQUERYABLE_H_

#include <cstdint>
#include "Settings/Jackpots/Jackpot.h"

namespace database
{

/*
 * this class will allow 'CRUD' operation over progressive jackpots collection
 */
class IJackpotsQueryable
{
public:

    IJackpotsQueryable()
    {

    }

    virtual ~IJackpotsQueryable()
    {

    }

    /**
     * create operation
     */
    virtual void
    add(const std::shared_ptr<Jackpot> level) const = 0;

    /*
     * retrieve operations
     */
    virtual std::shared_ptr<Jackpot> get(
            const uint32_t internalId) const = 0;

    virtual std::shared_ptr<Jackpot> get(
            const std::string& objectId) const = 0;

    /*
     * update operations
     */
    virtual void update(
            const uint32_t internalId,
            const std::shared_ptr<Jackpot> updatedLevel) const = 0;

    virtual void update(
            const std::string& objectId,
            const std::shared_ptr<Jackpot> updatedLevel) const = 0;

    /*
     * delete operations
     */
    virtual void remove(const uint32_t internalId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all jackpots
     */
    virtual std::vector<std::shared_ptr<Jackpot>> getAll() const = 0;

    /*
     Remove all jackpots
     */
    virtual void removeAll() const = 0;
};

}


#endif /* IJACKPOTQUERYABLE_H_ */
