/*
 * MongoPriorityScreensConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef MONGOPRIORITYSCREENSCONFIGURATIONS_H_
#define MONGOPRIORITYSCREENSCONFIGURATIONS_H_

#include <memory>

#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IPriorityScreensConfigurationsQueryable.h"
#include "Settings/Displays/PriorityScreensConfiguration.h"
#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"

namespace database
{

class MongoPriorityScreensConfigurations : public IPriorityScreensConfigurationsQueryable
{
public:
    MongoPriorityScreensConfigurations();

    virtual ~MongoPriorityScreensConfigurations();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param configuration PriorityScreensConfiguration to add.
     */
    void
    add
    (const std::shared_ptr<PriorityScreensConfiguration> configuration) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param configurationId Requsted PriorityScreensConfiguration configurationId.
     @return requested PriorityScreensConfiguration object.;
     */
    std::shared_ptr<PriorityScreensConfiguration>
    get(const uint16_t configurationId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested PriorityScreensConfiguration object id.
     @return requested PriorityScreensConfiguration object.;
     */
    std::shared_ptr<PriorityScreensConfiguration>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param configurationId PriorityScreensConfiguration configurationId to update.
     @param updatedConfiguration The new PriorityScreensConfiguration witch will
     be placed over the old one.
     */
    void
    update
    (const uint16_t configurationId,
     const std::shared_ptr<PriorityScreensConfiguration> updatedConfiguration) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId PriorityScreensConfiguration objectId to update.
     @param updatedConfiguration The new PriorityScreensConfiguration witch will
     be placed over the old one.
     */
    void
    update
    (const std::string& objectId,
     const std::shared_ptr<PriorityScreensConfiguration> updatedConfiguration) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param configurationId PriorityScreensConfiguration configurationId to remove.
     */

    void remove(const uint16_t configurationId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId PriorityScreensConfiguration object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of PriorityScreensConfiguration
     */
    std::vector<std::shared_ptr<PriorityScreensConfiguration>>
    getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize PriorityScreensConfiguration object to BSONObj
     @param configuration object to serialize
     */
    mongo::BSONObj
    serialize
    (const std::shared_ptr<PriorityScreensConfiguration> configuration) const;

    /*
     Unserialize BSONObj object to PriorityScreensConfiguration object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<PriorityScreensConfiguration>
    unserialize(const mongo::BSONObj dbConfigurations) const;

    /*
     Check for PriorityScreensConfiguration in database.
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
    const std::string COLLECTION_NAME = "MitkoDB.PriorityScreensConfigurations";
};

} /* namespace database */
#endif /* MONGOPRIORITYSCREENSCONFIGURATIONS_H_ */
