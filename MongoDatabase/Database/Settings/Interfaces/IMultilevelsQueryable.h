/*
 * IMultilevelsQueryable.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef IMULTILEVELSQUERYABLE_H_
#define IMULTILEVELSQUERYABLE_H_

#include <cstdint>
#include "Settings/Jackpots/ProgressiveMultilevel.h"

namespace database
{

/*
 this class will allow 'CRUD' operation over multilevels collection
 */
class IMultilevelsQueryable
{
public:

    IMultilevelsQueryable()
    {}

    virtual ~IMultilevelsQueryable()
    {}

    /**
     * create operation
     */
    virtual void add(
            const std::shared_ptr<ProgressiveMultilevel> multilevel) const = 0;

    /*
     * retrieve operations
     */
    virtual std::shared_ptr<ProgressiveMultilevel> get(
            const uint32_t internalId) const = 0;

    virtual std::shared_ptr<ProgressiveMultilevel> get(
            const std::string& objectId) const = 0;

    /*
     * update operations
     */
    virtual void update(
            const uint32_t internalId,
            const std::shared_ptr<ProgressiveMultilevel> updatedMultilevel) const = 0;

    virtual void update(
            const std::string& objectId,
            const std::shared_ptr<ProgressiveMultilevel> updatedMultilevel) const = 0;

    /*
     * delete operations
     */
    virtual void remove(const uint32_t internalId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all machines
     */
    virtual std::vector<std::shared_ptr<ProgressiveMultilevel>> getAll() const = 0;

    /*
     Remove all machines
     */
    virtual void removeAll() const = 0;
};

} /* namespace database */

#endif /* IMULTILEVELSQUERYABLE_H_ */
