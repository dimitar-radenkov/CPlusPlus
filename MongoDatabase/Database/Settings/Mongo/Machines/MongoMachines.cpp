/*
 * MongoMachines.cpp
 *
 *  Created on: May 10, 2014
 *      Author: root
 */

#include "MongoMachines.h"
#include "sys/time.h"

namespace database
{

MongoMachines::MongoMachines()
{

}

MongoMachines::~MongoMachines()
{

}

void MongoMachines::add(const std::shared_ptr<Machine> machine) const
{
    if(machine == nullptr)
    {
        throw utils::CommonException("Unable to add machine. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbMachine = this->serialize(machine);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbMachine);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert machine");
    }
}

std::shared_ptr<Machine>
MongoMachines::get(const uint64_t serialNumber) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("SerialNumber",(int64_t)serialNumber);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbMachine =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<Machine> machine = this->unserialize(dbMachine);

        return machine;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get machine.", e).c_str());
    }
}

std::shared_ptr<Machine>
MongoMachines::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbMachine =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<Machine> machine = this->unserialize(dbMachine);

        return machine;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get machine.", e).c_str());
    }
}

void MongoMachines::update(
        const uint64_t serialNumber,
        const std::shared_ptr<Machine> updatedMachine) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("SerialNumber",(int64_t)serialNumber);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedMachine == nullptr)
    {
        throw utils::CommonException("Unable to update. Invalid machine pointer");
    }

    if(!this->isMachineExists(query))
    {
        throw utils::CommonException("Unable to update. Machine doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbMachine = this->serialize(updatedMachine);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbMachine);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update machine", e).c_str());
    }
}

void MongoMachines::update(
        const std::string& objectId,
        const std::shared_ptr<Machine> updatedMachine) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedMachine == nullptr)
    {
        throw utils::CommonException("Unable to update. Invalid machine pointer");
    }

    if(!this->isMachineExists(query))
    {
        throw utils::CommonException("Unable to update. Machine doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbMachine = this->serialize(updatedMachine);

        MongoDriver::getInstance().getConnection().
                update(COLLECTION_NAME, query, updatedDbMachine);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update machine", e).c_str());
    }
}

void MongoMachines::remove(const uint64_t serialNumber) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("SerialNumber",(int64_t)serialNumber);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isMachineExists(query))
    {
        throw utils::CommonException("Unable to remove. Machine doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove machine", e).c_str());
    }
}

void MongoMachines::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isMachineExists(query))
    {
        throw utils::CommonException("Unable to remove. Machine doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove machine", e).c_str());
    }
}

std::vector<std::shared_ptr<Machine>>
MongoMachines::getAll() const
{
    std::vector<std::shared_ptr<Machine>> machinesList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbMachine = cursor->next();
            std::shared_ptr<Machine> level = this->unserialize(dbMachine);

            machinesList.push_back(level);
        }

        return machinesList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all machines", e).c_str());
    }
}

void MongoMachines::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all machines", e).c_str());
    }
}

mongo::BSONObj
MongoMachines::serialize(const std::shared_ptr<Machine> machine) const
{
    mongo::BSONObjBuilder builder;
    builder.append("SerialNumber", (int64_t)machine->getSerialNumber() );
    builder.append("Name", machine->getName() );
    builder.append("NetworkAddress", machine->getNetworkAddress() );
    builder.append("NumberInCasino", machine->getNumberInCasino() );

    //create nested array for games info
    std::vector<GameInfo> gamesInfo = machine->getGamesInfoList();

    if(!gamesInfo.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itGameInfo = gamesInfo.begin();
        for( ; itGameInfo != gamesInfo.end(); ++itGameInfo)
        {
            mongo::BSONObjBuilder gameInfoBuilder;
            gameInfoBuilder.append("GameId", itGameInfo->gameId);
            gameInfoBuilder.append("GameVersion", itGameInfo->gameVersion);
            gameInfoBuilder.append("DenominationId", itGameInfo->denominationId);
            gameInfoBuilder.append("MinBetPerLine", itGameInfo->minBetPerLine);
            gameInfoBuilder.append("MaxBetPerLine", itGameInfo->maxBetPerLine);
            gameInfoBuilder.append("MinNumberOfLines", itGameInfo->minNumberOfLines);
            gameInfoBuilder.append("NumberOfLines", itGameInfo->numberOfLines);
            gameInfoBuilder.append("TheoreticalPercentage", itGameInfo->theoreticalPercentage);

            arrayBuilder.append(gameInfoBuilder.obj());
        }

        builder.append("GamesInfoList", arrayBuilder.arr());
    }

    builder.append("Suspended", machine->isSuspended() );

    return builder.obj();
}

std::shared_ptr<Machine>
MongoMachines::unserialize(const mongo::BSONObj dbMachine) const
{
    int64_t serialNumber = dbMachine.getField("SerialNumber").Long();
    std::string name = dbMachine.getField("Name").String();
    uint16_t networkAddress = dbMachine.getField("NetworkAddress").Int();
    uint16_t numberInCasino = dbMachine.getField("NumberInCasino").Int();

    std::vector<GameInfo> gamesInfo;

    if (dbMachine.hasField("GamesInfoList"))
    {
        std::vector<mongo::BSONElement> arrayOfGamesInfo =
                dbMachine.getField("GamesInfoList").Array();

        if(!arrayOfGamesInfo.empty())
        {
            //iterate over Games Info list
            auto itArray = arrayOfGamesInfo.begin();
            for( ; itArray != arrayOfGamesInfo.end() ; ++itArray)
            {
                mongo::BSONObj dbGameInfo = itArray->Obj();

                GameInfo gameInfo;

                gameInfo.gameId = dbGameInfo.getField("GameId").Int();
                gameInfo.gameVersion = dbGameInfo.getField("GameVersion").String();
                gameInfo.denominationId = dbGameInfo.getField("DenominationId").Int();
                gameInfo.minBetPerLine = dbGameInfo.getField("MinBetPerLine").Int();
                gameInfo.maxBetPerLine = dbGameInfo.getField("MaxBetPerLine").Int();
                gameInfo.minNumberOfLines = dbGameInfo.getField("MinNumberOfLines").Int();
                gameInfo.numberOfLines = dbGameInfo.getField("NumberOfLines").Int();
                gameInfo.theoreticalPercentage = dbGameInfo.getField("TheoreticalPercentage").Int();

                gamesInfo.push_back(gameInfo);
            }
        }
    }
    bool suspended = dbMachine.getField("Suspended").Bool();

    std::shared_ptr<Machine> machine(
            new Machine(
                serialNumber,
                name,
                networkAddress,
                numberInCasino,
                gamesInfo,
                suspended));

    return machine;
}

bool MongoMachines::isMachineExists(const mongo::BSONObj& query) const
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

const std::string MongoMachines::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

}
