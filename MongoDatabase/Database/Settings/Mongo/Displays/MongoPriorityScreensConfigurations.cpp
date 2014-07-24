/*
 * MongoPriorityScreensConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "MongoPriorityScreensConfigurations.h"

namespace database
{

MongoPriorityScreensConfigurations::MongoPriorityScreensConfigurations()
{

}

MongoPriorityScreensConfigurations::~MongoPriorityScreensConfigurations()
{

}

void MongoPriorityScreensConfigurations::add
(const std::shared_ptr<PriorityScreensConfiguration> configuration) const
{
    if(configuration == nullptr)
    {
        throw utils::CommonException(
            "Unable to add options configuration. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbConfiguration = this->serialize(configuration);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbConfiguration);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert options configuration");
    }
}

std::shared_ptr<PriorityScreensConfiguration>
MongoPriorityScreensConfigurations::get(const uint16_t configurationId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbConfiguration =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<PriorityScreensConfiguration> configuration =
            this->unserialize(dbConfiguration);

        return configuration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get PriorityScreensConfiguration.", e).c_str());
    }
}

std::shared_ptr<PriorityScreensConfiguration>
MongoPriorityScreensConfigurations::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbConfigurations =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<PriorityScreensConfiguration> configuration =
            this->unserialize(dbConfigurations);

        return configuration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get PriorityScreensConfiguration.", e).c_str());
    }
}

void
MongoPriorityScreensConfigurations::update
(const uint16_t configurationId,
 const std::shared_ptr<PriorityScreensConfiguration> updatedConfigurations) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfigurations == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid PriorityScreensConfiguration pointer");
    }

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. PriorityScreensConfiguration doesn't exists");
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
            this->buildErrorMessage(
                "Unable to update PriorityScreensConfiguration", e).c_str());
    }
}

void MongoPriorityScreensConfigurations::update(
        const std::string& objectId,
        const std::shared_ptr<PriorityScreensConfiguration> updatedConfiguration) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfiguration == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid PriorityScreensConfiguration pointer");
    }

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. PriorityScreensConfiguration doesn't exists");
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
                "Unable to update PriorityScreensConfiguration", e).c_str());
    }
}

void MongoPriorityScreensConfigurations::remove(const uint16_t configurationId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. PriorityScreensConfiguration doesn't exists");
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
                "Unable to remove PriorityScreensConfiguration", e).c_str());
    }
}

void MongoPriorityScreensConfigurations::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. PriorityScreensConfiguration doesn't exists");
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
                "Unable to remove PriorityScreensConfiguration", e).c_str());
    }
}

std::vector<std::shared_ptr<PriorityScreensConfiguration>>
MongoPriorityScreensConfigurations::getAll() const
{
    std::vector<std::shared_ptr<PriorityScreensConfiguration>> configurationList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbConfiguration = cursor->next();
            std::shared_ptr<PriorityScreensConfiguration> configuration =
                this->unserialize(dbConfiguration);

            configurationList.push_back(configuration);
        }

        return configurationList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get all PriorityScreensConfiguration", e).c_str());
    }
}

void MongoPriorityScreensConfigurations::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to remove all PriorityScreensConfiguration", e).c_str());
    }
}

mongo::BSONObj
MongoPriorityScreensConfigurations::serialize
(const std::shared_ptr<PriorityScreensConfiguration> configuration) const
{
    mongo::BSONObjBuilder builder;
    builder.append("ConfigurationId", configuration->configurationId );

    std::vector<uint16_t> screensIds = configuration->screensIds;

    if(!screensIds.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itScreenId = screensIds.begin();
        for( ; itScreenId != screensIds.end(); ++itScreenId)
        {
            arrayBuilder.append(*itScreenId);
        }

        builder.append("ScreensIds", arrayBuilder.arr());
    }

    return builder.obj();
}

std::shared_ptr<PriorityScreensConfiguration>
MongoPriorityScreensConfigurations::unserialize
(const mongo::BSONObj dbConfiguration) const
{
    std::shared_ptr<PriorityScreensConfiguration> configuration(
            new PriorityScreensConfiguration());

        uint16_t configurationId = dbConfiguration.getField("ConfigurationId").Int();
        std::vector<uint16_t> screensIds;

        if (dbConfiguration.hasField("ScreensIds"))
        {
            std::vector<mongo::BSONElement> arrayOfScreenIds =
                dbConfiguration.getField("ScreensIds").Array();

            if(!arrayOfScreenIds.empty())
            {
                //iterate over machine serial numbers
                auto itArray = arrayOfScreenIds.begin();
                for( ; itArray != arrayOfScreenIds.end() ; ++itArray)
                {
                    uint16_t screenId = itArray->Int();
                    screensIds.push_back(screenId);
                }
            }
        }

        configuration->configurationId = configurationId;
        configuration->screensIds = screensIds;

        return configuration;
}

bool
MongoPriorityScreensConfigurations::isConfigurationExists
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

const std::string MongoPriorityScreensConfigurations::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}


} /* namespace database */
