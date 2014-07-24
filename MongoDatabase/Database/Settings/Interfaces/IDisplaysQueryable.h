/*
 * IDisplaysQueryable.h
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#ifndef IDISPLAYSQUERYABLE_H_
#define IDISPLAYSQUERYABLE_H_

#include <memory>
#include <vector>
#include <string>

#include "Settings/Displays/Display.h"

namespace database
{

class IDisplaysQueryable
{
public:

    IDisplaysQueryable()
    {

    }

    virtual ~IDisplaysQueryable()
    {

    }


    /**
     * create operation
     */
    virtual void add(const std::shared_ptr<Display> display) const = 0;

    /*
     * retrieve operations
     */
    virtual std::shared_ptr<Display> get(const uint64_t serialNumber) const = 0;
    virtual std::shared_ptr<Display> get(const std::string& objectId) const = 0;

    /*
     * update operations
     */
    virtual void update(
            const uint64_t serialNumber,
            const std::shared_ptr<Display> updatedDisplay) const = 0;

    virtual void update(
            const std::string& objectId,
            const std::shared_ptr<Display> updatedDisplay) const = 0;

    /*
     * delete operations
     */
    virtual void remove(const uint64_t serialNumber) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all displays
     */
    virtual std::vector<std::shared_ptr<Display>> getAll() const = 0;

    /*
     Remove all displays
     */
    virtual void removeAll() const = 0;
};

} /*namespace database*/

#endif /* IDISPLAYSQUERYABLE_H_ */
