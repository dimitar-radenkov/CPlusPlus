/*
 * MongoScenarioScreensConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "MongoScenarioScreensConfigurations.h"

namespace database
{

MongoScenarioScreensConfigurations::MongoScenarioScreensConfigurations()
{

}

MongoScenarioScreensConfigurations::~MongoScenarioScreensConfigurations()
{

}

void MongoScenarioScreensConfigurations::add
(const std::shared_ptr<ScenarioScreensConfiguration> configuration) const
{
    if(configuration == nullptr)
    {
        throw utils::CommonException(
            "Unable to add ScenarioScreensConfiguration. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbConfiguration = this->serialize(configuration);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbConfiguration);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert ScenarioScreensConfiguration");
    }
}

std::shared_ptr<ScenarioScreensConfiguration>
MongoScenarioScreensConfigurations::get(const uint16_t configurationId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbConfiguration =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ScenarioScreensConfiguration> configuration =
            this->unserialize(dbConfiguration);

        return configuration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get ScenarioScreensConfiguration.", e).c_str());
    }
}

std::shared_ptr<ScenarioScreensConfiguration>
MongoScenarioScreensConfigurations::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbConfigurations =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ScenarioScreensConfiguration> configuration =
            this->unserialize(dbConfigurations);

        return configuration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get ScenarioScreensConfiguration.", e).c_str());
    }
}

void
MongoScenarioScreensConfigurations::update
(const uint16_t configurationId,
 const std::shared_ptr<ScenarioScreensConfiguration> updatedConfigurations) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfigurations == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid ScenarioScreensConfiguration pointer");
    }

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. ScenarioScreensConfiguration doesn't exists");
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
                "Unable to update ScenarioScreensConfiguration", e).c_str());
    }
}

void MongoScenarioScreensConfigurations::update(
        const std::string& objectId,
        const std::shared_ptr<ScenarioScreensConfiguration> updatedConfiguration) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfiguration == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid ScenarioScreensConfiguration pointer");
    }

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. ScenarioScreensConfiguration doesn't exists");
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
                "Unable to update ScenarioScreensConfiguration", e).c_str());
    }
}

void MongoScenarioScreensConfigurations::remove(const uint16_t configurationId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. ScenarioScreensConfiguration doesn't exists");
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
                "Unable to remove ScenarioScreensConfiguration", e).c_str());
    }
}

void MongoScenarioScreensConfigurations::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. ScenarioScreensConfiguration doesn't exists");
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
                "Unable to remove ScenarioScreensConfiguration", e).c_str());
    }
}

std::vector<std::shared_ptr<ScenarioScreensConfiguration>>
MongoScenarioScreensConfigurations::getAll() const
{
    std::vector<std::shared_ptr<ScenarioScreensConfiguration>> configurationList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbConfiguration = cursor->next();
            std::shared_ptr<ScenarioScreensConfiguration> configuration =
                this->unserialize(dbConfiguration);

            configurationList.push_back(configuration);
        }

        return configurationList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get all ScenarioScreensConfigurations", e).c_str());
    }
}

void MongoScenarioScreensConfigurations::removeAll() const
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
                "Unable to remove all ScenarioScreensConfigurations", e).c_str());
    }
}

mongo::BSONObj
MongoScenarioScreensConfigurations::serialize
(const std::shared_ptr<ScenarioScreensConfiguration> configuration) const
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

std::shared_ptr<ScenarioScreensConfiguration>
MongoScenarioScreensConfigurations::unserialize
(const mongo::BSONObj dbConfiguration) const
{
    std::shared_ptr<ScenarioScreensConfiguration> configuration(
            new ScenarioScreensConfiguration());

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
MongoScenarioScreensConfigurations::isConfigurationExists
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

const std::string MongoScenarioScreensConfigurations::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
