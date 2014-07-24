/*
 * MongoMachinesGroups.cpp
 *
 *  Created on: May 13, 2014
 *      Author: root
 */

#include "MongoMachinesGroups.h"

namespace database
{

MongoMachinesGroups::MongoMachinesGroups()
{
	// TODO Auto-generated constructor stub

}

MongoMachinesGroups::~MongoMachinesGroups()
{
	// TODO Auto-generated destructor stub

}

void MongoMachinesGroups::add(
        const std::shared_ptr<MachinesGroup> machinesGroup) const
{
    if(machinesGroup == nullptr)
    {
        throw utils::CommonException("Unable to add machines group. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbMachinesGroup = this->serialize(machinesGroup);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbMachinesGroup);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert machine");
    }
}

std::shared_ptr<MachinesGroup>
MongoMachinesGroups::get(const uint32_t groupId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("GroupId", groupId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbMachinesGroup =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<MachinesGroup> machinesGroup =
                this->unserialize(dbMachinesGroup);

        return machinesGroup;
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get machines group.", e).c_str());
    }
}

std::shared_ptr<MachinesGroup>
MongoMachinesGroups::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbMachinesGroup =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<MachinesGroup> machinesGroup = this->unserialize(dbMachinesGroup);

        return machinesGroup;
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get machines group.", e).c_str());
    }
}

void MongoMachinesGroups::update(
        const uint32_t groupId,
        const std::shared_ptr<MachinesGroup> updatedMachinesGroup) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("GroupId", groupId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedMachinesGroup == nullptr)
    {
        throw utils::CommonException(
                "Unable to update. Invalid machines group pointer");
    }

    if(!this->isMachinesGroupExists(query))
    {
        throw utils::CommonException(
                "Unable to update. Machines group doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbMachinesGroup =
                this->serialize(updatedMachinesGroup);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbMachinesGroup);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update machines group", e).c_str());
    }
}

void MongoMachinesGroups::update(
        const std::string& objectId,
        const std::shared_ptr<MachinesGroup> updatedMachinesGroup) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedMachinesGroup == nullptr)
    {
        throw utils::CommonException(
                "Unable to update. Invalid machines group pointer");
    }

    if(!this->isMachinesGroupExists(query))
    {
        throw utils::CommonException(
                "Unable to update. Machines group doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbMachine = this->serialize(updatedMachinesGroup);

        MongoDriver::getInstance().getConnection().
                update(COLLECTION_NAME, query, updatedDbMachine);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update machine", e).c_str());
    }
}

void MongoMachinesGroups::remove(const uint32_t groupId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("GroupId", groupId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isMachinesGroupExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. Machines group doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove machines group", e).c_str());
    }
}

void MongoMachinesGroups::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isMachinesGroupExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. Machines group doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove machines group", e).c_str());
    }
}

std::vector<std::shared_ptr<MachinesGroup>>
MongoMachinesGroups::getAll() const
{
    std::vector<std::shared_ptr<MachinesGroup>> machinesGroupList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbMachinesGroup = cursor->next();
            std::shared_ptr<MachinesGroup> machinesGroup =
                    this->unserialize(dbMachinesGroup);

            machinesGroupList.push_back(machinesGroup);
        }

        return machinesGroupList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all machines group", e).c_str());
    }
}

void MongoMachinesGroups::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException& ex)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all machines group", ex).c_str());
    }
}

mongo::BSONObj
MongoMachinesGroups::serialize(
        const std::shared_ptr<MachinesGroup> machinesGroup) const
{
    mongo::BSONObjBuilder builder;
    builder.append("GroupId", machinesGroup->getId() );
    builder.append("SessionId", machinesGroup->getSessionId() );
    builder.append("MachinesNumberLimit", machinesGroup->getMachinesNumberLimit() );
    builder.append("Name", machinesGroup->getName() );

    //create nested array for machines serial numbers
    std::set<uint64_t> machinesSerialNumbers =  machinesGroup->getMachinesList();

    if(!machinesSerialNumbers.empty() )
    {
        mongo::BSONArrayBuilder arrayBuilder;
        auto itMachineSerial = machinesSerialNumbers.begin();
        for( ; itMachineSerial != machinesSerialNumbers.end(); ++itMachineSerial)
        {
            arrayBuilder.append((int64_t)*itMachineSerial);
        }

        builder.append("MachinesList", arrayBuilder.arr());
    }

    return builder.obj();
}

std::shared_ptr<MachinesGroup>
MongoMachinesGroups::unserialize(const mongo::BSONObj dbMachinesGroup) const
{
    uint32_t groupId = dbMachinesGroup.getField("GroupId").Int();
    uint32_t sessionId = dbMachinesGroup.getField("SessionId").Int();
    uint16_t machinesNumberLimit =
            dbMachinesGroup.getField("MachinesNumberLimit").Int();
    std::string name = dbMachinesGroup.getField("Name").String();

    std::shared_ptr<MachinesGroup> machinesGroup(
                new MachinesGroup(
                    groupId,
                    sessionId,
                    machinesNumberLimit,
                    name));

    if (dbMachinesGroup.hasField("MachinesList"))
    {
        std::vector<mongo::BSONElement> arrayOfSerials =
            dbMachinesGroup.getField("MachinesList").Array();

        if(!arrayOfSerials.empty())
        {
            //iterate over machine serial numbers
            auto itArray = arrayOfSerials.begin();
            for( ; itArray != arrayOfSerials.end() ; ++itArray)
            {
                uint64_t serialNumber = itArray->Long();
                machinesGroup->addMachine(serialNumber);
            }
        }
    }

    return machinesGroup;
}

bool MongoMachinesGroups::isMachinesGroupExists(const mongo::BSONObj& query) const
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

const std::string MongoMachinesGroups::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

}
