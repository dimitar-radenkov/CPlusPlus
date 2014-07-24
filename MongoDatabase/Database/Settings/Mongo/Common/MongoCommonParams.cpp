/*
 * MongoCommonParams.cpp
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#include "MongoCommonParams.h"

namespace database
{

MongoCommonParams::MongoCommonParams()
{

}

MongoCommonParams::~MongoCommonParams()
{

}

void MongoCommonParams::add(std::shared_ptr<CommonParams> commonParams) const
{
    if(commonParams == nullptr)
    {
        throw utils::CommonException("Unable to add common params. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbCommonParams = this->serialize(commonParams);

        //remove previous
        MongoDriver::getInstance().getConnection().
                dropCollection(COLLECTION_NAME);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbCommonParams);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert CommonParams");
    }
}

void MongoCommonParams::remove() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove CommonParams.", e).c_str());
    }
}

std::shared_ptr<CommonParams> MongoCommonParams::get() const
{
    try
    {
        const mongo::BSONObj dbCommonParams =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, mongo::BSONObj());

        std::shared_ptr<CommonParams> commonParams =
            this->unserialize(dbCommonParams);

        return commonParams;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get CommonParams.", e).c_str());
    }
}

mongo::BSONObj
MongoCommonParams::serialize(const std::shared_ptr<CommonParams> commonParams) const
{
    mongo::BSONObjBuilder builder;
    builder.append("JurisdictionLimit", commonParams->jurisdictionLimit );
    builder.append("CasinoName", commonParams->casinoName );
    builder.append("CasinoLocation", commonParams->casinoLocation );
    builder.append("CurrencyCode", commonParams->currencyCode );
    builder.append("AutomaticOverflow", commonParams->automaticOverflow );
    builder.append("AutoLogValuesTime", commonParams->autoLogValuesTime );

    return builder.obj();
}

std::shared_ptr<CommonParams>
MongoCommonParams::unserialize(const mongo::BSONObj dbCommonParams) const
{
    uint16_t jurisdictionLimit = dbCommonParams.getField("JurisdictionLimit").Int();
    std::string casinoName = dbCommonParams.getField("CasinoName").String();
    std::string casinoLocation = dbCommonParams.getField("CasinoLocation").String();
    std::string currencyCode = dbCommonParams.getField("CurrencyCode").String();
    bool automaticOverflow = dbCommonParams.getField("AutomaticOverflow").Bool();
    uint16_t autoLogValuesTime = dbCommonParams.getField("AutoLogValuesTime").Int();

    std::shared_ptr<CommonParams> commonParams(
            new CommonParams(
                jurisdictionLimit,
                casinoName,
                casinoLocation,
                currencyCode,
                automaticOverflow,
                autoLogValuesTime) );

    return commonParams;
}

bool MongoCommonParams::isCommonParamsExists(const mongo::BSONObj& query) const
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

const std::string MongoCommonParams::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
