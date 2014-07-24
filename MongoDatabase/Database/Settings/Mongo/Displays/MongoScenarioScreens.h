/*
 * MongoScenarioScreens.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef MONGOSCENARIOSCREENS_H_
#define MONGOSCENARIOSCREENS_H_

#include <memory>

#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/IScenarioScreensQueryable.h"
#include "Settings/Displays/ScreenDescription.h"
#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"

namespace database
{

class MongoScenarioScreens : public IScenarioScreensQueryable
{
public:
    MongoScenarioScreens();

    virtual ~MongoScenarioScreens();

public:
    /*
     If get fails for some reason CommonException has been thrown.
     @param screen ScreenDescription to add.
     */
    void
    add
    (const std::shared_ptr<ScreenDescription> screen) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param screen Requsted ScreenDescription screenId.
     @return requested ScreenDescription object.;
     */
    std::shared_ptr<ScreenDescription>
    get(const uint16_t screenId) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @param objectId Requested ScreenDescription object id.
     @return requested ScreenDescription object.;
     */
    std::shared_ptr<ScreenDescription>
    get(const std::string &objectId) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param screenId ScreenDescription screenId to update.
     @param updatedConfiguration The new ScreenDescription witch will
     be placed over the old one.
     */
    void
    update
    (const uint16_t screenId,
     const std::shared_ptr<ScreenDescription> updatedConfiguration) const override;

    /*
     If update fails for some reason CommonException has been thrown.
     @param objectId ScreenDescription objectId to update.
     @param updatedConfiguration The new ScreenDescription witch will
     be placed over the old one.
     */
    void
    update
    (const std::string& objectId,
     const std::shared_ptr<ScreenDescription> updatedConfiguration) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param screenId ScreenDescription screenId to remove.
     */

    void remove(const uint16_t screenId) const override;

    /*
     If remove fails for some reason CommonException has been thrown.
     @param objectId ScreenDescription object id to remove.
     */
    void remove(const std::string& objectId) const override;

    /*
     If getting fails for some reason CommonException has been thrown.
     @return vector of ScreenDescription
     */
    std::vector<std::shared_ptr<ScreenDescription>>
    getAll() const override;

    /*
     If removing fails for some reason CommonException has been thrown.
     */
    void removeAll() const override;

private:
    /*
     Serialize ScreenDescription object to BSONObj
     @param screen object to serialize
     */
    mongo::BSONObj
    serialize
    (const std::shared_ptr<ScreenDescription> screen) const;

    /*
     Unserialize BSONObj object to ScreenDescription object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<ScreenDescription>
    unserialize(const mongo::BSONObj dbScreen) const;

    /*
     Check for ScreenDescription in database.
     @return true if screen is found.False otherwise.
     */
    bool isScreenExists(const mongo::BSONObj& query) const;

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
    const std::string COLLECTION_NAME = "MitkoDB.ScenarioScreens";

};

} /* namespace database */
#endif /* MONGOSCENARIOSCREENS_H_ */
