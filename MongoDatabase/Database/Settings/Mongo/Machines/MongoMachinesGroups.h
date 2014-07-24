/*
 * MongoMachinesGroups.h
 *
 *  Created on: May 13, 2014
 *      Author: root
 */

#ifndef MONGOMACHINESGROUPS_H_
#define MONGOMACHINESGROUPS_H_

#include <memory>
#include <string>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Database/Driver/MongoDriver.h"
#include "Settings/Machines/MachinesGroup.h"
#include "Database/Settings/Interfaces/IMachinesGroupsQueryable.h"

namespace database
{

class MongoMachinesGroups : public IMachinesGroupsQueryable
{
public:
	MongoMachinesGroups();

	virtual ~MongoMachinesGroups();

	/*
     If get fails for some reason CommonException has been thrown.
     @param machine Machine to add.
     */
    void add(const std::shared_ptr<MachinesGroup> machinesGroup) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param serialNumber Requsted machine serial number.
     @return requested machine object.;
     */
    std::shared_ptr<MachinesGroup>
    get(const uint32_t groupId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested machine object id.
     @return requested machine object.;
     */
    std::shared_ptr<MachinesGroup>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param serialNumber Machine serial number to update.
     @param updatedMachine The new machine with will be placed over old
     machine.
     */
    void update(
            const uint32_t groupId,
            const std::shared_ptr<MachinesGroup> updatedMachine) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId Machine objectId to update.
     @param updatedMachine The new machine with will be placed over old
     machine.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<MachinesGroup> updatedMachine) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param serialNumber Machine serial number to remove.
     */

    void remove(const uint32_t groupId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId Machine object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of machines
     */
    std::vector<std::shared_ptr<MachinesGroup>> getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     @return vector of machines
     */
    void removeAll() const override;

private:
    /*
     Serialize machine object to BSONObj
     @param machine object to serialize
     */
    mongo::BSONObj serialize(const std::shared_ptr<MachinesGroup> machinesGroup) const;

    /*
     Unserialize BSONObj object to machine object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<MachinesGroup>
    unserialize(const mongo::BSONObj dbMachinesGroup) const;

    /*
     Check for machine in database.
     @param serialNumber Machine serial number to look for.
     @return true if machine is found.False otherwise.
     */
    bool isMachinesGroupExists(const mongo::BSONObj& query) const;

    /*
     Justify error message.
     @param message User message.
     @param exc throw DBException.
     */
    const std::string buildErrorMessage(
            const std::string& message,
            const mongo::DBException &exc) const;

    /**
     Collection name in database to commit
     */
    const std::string COLLECTION_NAME = "MitkoDB.MachinesGroups";
};

}

#endif /* MONGOMACHINESGROUPS_H_ */
