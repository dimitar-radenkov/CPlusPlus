/*
 * MongoGeneralOptionsConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "MongoGeneralOptionsConfigurations.h"

namespace database {

MongoGeneralOptionsConfigurations::MongoGeneralOptionsConfigurations()
{

}

MongoGeneralOptionsConfigurations::~MongoGeneralOptionsConfigurations()
{

}

void MongoGeneralOptionsConfigurations::add
(const std::shared_ptr<GeneralOptionsConfiguration> configuration) const
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

std::shared_ptr<GeneralOptionsConfiguration>
MongoGeneralOptionsConfigurations::get(const uint16_t configurationId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbConfiguration =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<GeneralOptionsConfiguration> configuration =
            this->unserialize(dbConfiguration);

        return configuration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get options configurations.", e).c_str());
    }
}

std::shared_ptr<GeneralOptionsConfiguration>
MongoGeneralOptionsConfigurations::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbTextsConfigurations =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<GeneralOptionsConfiguration> textConfiguration =
            this->unserialize(dbTextsConfigurations);

        return textConfiguration;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get GeneralOptionsConfiguration.", e).c_str());
    }
}

void
MongoGeneralOptionsConfigurations::update
(const uint16_t configurationId,
 const std::shared_ptr<GeneralOptionsConfiguration> updatedConfigurations) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfigurations == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid GeneralOptionsConfiguration pointer");
    }

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. GeneralOptionsConfiguration doesn't exists");
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
                "Unable to update GeneralOptionsConfiguration", e).c_str());
    }
}

void MongoGeneralOptionsConfigurations::update(
        const std::string& objectId,
        const std::shared_ptr<GeneralOptionsConfiguration> updatedConfiguration) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedConfiguration == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid GeneralOptionsConfiguration pointer");
    }

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to update. GeneralOptionsConfiguration doesn't exists");
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
                "Unable to update GeneralOptionsConfiguration", e).c_str());
    }
}

void MongoGeneralOptionsConfigurations::remove(const uint16_t configurationId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ConfigurationId", configurationId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. GeneralOptionsConfiguration doesn't exists");
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
                "Unable to remove GeneralOptionsConfiguration", e).c_str());
    }
}

void MongoGeneralOptionsConfigurations::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isConfigurationExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. GeneralOptionsConfiguration doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove GeneralOptionsConfiguration", e).c_str());
    }
}

std::vector<std::shared_ptr<GeneralOptionsConfiguration>>
MongoGeneralOptionsConfigurations::getAll() const
{
    std::vector<std::shared_ptr<GeneralOptionsConfiguration>> textMessagesList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbTextMessage = cursor->next();
            std::shared_ptr<GeneralOptionsConfiguration> textMessage =
                this->unserialize(dbTextMessage);

            textMessagesList.push_back(textMessage);
        }

        return textMessagesList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all options configurations", e).c_str());
    }
}

void MongoGeneralOptionsConfigurations::removeAll() const
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
                "Unable to remove all options configurations", e).c_str());
    }
}

mongo::BSONObj
MongoGeneralOptionsConfigurations::serialize
(const std::shared_ptr<GeneralOptionsConfiguration> configuration) const
{
    mongo::BSONObjBuilder builder;
    builder.append("ConfigurationId", configuration->configurationId );
    builder.append("DecimalPoint", configuration->decimalPoint );
    builder.append("ThousandSeparator", configuration->thousandSeparator );
    builder.append("LanguageId", configuration->languageId );
    builder.append("DefaultVolumeLevel", configuration->defaultVolumeLevel );
    builder.append("CurrencyCode", configuration->currencyCode );
    builder.append("ShowAllWins", configuration->showAllWins );

    return builder.obj();
}

std::shared_ptr<GeneralOptionsConfiguration>
MongoGeneralOptionsConfigurations::unserialize
(const mongo::BSONObj dbTextsConfiguration) const
{
    uint16_t configurationId = dbTextsConfiguration.getField("ConfigurationId").Int();
    uint8_t decimalPoint = dbTextsConfiguration.getField("DecimalPoint").Int();
    uint8_t thousandSeparator = dbTextsConfiguration.getField("ThousandSeparator").Int();
    uint16_t languageId = dbTextsConfiguration.getField("LanguageId").Int();
    uint8_t defaultVolumeLevel = dbTextsConfiguration.getField("DefaultVolumeLevel").Int();
    std::string currencyCode = dbTextsConfiguration.getField("CurrencyCode").String();
    uint8_t showAllWins = dbTextsConfiguration.getField("ShowAllWins").Int();


    std::shared_ptr<GeneralOptionsConfiguration> configuration(
        new GeneralOptionsConfiguration(
                configurationId,
                decimalPoint,
                thousandSeparator,
                languageId,
                defaultVolumeLevel,
                currencyCode,
                showAllWins));

    return configuration;
}

bool
MongoGeneralOptionsConfigurations::isConfigurationExists
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

const std::string MongoGeneralOptionsConfigurations::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
