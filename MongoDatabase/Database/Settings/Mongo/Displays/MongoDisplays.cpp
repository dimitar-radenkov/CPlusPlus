/*
 * MongoDisplays.cpp
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#include "MongoDisplays.h"

namespace database {

MongoDisplays::MongoDisplays()
{
    // TODO Auto-generated constructor stub
}

MongoDisplays::~MongoDisplays()
{
    // TODO Auto-generated destructor stub
}

void MongoDisplays::add(const std::shared_ptr<Display> display) const
{
    if(display == nullptr)
    {
        throw utils::CommonException("Unable to add display. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbDisplay = this->serialize(display);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbDisplay);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert display");
    }
}

std::shared_ptr<Display>
MongoDisplays::get(const uint64_t serialNumber) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("SerialNumber",(int64_t)serialNumber);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbDisplay =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<Display> display = this->unserialize(dbDisplay);

        return display;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get display.", e).c_str());
    }
}

std::shared_ptr<Display>
MongoDisplays::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbDisplay =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<Display> display = this->unserialize(dbDisplay);

        return display;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get display.", e).c_str());
    }
}

void MongoDisplays::update(
        const uint64_t serialNumber,
        const std::shared_ptr<Display> updatedDisplay) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("SerialNumber",(int64_t)serialNumber);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedDisplay == nullptr)
    {
        throw utils::CommonException("Unable to update. Invalid display pointer");
    }

    if(!this->isDisplayExists(query))
    {
        throw utils::CommonException("Unable to update. Display doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbDisplay = this->serialize(updatedDisplay);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbDisplay);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update display", e).c_str());
    }
}

void MongoDisplays::update(
        const std::string& objectId,
        const std::shared_ptr<Display> updatedDisplay) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedDisplay == nullptr)
    {
        throw utils::CommonException("Unable to update. Invalid display pointer");
    }

    if(!this->isDisplayExists(query))
    {
        throw utils::CommonException("Unable to update. Display doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbDisplay = this->serialize(updatedDisplay);

        MongoDriver::getInstance().getConnection().
                update(COLLECTION_NAME, query, updatedDbDisplay);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update display", e).c_str());
    }
}

void MongoDisplays::remove(const uint64_t serialNumber) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("SerialNumber",(int64_t)serialNumber);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isDisplayExists(query))
    {
        throw utils::CommonException("Unable to remove. Display doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove display", e).c_str());
    }
}

void MongoDisplays::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isDisplayExists(query))
    {
        throw utils::CommonException("Unable to remove. Display doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove display", e).c_str());
    }
}

std::vector<std::shared_ptr<Display>>
MongoDisplays::getAll() const
{
    std::vector<std::shared_ptr<Display>> displaysList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbDisplay = cursor->next();
            std::shared_ptr<Display> display = this->unserialize(dbDisplay);

            displaysList.push_back(display);
        }

        return displaysList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all displays", e).c_str());
    }
}

void MongoDisplays::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all displays", e).c_str());
    }
}

mongo::BSONObj
MongoDisplays::serialize(const std::shared_ptr<Display> display) const
{
    mongo::BSONObjBuilder builder;

    builder.append("SerialNumber", (int64_t)display->getSerialNumber() );
    builder.append("NetworkAddress", display->getNetworkAddress() );
    builder.append("NumberInCasino", display->getNumberInCasino() );
    builder.append("GeneralOptionsConfId", display->getGeneralOptionsConfId() );
    builder.append("PriorityScreensConfId", display->getPriorityScreensConfId() );
    builder.append("ScenarioScreensConfId", display->getScenarioScreensConfId() );
    builder.append("Suspended", display->isSuspended() );
    builder.append("Online", display->isOnline() );

    return builder.obj();
}

std::shared_ptr<Display>
MongoDisplays::unserialize(const mongo::BSONObj dbDisplay) const
{
    int64_t serialNumber = dbDisplay.getField("SerialNumber").Long();
    uint16_t networkAddress = dbDisplay.getField("NetworkAddress").Int();
    uint16_t numberInCasino = dbDisplay.getField("NumberInCasino").Int();
    uint16_t generalOptionsConfId = dbDisplay.getField("GeneralOptionsConfId").Int();
    uint16_t priorityScreensConfId = dbDisplay.getField("PriorityScreensConfId").Int();
    uint16_t scenarioScreensConfId = dbDisplay.getField("ScenarioScreensConfId").Int();
    bool suspended = dbDisplay.getField("Suspended").Bool();
    bool online = dbDisplay.getField("Online").Bool();

    std::shared_ptr<Display> display(
            new Display(
                networkAddress,
                serialNumber,
                numberInCasino,
                generalOptionsConfId,
                priorityScreensConfId,
                scenarioScreensConfId,
                suspended));

    display->setOnline(online);

    return display;
}

bool MongoDisplays::isDisplayExists(const mongo::BSONObj& query) const
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

const std::string MongoDisplays::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
