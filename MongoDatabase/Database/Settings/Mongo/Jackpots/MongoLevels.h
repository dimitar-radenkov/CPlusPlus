/*
 * MongoLevels.h
 *
 *  Created on: May 20, 2014
 *      Author: root
 */

#ifndef MONGOLEVELS_H_
#define MONGOLEVELS_H_

#include <memory>
#include <string>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/ILevelsQueryable.h"

namespace database
{

class MongoLevels : public ILevelsQueryable
{

public:

    /*
     Constructor
     */
    MongoLevels();

    /*
     Destructor
     */
    virtual ~MongoLevels();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param level ProgressiveLevel to add.
     */
    void add(const std::shared_ptr<ProgressiveLevel> level) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param internalId Requsted level internal id.
     @return requested progressive level object.;
     */
    std::shared_ptr<ProgressiveLevel>
    get(const uint32_t internalId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested level object id.
     @return requested progressive level object.;
     */
    std::shared_ptr<ProgressiveLevel>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param internalId ProgressiveLevel to update.
     @param updatedLevel The new level witch will be placed over old
     level.
     */
    void update(
            const uint32_t internalId,
            const std::shared_ptr<ProgressiveLevel> updatedLevel) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId Level objectId to update.
     @param updatedMachine The new machine with will be placed over old
     machine.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<ProgressiveLevel> updatedLevel) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param internalId ProgressiveLevel internal id to remove.
     */

    void remove(const uint32_t internalId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId ProgressiveLevel object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of ProgressiveLevels
     */
    std::vector<std::shared_ptr<ProgressiveLevel>>
    getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize level object to BSONObj
     @param level object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<ProgressiveLevel> level) const;

    /*
     Unserialize BSONObj object to level object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<ProgressiveLevel>
    unserialize(const mongo::BSONObj dbLevel) const;

    /*
     Check for level in database.
     @param query Database query.
     @return true if level is found.False otherwise.
     */
    bool isLevelExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.Levels";
};

}//database

#endif /* MONGOLEVELS_H_ */
