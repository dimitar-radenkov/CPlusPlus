/*
 * MongoDisplays.h
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#ifndef MONGODISPLAYS_H_
#define MONGODISPLAYS_H_

#include <memory>
#include <vector>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Settings/Displays/Display.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IDisplaysQueryable.h"

namespace database
{

class MongoDisplays : public IDisplaysQueryable
{

public:

    /*
     *
     */
    MongoDisplays();

    /*
     *
     */
    virtual ~MongoDisplays();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param display Display to add.
     */
    void add(const std::shared_ptr<Display> display) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param serialNumber Requsted display serial number.
     @return requested display object.;
     */
    std::shared_ptr<Display> get(const uint64_t serialNumber) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested display object id.
     @return requested display object.;
     */
    std::shared_ptr<Display> get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param serialNumber Display serial number to update.
     @param updatedDisplay The new display with will be placed over old
     display.
     */
    void update(
            const uint64_t serialNumber,
            const std::shared_ptr<Display> updatedDisplay) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId Display objectId to update.
     @param updatedDisplay The new display with will be placed over old
     display.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<Display> updatedDisplay) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param serialNumber Display serial number to remove.
     */

    void remove(const uint64_t serialNumber) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId Display object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of displays
     */
    std::vector<std::shared_ptr<Display>> getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     @return vector of displays
     */
    void removeAll() const override;

private:
    /*
     Serialize display object to BSONObj
     @param display object to serialize
     */
    mongo::BSONObj serialize(const std::shared_ptr<Display> display) const;

    /*
     Unserialize BSONObj object to display object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<Display> unserialize(const mongo::BSONObj dbDisplay) const;

    /*
     Check for display in database.
     @param serialNumber Display serial number to look for.
     @return true if display is found.False otherwise.
     */
    bool isDisplayExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.Displays";
};

} /* namespace database */
#endif /* MONGODISPLAYS_H_ */
