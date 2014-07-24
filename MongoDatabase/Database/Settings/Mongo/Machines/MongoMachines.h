/*
 * DBMachines.h
 *
 *  Created on: May 10, 2014
 *      Author: root
 */

#ifndef MONGOMACHINES_H_
#define MONGOMACHINES_H_

#include <memory>
#include <string>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Settings/Machines/Machine.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IMachinesQueryable.h"

namespace database
{

/*
 Class to interact with mongo machines collection
 */
class MongoMachines : public IMachinesQueryable
{

public:

    /*
     *
     */
    MongoMachines();

    /*
     *
     */
    virtual ~MongoMachines();

public:

    /*
	 If get fails for some reason CommonException has been thrown.
	 @param machine Machine to add.
     */
    void add(const std::shared_ptr<Machine> machine) const override;

    /*
	 If get fails for some reason CommonException has been thrown.
	 @param serialNumber Requsted machine serial number.
	 @return requested machine object.;
     */
    std::shared_ptr<Machine> get(const uint64_t serialNumber) const override;

    /*
	 If get fails for some reason CommonException has been thrown.
	 @param objectId Requested machine object id.
	 @return requested machine object.;
     */
    std::shared_ptr<Machine> get(const std::string &objectId) const override;

    /*
	 If update fails for some reason CommonException has been thrown.
	 @param serialNumber Machine serial number to update.
	 @param updatedMachine The new machine with will be placed over old
	 machine.
     */
    void update(
            const uint64_t serialNumber,
            const std::shared_ptr<Machine> updatedMachine) const override;

    /*
	 If update fails for some reason CommonException has been thrown.
	 @param objectId Machine objectId to update.
	 @param updatedMachine The new machine with will be placed over old
	 machine.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<Machine> updatedMachine) const override;

    /*
	 If remove fails for some reason CommonException has been thrown.
	 @param serialNumber Machine serial number to remove.
     */

    void remove(const uint64_t serialNumber) const override;

    /*
	 If remove fails for some reason CommonException has been thrown.
	 @param objectId Machine object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of machines
     */
    std::vector<std::shared_ptr<Machine>> getAll() const override;

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
    mongo::BSONObj serialize(const std::shared_ptr<Machine> machine) const;

    /*
	 Unserialize BSONObj object to machine object
	 @param BSONObj object to unserialize
     */
    std::shared_ptr<Machine> unserialize(const mongo::BSONObj dbMachine) const;

    /*
     Check for machine in database.
     @param serialNumber Machine serial number to look for.
     @return true if machine is found.False otherwise.
     */
    bool isMachineExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.Machines";
};

}

#endif /* MONGOMACHINES_H_ */
