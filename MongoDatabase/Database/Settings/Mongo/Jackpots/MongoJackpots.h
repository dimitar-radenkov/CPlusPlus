/*
 * MongoJackpots.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef MONGOJACKPOTS_H_
#define MONGOJACKPOTS_H_

#include <memory>
#include <string>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Settings/Jackpots/Jackpot.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IJackpotsQueryable.h"

namespace database {

class MongoJackpots : public IJackpotsQueryable
{
public:

    /*
     Constructor
     */
    MongoJackpots();

    /*
     Destructor
     */
    virtual ~MongoJackpots();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param jackpot Jackpot to add.
     */
    void add(const std::shared_ptr<Jackpot> jackpot) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param internalId Requsted jackpot internal id.
     @return requested jackpot object.;
     */
    std::shared_ptr<Jackpot>
    get(const uint32_t internalId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested jackpot object id.
     @return requested jackpot object.;
     */
    std::shared_ptr<Jackpot>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param internalId Jackpot to update.
     @param updatedJackpot The new jackpot witch will be placed over old
     jackpot.
     */
    void update(
            const uint32_t internalId,
            const std::shared_ptr<Jackpot> updatedJackpot) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId Jackpot objectId to update.
     @param updatedJackpot The new jackpot with will be placed over old
     jackpot.
     */
    void update(
            const std::string& objectId,
            const std::shared_ptr<Jackpot> updatedJackpot) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param internalId Jackpot internal id to remove.
     */

    void remove(const uint32_t internalId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId Jackpot object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of Jackpots
     */
    std::vector<std::shared_ptr<Jackpot>>
    getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize jackpot object to BSONObj
     @param jackpot object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<Jackpot> jackpot) const;

    /*
     Unserialize BSONObj object to jackpot object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<Jackpot>
    unserialize(const mongo::BSONObj dbJackpot) const;

    /*
     Check for level in database.
     @param query Database query.
     @return true if jackpot is found.False otherwise.
     */
    bool isJackpotExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.Jackpots";
};

} /* namespace database */
#endif /* MONGOJACKPOTS_H_ */
