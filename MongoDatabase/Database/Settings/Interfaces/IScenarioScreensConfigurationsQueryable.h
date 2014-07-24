/*
 * IScenarioScreensConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef ISCENARIOSCREENSCONFIGURATIONSQUERYABLE_H_
#define ISCENARIOSCREENSCONFIGURATIONSQUERYABLE_H_

#include <memory>
#include <vector>
#include <string>

#include "Settings/Displays/ScenarioScreensConfiguration.h"

namespace database
{

class IScenarioScreensConfigurationsQueryable
{
public:

    IScenarioScreensConfigurationsQueryable()
    {

    }

    virtual ~IScenarioScreensConfigurationsQueryable()
    {

    }

    /**
     create operation
     */
    virtual void
    add
    (const std::shared_ptr<ScenarioScreensConfiguration> configuration) const = 0;

    /*
     retrieve operations
     */
    virtual std::shared_ptr<ScenarioScreensConfiguration>
    get(const uint16_t configurationId) const = 0;

    virtual std::shared_ptr<ScenarioScreensConfiguration>
    get(const std::string& objectId) const = 0;

    /*
     update operations
     */
    virtual void
    update
    (const uint16_t configurationId,
     const std::shared_ptr<ScenarioScreensConfiguration> updatedConfiguration) const = 0;

    virtual void
    update
    (const std::string& objectId,
     const std::shared_ptr<ScenarioScreensConfiguration> updatedConfiguration) const = 0;

    /*
     delete operations
     */
    virtual void remove(const uint16_t configurationId) const = 0;
    virtual void remove(const std::string& objectId) const = 0;

    /*
     Get all configurations
     */
    virtual std::vector<std::shared_ptr<ScenarioScreensConfiguration>>
    getAll() const = 0;

    /*
     Remove all configurations
     */
    virtual void removeAll() const = 0;
};

}/*namespace database*/


#endif /* ISCENARIOSCREENSCONFIGURATIONSQUERYABLE_H_ */
