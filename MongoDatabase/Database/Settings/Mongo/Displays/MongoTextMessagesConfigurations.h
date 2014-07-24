/*
 * MongoTextMessagesConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef MONGOTEXTMESSAGESCONFIGURATIONS_H_
#define MONGOTEXTMESSAGESCONFIGURATIONS_H_

#include <memory>

#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/ITextMessagesConfigurationsQueryable.h"
#include "Settings/Displays/StatusLineTextsConfiguration.h"
#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"

namespace database
{

class MongoTextMessagesConfigurations : public ITextMessagesConfigurationsQueryable
{

public:

    MongoTextMessagesConfigurations();

    virtual ~MongoTextMessagesConfigurations();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param configuration StatusLineTextsConfiguration to add.
     */
    void add(const std::shared_ptr<StatusLineTextsConfiguration> configuration) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param uniqueId Requsted StatusLineTextsConfiguration uniqueId.
     @return requested StatusLineTextsConfiguration object.;
     */
    std::shared_ptr<StatusLineTextsConfiguration>
    get(const uint16_t uniqueId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested StatusLineTextsConfiguration object id.
     @return requested StatusLineTextsConfiguration object.;
     */
    std::shared_ptr<StatusLineTextsConfiguration>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param uniqueId StatusLineTextsConfiguration uniqueId to update.
     @param updatedConfiguration The new text messaage witch will be placed over
     the old one.
     */
    void
    update(const uint16_t uniqueId,
           const std::shared_ptr<StatusLineTextsConfiguration> updatedConfiguration) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId StatusLineTextsConfiguration objectId to update.
     @param updatedConfiguration The new text messaage witch will be placed over
     the old one.
     */
    void
    update(const std::string& objectId,
           const std::shared_ptr<StatusLineTextsConfiguration> updatedConfiguration) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param uniqueId StatusLineTextsConfiguration uniqueId to remove.
     */

    void remove(const uint16_t uniqueId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId StatusLineTextsConfiguration object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of text configurations
     */
    std::vector<std::shared_ptr<StatusLineTextsConfiguration>> getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     @return vector of StatusLineTextsConfiguration
     */
    void removeAll() const override;

private:
    /*
     Serialize StatusLineTextsConfiguration object to BSONObj
     @param configuration object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<StatusLineTextsConfiguration> configuration) const;

    /*
     Unserialize BSONObj object to StatusLineTextsConfiguration object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<StatusLineTextsConfiguration>
    unserialize(const mongo::BSONObj dbTextConfiguration) const;

    /*
     Check for StatusLineTextsConfiguration in database.
     @return true if text configuration is found.False otherwise.
     */
    bool isTextsConfigurationExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.TextMessagesConfiguration";
};

} /* namespace database */
#endif /* MONGOTEXTMESSAGESCONFIGURATIONS_H_ */
