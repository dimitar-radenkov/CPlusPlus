/*
 * MongoGeneralOptionsConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef MONGOGENERALOPTIONSCONFIGURATIONS_H_
#define MONGOGENERALOPTIONSCONFIGURATIONS_H_

#include <memory>

#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IGeneralOptionsConfigurationsQueryable.h"
#include "Settings/Displays/GeneralOptionsConfiguration.h"
#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"

namespace database
{

class MongoGeneralOptionsConfigurations : public IGeneralOptionsConfigurationsQueryable
{
public:

    MongoGeneralOptionsConfigurations();

    virtual ~MongoGeneralOptionsConfigurations();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param configuration GeneralOptionsConfiguration to add.
     */
    void
    add
    (const std::shared_ptr<GeneralOptionsConfiguration> configuration) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param configurationId Requsted GeneralOptionsConfiguration configurationId.
     @return requested GeneralOptionsConfiguration object.;
     */
    std::shared_ptr<GeneralOptionsConfiguration>
    get(const uint16_t configurationId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested GeneralOptionsConfiguration object id.
     @return requested GeneralOptionsConfiguration object.;
     */
    std::shared_ptr<GeneralOptionsConfiguration>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param configurationId GeneralOptionsConfiguration configurationId to update.
     @param updatedConfiguration The new text messaage witch will be placed over
     the old one.
     */
    void
    update
    (const uint16_t configurationId,
     const std::shared_ptr<GeneralOptionsConfiguration> updatedConfiguration) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId GeneralOptionsConfiguration objectId to update.
     @param updatedConfiguration The new GeneralOptionsConfiguration witch will
     be placed over the old one.
     */
    void
    update
    (const std::string& objectId,
     const std::shared_ptr<GeneralOptionsConfiguration> updatedConfiguration) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param configurationId GeneralOptionsConfiguration configurationId to remove.
     */

    void remove(const uint16_t configurationId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId GeneralOptionsConfiguration object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of GeneralOptionsConfigurations
     */
    std::vector<std::shared_ptr<GeneralOptionsConfiguration>> getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize GeneralOptionsConfiguration object to BSONObj
     @param configuration object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<GeneralOptionsConfiguration> configuration) const;

    /*
     Unserialize BSONObj object to GeneralOptionsConfiguration object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<GeneralOptionsConfiguration>
    unserialize(const mongo::BSONObj dbConfigurations) const;

    /*
     Check for GeneralOptionsConfiguration in database.
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
    const std::string COLLECTION_NAME = "MitkoDB.GeneralOptionsConfigurations";
};

} /* namespace database */
#endif /* MONGOGENERALOPTIONSCONFIGURATIONS_H_ */
