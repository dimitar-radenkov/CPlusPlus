/*
 * MongoMultilevels.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "MongoMultilevels.h"

namespace database
{

MongoMultilevels::MongoMultilevels()
{
    // TODO Auto-generated constructor stub
}

MongoMultilevels::~MongoMultilevels()
{
    // TODO Auto-generated destructor stub
}

void MongoMultilevels::add(
        const std::shared_ptr<ProgressiveMultilevel> multilevel) const
{
    if(multilevel == nullptr)
    {
        throw utils::CommonException(
            "Unable to add multilevel. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbMultilevel = this->serialize(multilevel);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbMultilevel);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert multilevel");
    }
}

std::shared_ptr<ProgressiveMultilevel>
MongoMultilevels::get(const uint32_t internalId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbMultilevel =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ProgressiveMultilevel> multilevel =
                this->unserialize(dbMultilevel);

        return multilevel;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get multilevel.", e).c_str());
    }
}

std::shared_ptr<ProgressiveMultilevel>
MongoMultilevels::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbMultilevel =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ProgressiveMultilevel> multilevel =
                this->unserialize(dbMultilevel);

        return multilevel;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get progressive level.", e).c_str());
    }
}

void MongoMultilevels::update(
        const uint32_t internalId,
        const std::shared_ptr<ProgressiveMultilevel> updatedMultilevel) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedMultilevel == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid multilevel pointer");
    }

    if(!this->isMultilevelExists(query))
    {
        throw utils::CommonException(
            "Unable to update. Multilevel doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbMultilevel = this->serialize(updatedMultilevel);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbMultilevel);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update multilevel", e).c_str());
    }
}

void MongoMultilevels::update(
        const std::string& objectId,
        const std::shared_ptr<ProgressiveMultilevel> updatedMultilevel) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedMultilevel == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid multilevel pointer");
    }

    if(!this->isMultilevelExists(query))
    {
        throw utils::CommonException(
            "Unable to update. Multilevel doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbMultilevel = this->serialize(updatedMultilevel);

        MongoDriver::getInstance().getConnection().
                update(COLLECTION_NAME, query, updatedDbMultilevel);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update multilevel", e).c_str());
    }
}

void MongoMultilevels::remove(const uint32_t internalId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isMultilevelExists(query))
    {
        throw utils::CommonException(
                "Unable to remove. Multilevel doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove multilevel", e).c_str());
    }
}

void MongoMultilevels::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isMultilevelExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. Multilevel doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove multilevel.", e).c_str());
    }
}

std::vector<std::shared_ptr<ProgressiveMultilevel>>
MongoMultilevels::getAll() const
{
    std::vector<std::shared_ptr<ProgressiveMultilevel>> multillevelsList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbMultilevel = cursor->next();
            std::shared_ptr<ProgressiveMultilevel> multilevel =
                    this->unserialize(dbMultilevel);

            multillevelsList.push_back(multilevel);
        }

        return multillevelsList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all multilevels", e).c_str());
    }
}

void MongoMultilevels::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all multilevels", e).c_str());
    }
}

mongo::BSONObj
MongoMultilevels::serialize(
        const std::shared_ptr<ProgressiveMultilevel> multilevel) const
{
    mongo::BSONObjBuilder multilevelBuilder;

    multilevelBuilder.append("MultilevelType", multilevel->getType() );
    multilevelBuilder.append("LevelsNumberLimitLimit", multilevel->getLevelsNumberLimit() );
    multilevelBuilder.append("Name", multilevel->getName() );
    multilevelBuilder.append("InternalId", multilevel->getInternalId() );
    multilevelBuilder.append("ExternalId", multilevel->getExternalId() );
    multilevelBuilder.append("SessionId", multilevel->getSessionId() );

    std::set<uint32_t> levelsList = multilevel->getLevelsList();
    if(!levelsList.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itLevelSerial = levelsList.begin();
        for( ; itLevelSerial != levelsList.end(); ++itLevelSerial)
        {
            arrayBuilder.append(*itLevelSerial);
        }

        multilevelBuilder.append("LevelsList", arrayBuilder.arr());
    }

    return multilevelBuilder.obj();
}

std::shared_ptr<ProgressiveMultilevel>
MongoMultilevels::unserialize(const mongo::BSONObj dbMultilevel) const
{
    MultilevelType type =
            (MultilevelType)dbMultilevel.getField("MultilevelType").Int();
    uint16_t levelsNumberLimitLimit = dbMultilevel.getField("LevelsNumberLimitLimit").Int();
    std::string name = dbMultilevel.getField("Name").String();
    uint32_t internalId = dbMultilevel.getField("InternalId").Int();
    uint32_t externalId = dbMultilevel.getField("ExternalId").Int();
    uint32_t sessionId = dbMultilevel.getField("SessionId").Int();

    std::shared_ptr<ProgressiveMultilevel> multilevel(
        new ProgressiveMultilevel(
            type,
            levelsNumberLimitLimit,
            internalId,
            externalId,
            sessionId));

    multilevel->setName(name);

    if (dbMultilevel.hasField("LevelsList"))
    {
        std::vector<mongo::BSONElement> arrayOfIds =
                dbMultilevel.getField("LevelsList").Array();

        if(!arrayOfIds.empty())
        {
            //iterate over levels ids
            auto itArray = arrayOfIds.begin();
            for( ; itArray != arrayOfIds.end() ; ++itArray)
            {
                uint32_t id = itArray->Int();
                multilevel->addLevel(id);
            }
        }
    }

    return multilevel;
}

bool MongoMultilevels::isMultilevelExists(const mongo::BSONObj& query) const
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

const std::string MongoMultilevels::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
