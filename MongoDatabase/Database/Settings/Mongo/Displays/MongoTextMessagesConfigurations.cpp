/*
 * MongoTextMessagesConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "MongoTextMessagesConfigurations.h"

namespace database
{

MongoTextMessagesConfigurations::MongoTextMessagesConfigurations()
{

}

MongoTextMessagesConfigurations::~MongoTextMessagesConfigurations()
{

}

void MongoTextMessagesConfigurations::add
(const std::shared_ptr<StatusLineTextsConfiguration> configuration) const
{
    if(configuration == nullptr)
    {
        throw utils::CommonException("Unable to add texts configuration. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbTextsConfiguration = this->serialize(configuration);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbTextsConfiguration);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert texts configuration");
    }
}

std::shared_ptr<StatusLineTextsConfiguration>
MongoTextMessagesConfigurations::get(const uint16_t uniqueId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("UniqueId", uniqueId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbTextsConfiguration =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<StatusLineTextsConfiguration> textsConfiguration =
                this->unserialize(dbTextsConfiguration);

        return textsConfiguration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get text configurations.", e).c_str());
    }
}

std::shared_ptr<StatusLineTextsConfiguration>
MongoTextMessagesConfigurations::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbTextsConfigurations =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<StatusLineTextsConfiguration> textConfiguration =
            this->unserialize(dbTextsConfigurations);

        return textConfiguration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get texts configuration.", e).c_str());
    }
}

void
MongoTextMessagesConfigurations::update
(const uint16_t uniqueId,
 const std::shared_ptr<StatusLineTextsConfiguration> updatedConfigurations) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("UniqueId", uniqueId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfigurations == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid StatusLineTextsConfiguration pointer");
    }

    if(!this->isTextsConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. StatusLineTextsConfiguration doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbConfigurations =
                this->serialize(updatedConfigurations);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbConfigurations);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update texts configuration", e).c_str());
    }
}

void MongoTextMessagesConfigurations::update(
        const std::string& objectId,
        const std::shared_ptr<StatusLineTextsConfiguration> updatedConfiguration) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfiguration == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid text configuration pointer");
    }

    if(!this->isTextsConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. StatusLineTextsConfiguration doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbConfigurations =
            this->serialize(updatedConfiguration);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbConfigurations);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to update StatusLineTextsConfiguration", e).c_str());
    }
}

void MongoTextMessagesConfigurations::remove(const uint16_t uniqueId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("UniqueId", uniqueId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isTextsConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. StatusLineTextsConfiguration doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to remove StatusLineTextsConfiguration", e).c_str());
    }
}

void MongoTextMessagesConfigurations::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isTextsConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. StatusLineTextsConfiguration doesn't exists");
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

std::vector<std::shared_ptr<StatusLineTextsConfiguration>>
MongoTextMessagesConfigurations::getAll() const
{
    std::vector<std::shared_ptr<StatusLineTextsConfiguration>> textMessagesList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbTextMessage = cursor->next();
            std::shared_ptr<StatusLineTextsConfiguration> textMessage =
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

void MongoTextMessagesConfigurations::removeAll() const
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
MongoTextMessagesConfigurations::serialize
(const std::shared_ptr<StatusLineTextsConfiguration> configuration) const
{
    mongo::BSONObjBuilder builder;
    builder.append("UniqueId", configuration->uniqueId );

    std::vector<uint16_t> messagesIds = configuration->messagesIds;

    if(!messagesIds.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itMessagesId = messagesIds.begin();
        for( ; itMessagesId != messagesIds.end(); ++itMessagesId)
        {
            arrayBuilder.append(*itMessagesId);
        }

        builder.append("MessagesIds", arrayBuilder.arr());
    }

    return builder.obj();
}

std::shared_ptr<StatusLineTextsConfiguration>
MongoTextMessagesConfigurations::unserialize
(const mongo::BSONObj dbTextsConfiguration) const
{
    std::shared_ptr<StatusLineTextsConfiguration> textsConfiguration(
        new StatusLineTextsConfiguration());

    uint16_t uniqueId = dbTextsConfiguration.getField("UniqueId").Int();
    std::vector<uint16_t> messagesIds;

    if (dbTextsConfiguration.hasField("MessagesIds"))
    {
        std::vector<mongo::BSONElement> arrayOfMessageIds =
            dbTextsConfiguration.getField("MessagesIds").Array();

        if(!arrayOfMessageIds.empty())
        {
            //iterate over machine serial numbers
            auto itArray = arrayOfMessageIds.begin();
            for( ; itArray != arrayOfMessageIds.end() ; ++itArray)
            {
                uint16_t messageId = itArray->Int();
                messagesIds.push_back(messageId);
            }
        }
    }

    textsConfiguration->uniqueId = uniqueId;
    textsConfiguration->messagesIds = messagesIds;

    return textsConfiguration;
}

bool
MongoTextMessagesConfigurations::isTextsConfigurationExists
(const mongo::BSONObj& query) const
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

const std::string MongoTextMessagesConfigurations::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
