/*
 * MongoJackpots.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "MongoJackpots.h"

namespace database {

MongoJackpots::MongoJackpots()
{}

MongoJackpots::~MongoJackpots()
{}

void MongoJackpots::add(
        const std::shared_ptr<Jackpot> jackpot) const
{
    if(jackpot == nullptr)
    {
        throw utils::CommonException(
            "Unable to add jackpot. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbJackpot = this->serialize(jackpot);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbJackpot);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert jackpot");
    }
}

std::shared_ptr<Jackpot>
MongoJackpots::get(const uint32_t internalId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbJackpot =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<Jackpot> jackpot =
                this->unserialize(dbJackpot);

        return jackpot;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get jackpot.", e).c_str());
    }
}

std::shared_ptr<Jackpot>
MongoJackpots::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbJackpot =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<Jackpot> jackpot = this->unserialize(dbJackpot);

        return jackpot;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get jackpot.", e).c_str());
    }
}

void MongoJackpots::update(
        const uint32_t internalId,
        const std::shared_ptr<Jackpot> updatedJackpot) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedJackpot == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid jackpot pointer");
    }

    if(!this->isJackpotExists(query))
    {
        throw utils::CommonException(
            "Unable to update. Jackpot doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbJackpot = this->serialize(updatedJackpot);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbJackpot);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update jackpot", e).c_str());
    }
}

void MongoJackpots::update(
        const std::string& objectId,
        const std::shared_ptr<Jackpot> updatedJackpot) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedJackpot == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid jackpot pointer");
    }

    if(!this->isJackpotExists(query))
    {
        throw utils::CommonException(
            "Unable to update. Jackpot doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbJackpot = this->serialize(updatedJackpot);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbJackpot);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update jackpot", e).c_str());
    }
}

void MongoJackpots::remove(const uint32_t internalId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isJackpotExists(query))
    {
        throw utils::CommonException(
                "Unable to remove. Jackpot doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove jackpot", e).c_str());
    }
}

void MongoJackpots::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isJackpotExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. Jackpot doesn't exists");
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

std::vector<std::shared_ptr<Jackpot>>
MongoJackpots::getAll() const
{
    std::vector<std::shared_ptr<Jackpot>> jackpotslevelsList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbJackpot = cursor->next();
            std::shared_ptr<Jackpot> jackpot = this->unserialize(dbJackpot);

            jackpotslevelsList.push_back(jackpot);
        }

        return jackpotslevelsList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all jackpots", e).c_str());
    }
}

void MongoJackpots::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all jackpots", e).c_str());
    }
}

mongo::BSONObj
MongoJackpots::serialize(
        const std::shared_ptr<Jackpot> jackpot) const
{
    mongo::BSONObjBuilder builder;

    builder.append("JackpotType", jackpot->getType() );
    builder.append("JackpotSubType", jackpot->getSubType() );
    builder.append("Name", jackpot->getName() );
    builder.append("GameId", jackpot->getGameId() );
    builder.append("ProtocolType", jackpot->getProtocolType() );
    builder.append("MultilevelsLimit", jackpot->getMultilevelsNumberLimit() );
    builder.append("InternalId", jackpot->getInternalId() );
    builder.append("ExternalId", jackpot->getExternalId() );
    builder.append("SessionId", jackpot->getSessionId() );
    builder.append("InternalNetworkId", jackpot->getInternalNetworkId() );
    builder.append("ExternalNetworkId", jackpot->getExternalNetworkId() );

    std::map<uint32_t, uint32_t> multilevelsList = jackpot->getMultilevels();
    if(!multilevelsList.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itMultilevel = multilevelsList.begin();
        for( ; itMultilevel != multilevelsList.end(); ++itMultilevel)
        {
            mongo::BSONObjBuilder listBuilder;
            listBuilder.append("Number", itMultilevel->first);
            listBuilder.append("MultilevelId", itMultilevel->second);

            arrayBuilder.append(listBuilder.obj());
        }

        builder.append("Multilevels", arrayBuilder.arr());
    }

    std::set<uint32_t> attachedMachinesGroupsIds =
            jackpot->getAttachedMachinesGroupsIds();
    if(!attachedMachinesGroupsIds.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itMachinesGroupId = attachedMachinesGroupsIds.begin();
        for( ; itMachinesGroupId != attachedMachinesGroupsIds.end(); ++itMachinesGroupId)
        {
            arrayBuilder.append(*itMachinesGroupId);
        }

        builder.append("AttachedMachinesGroupsIds", arrayBuilder.arr());
    }

    return builder.obj();
}

std::shared_ptr<Jackpot>
MongoJackpots::unserialize(const mongo::BSONObj dbJackpot) const
{
    JackpotType type =
            (JackpotType)dbJackpot.getField("JackpotType").Int();
    uint16_t subType = dbJackpot.getField("JackpotSubType").Int();
    std::string name = dbJackpot.getField("Name").String();
    uint16_t gameId = dbJackpot.getField("GameId").Int();
    ProtocolType protocolType =
            (ProtocolType)dbJackpot.getField("ProtocolType").Int();
    uint16_t multilevelsLimit = dbJackpot.getField("MultilevelsLimit").Int();
    uint32_t internalId = dbJackpot.getField("InternalId").Int();
    uint32_t externalId = dbJackpot.getField("ExternalId").Int();
    uint32_t sessionId = dbJackpot.getField("SessionId").Int();
    uint32_t internalNetworkId = dbJackpot.getField("InternalNetworkId").Int();
    uint32_t externalNetworkId = dbJackpot.getField("ExternalNetworkId").Int();

    std::shared_ptr<Jackpot> jackpot (
            new Jackpot(
                   type,
                   subType,
                   name,
                   gameId,
                   protocolType,
                   multilevelsLimit,
                   internalId,
                   externalId,
                   sessionId,
                   internalNetworkId,
                   externalNetworkId));

    if (dbJackpot.hasField("Multilevels"))
    {
        std::vector<mongo::BSONElement> arrayOfMultilevelsList =
                dbJackpot.getField("Multilevels").Array();

        if(!arrayOfMultilevelsList.empty())
        {
            auto itArray = arrayOfMultilevelsList.begin();
            for( ; itArray != arrayOfMultilevelsList.end() ; ++itArray)
            {
                mongo::BSONObj dbMultilevel = itArray->Obj();

                uint32_t number = dbMultilevel.getField("Number").Int();
                uint32_t multilevelId = dbMultilevel.getField("MultilevelId").Int();

                jackpot->addMultilevel(number, multilevelId);
            }
        }
    }

    if (dbJackpot.hasField("AttachedMachinesGroupsIds"))
    {
        std::vector<mongo::BSONElement> arrayOfMachinesGroupsIDs =
                dbJackpot.getField("AttachedMachinesGroupsIds").Array();

        if(!arrayOfMachinesGroupsIDs.empty())
        {
            //iterate over machine serial numbers
            auto itArray = arrayOfMachinesGroupsIDs.begin();
            for( ; itArray != arrayOfMachinesGroupsIDs.end() ; ++itArray)
            {
                uint32_t machinesGroupId = itArray->Int();
                jackpot->attachMachinesGroup(machinesGroupId);
            }
        }
    }

    return jackpot;
}

bool MongoJackpots::isJackpotExists(const mongo::BSONObj& query) const
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

const std::string MongoJackpots::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
