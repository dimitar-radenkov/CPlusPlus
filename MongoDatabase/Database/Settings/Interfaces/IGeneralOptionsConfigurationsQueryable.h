/*
 * IGeneralOptionsConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef IGENERALOPTIONSCONFIGURATIONS_H_
#define IGENERALOPTIONSCONFIGURATIONS_H_

#include <memory>
#include <vector>
#include <string>

#include "Settings/Displays/GeneralOptionsConfiguration.h"

namespace database
{

class IGeneralOptionsConfigurationsQueryable
{
public:

    IGeneralOptionsConfigurationsQueryable()
    {

    }

    virtual ~IGeneralOptionsConfigurationsQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add
    (const std::shared_ptr<GeneralOptionsConfiguration> configuration) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<GeneralOptionsConfiguration>
    get(const uint16_t uniqueId) const = 0;

    virtual std::shared_ptr<GeneralOptionsConfiguration>
    get(const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void
    update
    (const uint16_t uniqueId,
     const std::shared_ptr<GeneralOptionsConfiguration> updatedConfiguration) const = 0;

    virtual void
    update
    (const std::string& objectId,
     const std::shared_ptr<GeneralOptionsConfiguration> updatedConfiguration) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint16_t uniqueId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all general options configurations
     */
    virtual std::vector<std::shared_ptr<GeneralOptionsConfiguration>>
    getAll() const = 0;

    /*
     Remove all general options configurations
     */
    virtual void removeAll() const = 0;
};

}/*namespace database*/


#endif /* IGENERALOPTIONSCONFIGURATIONS_H_ */
