/*
 * IPriorityScreensConfigurationsQueryable.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef IPRIORITYSCREENSCONFIGURATIONSQUERYABLE_H_
#define IPRIORITYSCREENSCONFIGURATIONSQUERYABLE_H_

#include <memory>
#include <vector>
#include <string>

#include "Settings/Displays/PriorityScreensConfiguration.h"

namespace database
{

class IPriorityScreensConfigurationsQueryable
{
public:

    IPriorityScreensConfigurationsQueryable()
    {

    }

    virtual ~IPriorityScreensConfigurationsQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add
    (const std::shared_ptr<PriorityScreensConfiguration> configuration) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<PriorityScreensConfiguration>
    get(const uint16_t configurationId) const = 0;

    virtual std::shared_ptr<PriorityScreensConfiguration>
    get(const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void
    update
    (const uint16_t configurationId,
     const std::shared_ptr<PriorityScreensConfiguration> updatedConfiguration) const = 0;

    virtual void
    update
    (const std::string& objectId,
     const std::shared_ptr<PriorityScreensConfiguration> updatedConfiguration) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint16_t uniqueId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all configurations
     */
    virtual std::vector<std::shared_ptr<PriorityScreensConfiguration>>
    getAll() const = 0;

    /*
     Remove all configurations
     */
    virtual void removeAll() const = 0;
};

}/*namespace database*/


#endif /* IPRIORITYSCREENSCONFIGURATIONSQUERYABLE_H_ */
