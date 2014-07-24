/*
 * MongoTextMessages.h
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#ifndef MONGOTEXTMESSAGES_H_
#define MONGOTEXTMESSAGES_H_

#include <memory>
#include <cstdint>

#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/ITextMessagesQueryable.h"
#include "Settings/Displays/StatusLineText.h"
#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"

namespace database
{

class MongoTextMessages : public ITextMessagesQueryable
{
public:

    MongoTextMessages();

    virtual ~MongoTextMessages();
public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param textMessage StatusLineText to add.
     */
    void add(const std::shared_ptr<StatusLineText> textMessage) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param uniqueId Requsted StatusLineText uniqueId.
     @return requested StatusLineText object.;
     */
    std::shared_ptr<StatusLineText>
    get(const uint16_t uniqueId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested StatusLineText object id.
     @return requested StatusLineText object.;
     */
    std::shared_ptr<StatusLineText>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param uniqueId StatusLineText uniqueId to update.
     @param updatedTextMessage The new text messaage witch will be placed over
     the old one.
     */
    void update(
            const uint16_t uniqueId,
            const std::shared_ptr<StatusLineText> updatedTextMessage) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId StatusLineText objectId to update.
     @param updatedTextMessage The new text messaage witch will be placed over
     the old one.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<StatusLineText> updatedTextMessage) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param uniqueId StatusLineText uniqueId to remove.
     */

    void remove(const uint16_t uniqueId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId StatusLineText object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of text messages
     */
    std::vector<std::shared_ptr<StatusLineText>> getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     @return vector of StatusLineText
     */
    void removeAll() const override;

private:
    /*
     Serialize StatusLineText object to BSONObj
     @param textMessage object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<StatusLineText> textMessage) const;

    /*
     Unserialize BSONObj object to StatusLineText object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<StatusLineText>
    unserialize(const mongo::BSONObj dbTextMessage) const;

    /*
     Check for StatusLineText in database.
     @return true if text message is found.False otherwise.
     */
    bool isTextMessageExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.TextMessages";
};

} /* namespace database */
#endif /* MONGOTEXTMESSAGES_H_ */
