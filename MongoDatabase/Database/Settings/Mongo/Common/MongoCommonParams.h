/*
 * MongoCommonParams.h
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#ifndef MONGOCOMMONPARAMS_H_
#define MONGOCOMMONPARAMS_H_

#include <memory>
#include <vector>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Settings/Displays/Display.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/Settings/Interfaces/ICommonParamsQueryable.h"

namespace database
{

class MongoCommonParams : public ICommonParamsQueryable
{

public:

    MongoCommonParams();

    virtual ~MongoCommonParams();

public:

    /*
     If get fails for some reason CommonException has been thrown.
     @param commonParams CommonParams object to add.It will replace existing
     common params in database.
     */
    void add(const std::shared_ptr<CommonParams> commonParams) const override;

    /*
     If get fails for some reason CommonException has been thrown.
     Removes currently saved common params in database
     */
    void remove() const override;

    /*
     If get fails for some reason CommonException has been thrown.
     @return CommonParams object.;
     */
    std::shared_ptr<CommonParams> get() const override;

private:
    /*
     Serialize CommonParams object to BSONObj
     @param commonParams object to serialize
     */
    mongo::BSONObj
    serialize(const std::shared_ptr<CommonParams> commonParams) const;

    /*
     Unserialize BSONObj object to display object
     @param BSONObj object to unserialize
     */
    std::shared_ptr<CommonParams>
    unserialize(const mongo::BSONObj dbCommonParams) const;

    /*
     Check for CommonParams in database.
     @param query Serialized mongo object.
     @return true if display is found.False otherwise.
     */
    bool isCommonParamsExists(const mongo::BSONObj& query) const;

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
#endif /* MONGOCOMMONPARAMS_H_ */
