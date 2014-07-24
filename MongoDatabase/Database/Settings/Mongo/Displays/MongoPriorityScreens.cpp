/*
 * MongoPriorityScreens.cpp
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#include "MongoPriorityScreens.h"

namespace database
{

MongoPriorityScreens::MongoPriorityScreens()
{

}

MongoPriorityScreens::~MongoPriorityScreens()
{

}

void MongoPriorityScreens::add
(const std::shared_ptr<ScreenDescription> screen) const
{
    if(screen == nullptr)
    {
        throw utils::CommonException(
            "Unable to add PriorityScreens. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbScreen = this->serialize(screen);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbScreen);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert PriorityScreens");
    }
}

std::shared_ptr<ScreenDescription>
MongoPriorityScreens::get(const uint16_t screenId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ScreenId", screenId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbScreen =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ScreenDescription> screen =
            this->unserialize(dbScreen);

        return screen;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get PriorityScreens.", e).c_str());
    }
}

std::shared_ptr<ScreenDescription>
MongoPriorityScreens::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbScreen =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ScreenDescription> screen =
            this->unserialize(dbScreen);

        return screen;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get PriorityScreens.", e).c_str());
    }
}

void
MongoPriorityScreens::update
(const uint16_t screenId,
 const std::shared_ptr<ScreenDescription> updatedScreen) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ScreenId", screenId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedScreen == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid PriorityScreens pointer");
    }

    if(!this->isScreenExists(query))
    {
        throw utils::CommonException(
            "Unable to update. PriorityScreens doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbScreen =
                this->serialize(updatedScreen);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbScreen);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to update PriorityScreens", e).c_str());
    }
}

void MongoPriorityScreens::update(
        const std::string& objectId,
        const std::shared_ptr<ScreenDescription> updatedScreen) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedScreen == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid PriorityScreens pointer");
    }

    if(!this->isScreenExists(query))
    {
        throw utils::CommonException(
            "Unable to update. PriorityScreens doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbScreen =
            this->serialize(updatedScreen);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbScreen);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to update PriorityScreens", e).c_str());
    }
}

void MongoPriorityScreens::remove(const uint16_t screenId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("ScreenId", screenId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isScreenExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. PriorityScreens doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to remove PriorityScreens", e).c_str());
    }
}

void MongoPriorityScreens::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isScreenExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. PriorityScreens doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to remove PriorityScreens", e).c_str());
    }
}

std::vector<std::shared_ptr<ScreenDescription>>
MongoPriorityScreens::getAll() const
{
    std::vector<std::shared_ptr<ScreenDescription>> screenList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbScreen = cursor->next();
            std::shared_ptr<ScreenDescription> screen =
                this->unserialize(dbScreen);

            screenList.push_back(screen);
        }

        return screenList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to get all PriorityScreens", e).c_str());
    }
}

void MongoPriorityScreens::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage(
                "Unable to remove all PriorityScreens", e).c_str());
    }
}

mongo::BSONObj
MongoPriorityScreens::serialize
(const std::shared_ptr<ScreenDescription> screen) const
{
    mongo::BSONObjBuilder builder;
    builder.append("ScreenId", screen->uniqueId() );
    builder.append("Type", screen->type() );
    builder.append("Label", screen->label() );
    builder.append("JackpotId", screen->jackpotGroupId() );
    builder.append("Index", screen->index() );
    builder.append("StayVisibleTime", screen->stayVisibleTime() );
    builder.append("RepeatSoundInterval", screen->repeatSoundInterval() );
    builder.append("VolumeLevel", screen->volumeLevel() );

    StatusLineDescription statusLine = screen->statusLine();

    if(statusLine.type != StatusLineType::NoneStatusLineType)
    {
        mongo::BSONObjBuilder slBuilder;
        slBuilder.append("Type", statusLine.type);
        slBuilder.append("AppearProgramType", statusLine.appearProgramType);
        slBuilder.append("DisappearProgramType", statusLine.disappearProgramType);
        slBuilder.append("StayVisibleTime", statusLine.stayVisibleTime);
        slBuilder.append("TimeBetweenMessages", statusLine.timeBetweenMessages);
        slBuilder.append("TextsConfigurationId", statusLine.textsConfId);

        builder.append("StatusLine", slBuilder.obj() );
    }

    return builder.obj();
}

std::shared_ptr<ScreenDescription>
MongoPriorityScreens::unserialize
(const mongo::BSONObj dbScreen) const
{
    uint16_t screenId = dbScreen.getField("ScreenId").Int();
    ScreenType screenType = (ScreenType)dbScreen.getField("Type").Int();
    std::string label = dbScreen.getField("Label").String();
    uint16_t jackpotId = dbScreen.getField("JackpotId").Int();
    uint16_t index = dbScreen.getField("Index").Int();
    uint32_t stayVisibleTime = dbScreen.getField("StayVisibleTime").Int();
    uint32_t repeatSoundInterval = dbScreen.getField("RepeatSoundInterval").Int();
    int16_t volumeLevel = dbScreen.getField("VolumeLevel").Int();

    StatusLineDescription statusLine;

    if (dbScreen.hasField("StatusLine"))
    {
        mongo::BSONObj statuslineObj = dbScreen.getField("StatusLine").Obj();

        StatusLineType slType =
            (StatusLineType)statuslineObj.getField("Type").Int();
        StatusLineTextProgramType slAppearType =
            (StatusLineTextProgramType)statuslineObj.getField("AppearProgramType").Int();
        StatusLineTextProgramType slDisappearType =
            (StatusLineTextProgramType)statuslineObj.getField("DisappearProgramType").Int();
        uint32_t slStayVisibleTime = statuslineObj.getField("StayVisibleTime").Int();
        uint32_t slTimeBetweenMessages = statuslineObj.getField("TimeBetweenMessages").Int();
        uint16_t slTextConfId = statuslineObj.getField("TextsConfigurationId").Int();

        statusLine.type = slType;
        statusLine.appearProgramType = slAppearType;
        statusLine.disappearProgramType = slDisappearType;
        statusLine.stayVisibleTime = slStayVisibleTime;
        statusLine.timeBetweenMessages = slTimeBetweenMessages;
        statusLine.textsConfId = slTextConfId;
    }

    std::shared_ptr<ScreenDescription> screen (
        new ScreenDescription(
            screenId,
            screenType,
            label,
            jackpotId,
            index,
            stayVisibleTime,
            repeatSoundInterval,
            volumeLevel,
            statusLine));

    return screen;
}

bool
MongoPriorityScreens::isScreenExists
(const mongo::BSONObj& query) const
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

const std::string MongoPriorityScreens::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

} /* namespace database */
