/*
 * MongoMultilevels.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef MONGOMULTILEVELS_H_
#define MONGOMULTILEVELS_H_

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Settings/Jackpots/ProgressiveMultilevel.h"
#include "Settings/Jackpots/Definitions/MultilevelType.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IMultilevelsQueryable.h"

namespace database
{

class MongoMultilevels : public IMultilevelsQueryable
{
public:

    /*
     Constructor
     */
    MongoMultilevels();

    /*
     Destructor
     */
    virtual ~MongoMultilevels();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param multilevel ProgressiveMultilevel to add.
     */
    void add(
            const std::shared_ptr<ProgressiveMultilevel> multilevel) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param internalId Requsted ProgressiveMultilevel internal id.
     @return requested ProgressiveMultilevel level object.;
     */
    std::shared_ptr<ProgressiveMultilevel>
    get(const uint32_t internalId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested ProgressiveMultilevel object id.
     @return requested ProgressiveMultilevel object.;
     */
    std::shared_ptr<ProgressiveMultilevel>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param internalId ProgressiveMultilevel to update.
     @param updatedMultilevel The new multilevel witch will be placed over old
     level.
     */
    void update(
            const uint32_t internalId,
            const std::shared_ptr<ProgressiveMultilevel> updatedMultilevel) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId Level objectId to update.
     @param updatedMultilevel The new multilevel with will be placed over old
     machine.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<ProgressiveMultilevel> updatedMultilevel) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param internalId ProgressiveMultilevel internal id to remove.
     */

    void remove(const uint32_t internalId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId ProgressiveMultilevel object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of ProgressiveLevels
     */
    std::vector<std::shared_ptr<ProgressiveMultilevel>>
    getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize multilevel object to BSONObj
     @param level object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<ProgressiveMultilevel> multilevel) const;

    /*
     Unserialize BSONObj object to ProgressiveMultilevel object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<ProgressiveMultilevel>
    unserialize(const mongo::BSONObj dbMultielevel) const;

    /*
     Check for multilevel in database.
     @param query Database query.
     @return true if level is found.False otherwise.
     */
    bool isMultilevelExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.Multilevels";
};

} /* namespace database */

#endif /* MONGOMULTILEVELS_H_ */
