/*
 * MongoScenarioScreensConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef MONGOSCENARIOSCREENSCONFIGURATIONS_H_
#define MONGOSCENARIOSCREENSCONFIGURATIONS_H_

#include <memory>

#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IScenarioScreensConfigurationsQueryable.h"
#include "Settings/Displays/ScenarioScreensConfiguration.h"
#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"

namespace database
{

class MongoScenarioScreensConfigurations : public IScenarioScreensConfigurationsQueryable
{
public:
    MongoScenarioScreensConfigurations();
    virtual ~MongoScenarioScreensConfigurations();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param configuration ScenarioScreensConfiguration to add.
     */
    void
    add
    (const std::shared_ptr<ScenarioScreensConfiguration> configuration) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param configurationId Requsted ScenarioScreensConfiguration configurationId.
     @return requested ScenarioScreensConfiguration object.;
     */
    std::shared_ptr<ScenarioScreensConfiguration>
    get(const uint16_t configurationId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested ScenarioScreensConfiguration object id.
     @return requested ScenarioScreensConfiguration object.;
     */
    std::shared_ptr<ScenarioScreensConfiguration>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param configurationId ScenarioScreensConfiguration configurationId to update.
     @param updatedConfiguration The new ScenarioScreensConfiguration witch will
     be placed over the old one.
     */
    void
    update
    (const uint16_t configurationId,
     const std::shared_ptr<ScenarioScreensConfiguration> updatedConfiguration) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId ScenarioScreensConfiguration objectId to update.
     @param updatedConfiguration The new ScenarioScreensConfiguration witch will
     be placed over the old one.
     */
    void
    update
    (const std::string& objectId,
     const std::shared_ptr<ScenarioScreensConfiguration> updatedConfiguration) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param configurationId ScenarioScreensConfiguration configurationId to remove.
     */

    void remove(const uint16_t configurationId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId ScenarioScreensConfiguration object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of ScenarioScreensConfiguration
     */
    std::vector<std::shared_ptr<ScenarioScreensConfiguration>>
    getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize ScenarioScreensConfiguration object to BSONObj
     @param configuration object to serialize
     */
    mongo::BSONObj
    serialize
    (const std::shared_ptr<ScenarioScreensConfiguration> configuration) const;

    /*
     Unserialize BSONObj object to ScenarioScreensConfiguration object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<ScenarioScreensConfiguration>
    unserialize(const mongo::BSONObj dbConfigurations) const;

    /*
     Check for ScenarioScreensConfiguration in database.
     @return true if text configuration is found.False otherwise.
     */
    bool isConfigurationExists(const mongo::BSONObj& query) const;

    /*
     Justify error message.
     @param message User message.
     @param exc throw DBException.
     */
    const std::string buildErrorMessage(
            const std::string& message,
            const mongo::DBException &exc) const;

    /**
     Collection name in database to commit
     */
    const std::string COLLECTION_NAME = "MitkoDB.ScenarioScreensConfigurations";
};

} /* namespace database */
#endif /* MONGOSCENARIOSCREENSCONFIGURATIONS_H_ */
