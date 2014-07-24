/*
 * MongoTextMessages.cpp
 *
 *  Created on: May 24, 2014
 *      Author: root
 */

#include "MongoTextMessages.h"

namespace database {

MongoTextMessages::MongoTextMessages()
{

}

MongoTextMessages::~MongoTextMessages()
{

}

void MongoTextMessages::add(const std::shared_ptr<StatusLineText> textMessage) const
{
    if(textMessage == nullptr)
    {
        throw utils::CommonException("Unable to add text message. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbTextMessage = this->serialize(textMessage);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbTextMessage);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert text message");
    }
}

std::shared_ptr<StatusLineText>
MongoTextMessages::get(const uint16_t uniqueId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("UniqueId", uniqueId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbTextMessage =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<StatusLineText> textMessage = this->unserialize(dbTextMessage);

        return textMessage;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get text message.", e).c_str());
    }
}

std::shared_ptr<StatusLineText>
MongoTextMessages::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbTextMessage =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<StatusLineText> textMessage = this->unserialize(dbTextMessage);

        return textMessage;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get text message.", e).c_str());
    }
}

void MongoTextMessages::update(
        const uint16_t uniqueId,
        const std::shared_ptr<StatusLineText> updatedTextMessage) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("UniqueId", uniqueId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedTextMessage == nullptr)
    {
        throw utils::CommonException("Unable to update. Invalid text message pointer");
    }

    if(!this->isTextMessageExists(query))
    {
        throw utils::CommonException("Unable to update. StatusLineText doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbTextMessage = this->serialize(updatedTextMessage);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbTextMessage);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update text message", e).c_str());
    }
}

void MongoTextMessages::update(
        const std::string& objectId,
        const std::shared_ptr<StatusLineText> updatedTextMessage) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedTextMessage == nullptr)
    {
        throw utils::CommonException("Unable to update. Invalid text message pointer");
    }

    if(!this->isTextMessageExists(query))
    {
        throw utils::CommonException("Unable to update. StatusLineText doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbTextMessage = this->serialize(updatedTextMessage);

        MongoDriver::getInstance().getConnection().
                update(COLLECTION_NAME, query, updatedDbTextMessage);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update StatusLineText", e).c_str());
    }
}

void MongoTextMessages::remove(const uint16_t uniqueId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("UniqueId", uniqueId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isTextMessageExists(query))
    {
        throw utils::CommonException("Unable to remove. StatusLineText doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove StatusLineText", e).c_str());
    }
}

void MongoTextMessages::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isTextMessageExists(query))
    {
        throw utils::CommonException("Unable to remove. StatusLineText doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove text message", e).c_str());
    }
}

std::vector<std::shared_ptr<StatusLineText>>
MongoTextMessages::getAll() const
{
    std::vector<std::shared_ptr<StatusLineText>> textMessagesList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbTextMessage = cursor->next();
            std::shared_ptr<StatusLineText> textMessage =
                this->unserialize(dbTextMessage);

            textMessagesList.push_back(textMessage);
        }

        return textMessagesList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all text messages", e).c_str());
    }
}

void MongoTextMessages::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all text messages", e).c_str());
    }
}

mongo::BSONObj
MongoTextMessages::serialize(const std::shared_ptr<StatusLineText> textMessage) const
{
    mongo::BSONObjBuilder builder;
    builder.append("UniqueId", textMessage->uniqueId );
    builder.append("MessageText", textMessage->messageText );

    return builder.obj();
}

std::shared_ptr<StatusLineText>
MongoTextMessages::unserialize(const mongo::BSONObj dbTextMessage) const
{
    uint16_t uniqueId = dbTextMessage.getField("UniqueId").Int();
    std::string textMessageStr = dbTextMessage.getField("MessageText").String();

    std::shared_ptr<StatusLineText> textMessage(
        new StatusLineText(
                uniqueId,
                textMessageStr));


    return textMessage;
}

bool MongoTextMessages::isTextMessageExists(const mongo::BSONObj& query) const
{
    mongo::BSONObj result =
            MongoDriver::getInstance().getConnection().
            findOne( COLLECTION_NAME , query );

    if(result.isEmpty())
    {
        return false;
    }

    return true;
}

const std::string MongoTextMessages::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
