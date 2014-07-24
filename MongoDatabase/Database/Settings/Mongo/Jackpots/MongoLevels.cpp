/*
 * MongoLevels.cpp
 *
 *  Created on: May 20, 2014
 *      Author: root
 */

#include "MongoLevels.h"

namespace database
{

MongoLevels::MongoLevels()
{
    // TODO Auto-generated constructor stub

}

MongoLevels::~MongoLevels()
{
    // TODO Auto-generated destructor stub
}

void MongoLevels::add(const std::shared_ptr<ProgressiveLevel> level) const
{
    if(level == nullptr)
    {
        throw utils::CommonException(
            "Unable to add progressive level. Invalid pointer");
    }

    try
    {
        mongo::BSONObj dbLevel = this->serialize(level);

        MongoDriver::getInstance().
                getConnection().insert(COLLECTION_NAME, dbLevel);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException("Unable to insert machine");
    }
}

std::shared_ptr<ProgressiveLevel>
MongoLevels::get(const uint32_t internalId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbLevel =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ProgressiveLevel> level = this->unserialize(dbLevel);

        return level;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get progressive level.", e).c_str());
    }
}

std::shared_ptr<ProgressiveLevel>
MongoLevels::get(const std::string &objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    try
    {
        const mongo::BSONObj dbLevel =
            MongoDriver::getInstance().getConnection().
            findOne(COLLECTION_NAME, query);

        std::shared_ptr<ProgressiveLevel> level = this->unserialize(dbLevel);

        return level;

    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get progressive level.", e).c_str());
    }
}

void MongoLevels::update(
        const uint32_t internalId,
        const std::shared_ptr<ProgressiveLevel> updatedLevel) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedLevel == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid progressive level pointer");
    }

    if(!this->isLevelExists(query))
    {
        throw utils::CommonException(
            "Unable to update. Progressive level doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbLevel = this->serialize(updatedLevel);

        MongoDriver::getInstance().getConnection().
            update(COLLECTION_NAME, query, updatedDbLevel);
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update progressive level", e).c_str());
    }
}

void MongoLevels::update(
        const std::string& objectId,
        const std::shared_ptr<ProgressiveLevel> updatedLevel) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));

    mongo::BSONObj query = queryBuilder.obj();

    if(updatedLevel == nullptr)
    {
        throw utils::CommonException(
            "Unable to update. Invalid progressive pointer");
    }

    if(!this->isLevelExists(query))
    {
        throw utils::CommonException(
            "Unable to update. Progressive level doesn't exists");
    }

    try
    {
        mongo::BSONObj updatedDbLevel = this->serialize(updatedLevel);

        MongoDriver::getInstance().getConnection().
                update(COLLECTION_NAME, query, updatedDbLevel);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to update progressive level", e).c_str());
    }
}

void MongoLevels::remove(const uint32_t internalId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("InternalId", internalId);
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isLevelExists(query))
    {
        throw utils::CommonException(
                "Unable to remove. Progressive level doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
            remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove progressive level", e).c_str());
    }
}

void MongoLevels::remove(const std::string& objectId) const
{
    mongo::BSONObjBuilder queryBuilder;
    queryBuilder.append("_id", mongo::OID(objectId));
    mongo::BSONObj query = queryBuilder.obj();

    if(!this->isLevelExists(query))
    {
        throw utils::CommonException(
            "Unable to remove. Progressive level doesn't exists");
    }

    try
    {
        MongoDriver::getInstance().getConnection().
                remove(COLLECTION_NAME, query);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove progressive level", e).c_str());
    }
}

std::vector<std::shared_ptr<ProgressiveLevel>>
MongoLevels::getAll() const
{
    std::vector<std::shared_ptr<ProgressiveLevel>> levelsList;

    try
    {
        std::shared_ptr<mongo::DBClientCursor> cursor =
            MongoDriver::getInstance().getConnection().
            query(COLLECTION_NAME, mongo::Query());

        while(cursor->more())
        {
            mongo::BSONObj dbLevel = cursor->next();
            std::shared_ptr<ProgressiveLevel> level = this->unserialize(dbLevel);

            levelsList.push_back(level);
        }

        return levelsList;
    }
    catch(mongo::DBException& e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to get all levels", e).c_str());
    }
}

void MongoLevels::removeAll() const
{
    try
    {
        MongoDriver::getInstance().getConnection().
            dropCollection(COLLECTION_NAME);
    }
    catch(mongo::DBException &e)
    {
        throw utils::CommonException(
            this->buildErrorMessage("Unable to remove all levels", e).c_str());
    }
}

mongo::BSONObj
MongoLevels::serialize(const std::shared_ptr<ProgressiveLevel> level) const
{

    mongo::BSONObjBuilder levelBuilder;

    levelBuilder.append("LevelType", level->getType() );
    levelBuilder.append("InternalId", level->getInternalId() );
    levelBuilder.append("ExternalId", level->getExternalId() );
    levelBuilder.append("SessionId", level->getSessionId() );
    levelBuilder.append("DenomIndex", level->getDenomIndex() );

    levelBuilder.append("ApplyNextSettings", level->getApplyNextSettings() );
    levelBuilder.append("Status", level->getStatus() );
    levelBuilder.append("BaseValue", (int64_t)level->getBaseValue() );
    levelBuilder.append("VisibleValue", (int64_t)level->getVisibleValue() );
    levelBuilder.append("VisibleLimitValue", (int64_t)level->getVisibleLimitValue() );
    levelBuilder.append("VisiblePercentage", (int64_t)level->getVisiblePercentage() );
    levelBuilder.append("UseVisibleMiddleValue", level->getUseVisibleMiddleValue() );
    levelBuilder.append("VisibleMiddleValue", (int64_t)level->getVisibleMiddleValue() );
    levelBuilder.append("VisibleMiddlePercentage", (int64_t)level->getVisibleMiddlePercentage() );

    levelBuilder.append("HiddenValue", (int64_t)level->getHiddenValue() );
    levelBuilder.append("HiddenPercentage", (int64_t)level->getHiddenPercentage() );
    levelBuilder.append("HiddenValueAdd", (int64_t)level->getHiddenValueAdd() );
    levelBuilder.append("TotalHiddenAddition", (int64_t)level->getTotalHiddenAddition() );

    levelBuilder.append("AutomaticOverflow", level->getAutomaticOverflow() );
    levelBuilder.append("OverflowValue", (int64_t)level->getOverflowValue() );
    levelBuilder.append("OverflowPercentage", (int64_t)level->getOverflowPercentage() );

    levelBuilder.append("ReserveValue", (int64_t)level->getReserveValue() );
    levelBuilder.append("ReserveLimitValue", (int64_t)level->getReserveLimitValue() );
    levelBuilder.append("ReservePercentage", (int64_t)level->getReservePercentage() );

    levelBuilder.append("MinBaseValue", (int64_t)level->getMinBaseValue() );
    levelBuilder.append("MaxBaseValue", (int64_t)level->getMaxBaseValue() );

    levelBuilder.append("HitMinTriggerValue", (int64_t)level->getHitMinTriggerValue() );
    levelBuilder.append("HitMaxTriggerValue", (int64_t)level->getHitMaxTriggerValue() );
    levelBuilder.append("HitTriggerValue", (int64_t)level->getHitTriggerValue() );

    levelBuilder.append("HitMinBetAmount", (int64_t)level->getHitMinBetAmount() );
    levelBuilder.append("HitMaxBetAmount", (int64_t)level->getHitMaxBetAmount() );
    levelBuilder.append("HitBetAmount", (int64_t)level->getHitBetAmount() );

    levelBuilder.append("HitMinPlayedGames", level->getHitMinPlayedGames() );
    levelBuilder.append("HitMaxPlayedGames", level->getHitMaxPlayedGames() );
    levelBuilder.append("HitPlayedGames", level->getHitPlayedGames() );

    levelBuilder.append("HitStartTime", level->getHitStartTime() );
    levelBuilder.append("HitEndTime", level->getHitEndTime() );
    levelBuilder.append("HitTime", level->getHitTime() );

    levelBuilder.append("HitWeekDays", level->getHitWeekDays() );
    levelBuilder.append("HitMonths", level->getHitMonths() );

    levelBuilder.append("HitMinDeductionAmount", (int64_t)level->getHitMinDeductionAmount() );
    levelBuilder.append("HitMaxDeductionAmount", (int64_t)level->getHitMaxDeductionAmount() );
    levelBuilder.append("HitDeductionAmount", (int64_t)level->getHitDeductionAmount() );

    levelBuilder.append("MinBetToWin", (int64_t)level->getMinBetToWin() );

    levelBuilder.append("ActiveStartTime", level->getActiveStartTime() );
    levelBuilder.append("ActiveEndTime", level->getActiveEndTime() );
    levelBuilder.append("ActiveWeekDays", level->getActiveWeekDays() );
    levelBuilder.append("ActiveMonths", level->getActiveMonths() );

    levelBuilder.append("MinMachinesNumber", level->getMinMachinesNumber() );
    levelBuilder.append("MinMachinesPeriod", level->getMinMachinesPeriod() );
    levelBuilder.append("MaxNumberOfHits", level->getMaxNumberOfHits() );
    levelBuilder.append("MinActiveBet", (int64_t)level->getMinActiveBet() );
    levelBuilder.append("MaxActiveBet", (int64_t)level->getMaxActiveBet() );

    levelBuilder.append("NextStatus", level->getNextStatus() );
    levelBuilder.append("NextBaseValue", (int64_t)level->getNextBaseValue() );
    levelBuilder.append("NextVisibleValue", (int64_t)level->getNextVisibleValue() );
    levelBuilder.append("NextVisibleLimitValue", (int64_t)level->getNextVisibleLimitValue() );
    levelBuilder.append("NextVisiblePercentage", (int64_t)level->getNextVisiblePercentage() );
    levelBuilder.append("NextUseVisibleMiddleValue", level->getNextUseVisibleMiddleValue() );
    levelBuilder.append("NextVisibleMiddleValue", (int64_t)level->getNextVisibleMiddleValue() );
    levelBuilder.append("NextVisibleMiddlePercentage", (int64_t)level->getNextVisibleMiddlePercentage() );

    levelBuilder.append("NextHiddenValue", (int64_t)level->getNextHiddenValue() );
    levelBuilder.append("NextHiddenPercentage", (int64_t)level->getNextHiddenPercentage() );
    levelBuilder.append("NextHiddenValueAdd", (int64_t)level->getNextHiddenValueAdd() );

    levelBuilder.append("NextOverflowValue", (int64_t)level->getNextOverflowValue() );
    levelBuilder.append("NextOverflowPercentage", (int64_t)level->getNextOverflowPercentage() );

    levelBuilder.append("NextReserveValue", (int64_t)level->getNextReserveValue() );
    levelBuilder.append("NextReserveLimitValue", (int64_t)level->getNextReserveLimitValue() );
    levelBuilder.append("NextReservePercentage", (int64_t)level->getNextReservePercentage() );

    levelBuilder.append("NextMinBaseValue", (int64_t)level->getNextMinBaseValue() );
    levelBuilder.append("NextMaxBaseValue", (int64_t)level->getNextMaxBaseValue() );

    levelBuilder.append("NextHitMinTriggerValue", (int64_t)level->getNextHitMinTriggerValue() );
    levelBuilder.append("NextHitMaxTriggerValue", (int64_t)level->getNextHitMaxTriggerValue() );

    levelBuilder.append("NextHitMinBetAmount", (int64_t)level->getNextHitMinBetAmount() );
    levelBuilder.append("NextHitMaxBetAmount", (int64_t)level->getNextHitMaxBetAmount() );

    levelBuilder.append("NextHitMinPlayedGames", level->getNextHitMinPlayedGames() );
    levelBuilder.append("NextHitMaxPlayedGames", level->getNextHitMaxPlayedGames() );

    levelBuilder.append("NextHitStartTime", level->getNextHitStartTime() );
    levelBuilder.append("NextHitEndTime", level->getNextHitEndTime() );
    levelBuilder.append("NextHitWeekDays", level->getNextHitWeekDays() );
    levelBuilder.append("NextHitMonths", level->getNextHitMonths() );

    levelBuilder.append("NextHitMinDeductionAmount", (int64_t)level->getNextHitMinDeductionAmount() );
    levelBuilder.append("NextHitMaxDeductionAmount", (int64_t)level->getNextHitMaxDeductionAmount() );

    levelBuilder.append("NextMinBetToWin", (int64_t)level->getNextMinBetToWin() );
    levelBuilder.append("NextActiveStartTime", level->getNextActiveStartTime() );
    levelBuilder.append("NextActiveEndTime", level->getNextActiveEndTime() );
    levelBuilder.append("NextActiveWeekDays", level->getNextActiveWeekDays() );
    levelBuilder.append("NextActiveMonths", level->getNextActiveMonths() );

    levelBuilder.append("NextMinMachinesNumber", level->getNextMinMachinesNumber() );
    levelBuilder.append("NextMinMachinesPeriod", level->getNextMinMachinesPeriod() );
    levelBuilder.append("NextMaxNumberOfHits", level->getNextMaxNumberOfHits() );

    levelBuilder.append("NextMinActiveBet", (int64_t)level->getNextMinActiveBet() );
    levelBuilder.append("NextMaxActiveBet", (int64_t)level->getNextMaxActiveBet() );

    levelBuilder.append("LastActivationTime", level->getLastActivationTime() );
    levelBuilder.append("LastDeactivationTime", level->getLastDeactivationTime() );
    levelBuilder.append("LastChangeTime", level->getLastChangeTime() );
    levelBuilder.append("TimesWon", level->getTimesWon() );
    levelBuilder.append("TotalWon", (int64_t)level->getTotalWon() );
    levelBuilder.append("TotalDeduction", (int64_t)level->getTotalDeduction() );
    levelBuilder.append("PartialDeduction", (int64_t)level->getPartialDeduction() );
    levelBuilder.append("TotalBetsNumber", level->getTotalBetsNumber() );
    levelBuilder.append("PartialBetsNumber", level->getPartialBetsNumber() );
    levelBuilder.append("TotalBet", (int64_t)level->getTotalBet() );
    levelBuilder.append("PartialBet", level->getPartialBet() );
    levelBuilder.append("MinWin", (int64_t)level->getMinWin() );
    levelBuilder.append("MaxWin", (int64_t)level->getMaxWin() );

    levelBuilder.append("Locked", level->isLocked() );
    levelBuilder.append("OnFocus", level->isOnFocus() );

    return levelBuilder.obj();
}

std::shared_ptr<ProgressiveLevel>
MongoLevels::unserialize(const mongo::BSONObj dbLevel) const
{
    LevelType type = (LevelType)dbLevel.getField("LevelType").Int();
    uint32_t internalId = dbLevel.getField("InternalId").Int();
    uint32_t externalId = dbLevel.getField("ExternalId").Int();
    uint32_t sessionId = dbLevel.getField("SessionId").Int();
    uint16_t denomIndex = dbLevel.getField("DenomIndex").Int();

    bool applyNextSettings = dbLevel.getField("ApplyNextSettings").Bool();
    LevelStatus status = (LevelStatus)dbLevel.getField("Status").Int();
    int64_t baseValue = dbLevel.getField("BaseValue").Long();
    int64_t visibleValue = dbLevel.getField("VisibleValue").Long();
    int64_t visibleLimitValue = dbLevel.getField("VisibleLimitValue").Long();
    int64_t visiblePercentage = dbLevel.getField("VisiblePercentage").Long();
    int64_t useVisibleMiddleValue = dbLevel.getField("UseVisibleMiddleValue").Int();
    int64_t visibleMiddleValue = dbLevel.getField("VisibleMiddleValue").Long();
    int64_t visibleMiddlePercentage = dbLevel.getField("VisibleMiddlePercentage").Long();

    int64_t hiddenValue = dbLevel.getField("HiddenValue").Long();
    int64_t hiddenPercentage = dbLevel.getField("HiddenPercentage").Long();
    int64_t hiddenValueAdd = dbLevel.getField("HiddenValueAdd").Long();
    int64_t totalHiddenAddition = dbLevel.getField("TotalHiddenAddition").Long();

    bool automaticOverflow = dbLevel.getField("AutomaticOverflow").Bool();
    int64_t overflowValue = dbLevel.getField("OverflowValue").Long();
    int64_t overflowPercentage = dbLevel.getField("OverflowPercentage").Long();

    int64_t reserveValue = dbLevel.getField("ReserveValue").Long();
    int64_t reserveLimitValue = dbLevel.getField("ReserveLimitValue").Long();
    int64_t reservePercentage = dbLevel.getField("ReservePercentage").Long();

    int64_t minBaseValue = dbLevel.getField("MinBaseValue").Long();
    int64_t maxBaseValue = dbLevel.getField("MaxBaseValue").Long();

    int64_t hitMinTriggerValue = dbLevel.getField("HitMinTriggerValue").Long();
    int64_t hitMaxTriggerValue = dbLevel.getField("HitMaxTriggerValue").Long();
    int64_t hitTriggerValue = dbLevel.getField("HitTriggerValue").Long();

    int64_t hitMinBetAmount = dbLevel.getField("HitMinBetAmount").Long();
    int64_t hitMaxBetAmount = dbLevel.getField("HitMaxBetAmount").Long();
    int64_t hitBetAmount = dbLevel.getField("HitBetAmount").Long();

    uint32_t hitMinPlayedGames = dbLevel.getField("HitMinPlayedGames").Int();
    uint32_t hitMaxPlayedGames = dbLevel.getField("HitMaxPlayedGames").Int();
    uint32_t hitPlayedGames = dbLevel.getField("HitPlayedGames").Int();

    uint32_t hitStartTime = dbLevel.getField("HitStartTime").Int();
    uint32_t hitEndTime = dbLevel.getField("HitEndTime").Int();
    uint32_t hitTime = dbLevel.getField("HitTime").Int();
    uint8_t hitWeekDays = dbLevel.getField("HitWeekDays").Int();
    uint16_t hitMonths = dbLevel.getField("HitMonths").Int();

    int64_t hitMinDeductionAmount = dbLevel.getField("HitMinDeductionAmount").Long();
    int64_t hitMaxDeductionAmount = dbLevel.getField("HitMaxDeductionAmount").Long();
    int64_t hitDeductionAmount = dbLevel.getField("HitDeductionAmount").Long();

    int64_t minBetToWin = dbLevel.getField("MinBetToWin").Long();
    uint32_t activeStartTime = dbLevel.getField("ActiveStartTime").Int();
    uint32_t activeEndTime = dbLevel.getField("ActiveEndTime").Int();
    uint8_t activeWeekDays = dbLevel.getField("ActiveWeekDays").Int();
    uint16_t activeMonths = dbLevel.getField("ActiveMonths").Int();

    uint16_t minMachinesNumber = dbLevel.getField("MinMachinesNumber").Int();
    uint16_t minMachinesPeriod = dbLevel.getField("MinMachinesPeriod").Int();
    uint16_t maxNumberOfHits = dbLevel.getField("MaxNumberOfHits").Int();

    int64_t minActiveBet = dbLevel.getField("MinActiveBet").Long();
    int64_t maxActiveBet = dbLevel.getField("MaxActiveBet").Long();

    LevelStatus nextStatus = (LevelStatus)dbLevel.getField("NextStatus").Int();
    int64_t nextBaseValue = dbLevel.getField("NextBaseValue").Long();
    int64_t nextVisibleValue = dbLevel.getField("NextVisibleValue").Long();
    int64_t nextVisibleLimitValue = dbLevel.getField("NextVisibleLimitValue").Long();
    int64_t nextVisiblePercentage = dbLevel.getField("NextVisiblePercentage").Long();

    uint8_t nextUseVisibleMiddleValue = dbLevel.getField("NextUseVisibleMiddleValue").Int();
    int64_t nextVisibleMiddleValue = dbLevel.getField("NextVisibleMiddleValue").Long();
    int64_t nextVisibleMiddlePercentage = dbLevel.getField("NextVisibleMiddlePercentage").Long();

    int64_t nextHiddenValue = dbLevel.getField("NextHiddenValue").Long();
    int64_t nextHiddenPercentage = dbLevel.getField("NextHiddenPercentage").Long();
    int64_t nextHiddenValueAdd = dbLevel.getField("NextHiddenValueAdd").Long();

    int64_t nextOverflowValue = dbLevel.getField("NextOverflowValue").Long();
    int64_t nextOverflowPercentage = dbLevel.getField("NextOverflowPercentage").Long();

    int64_t nextReserveValue = dbLevel.getField("NextReserveValue").Long();
    int64_t nextReserveLimitValue = dbLevel.getField("NextReserveLimitValue").Long();
    int64_t nextReservePercentage = dbLevel.getField("NextReservePercentage").Long();

    int64_t nextMinBaseValue = dbLevel.getField("NextMinBaseValue").Long();
    int64_t nextMaxBaseValue = dbLevel.getField("NextMaxBaseValue").Long();

    int64_t nextHitMinTriggerValue = dbLevel.getField("NextHitMinTriggerValue").Long();
    int64_t nextHitMaxTriggerValue = dbLevel.getField("NextHitMaxTriggerValue").Long();

    int64_t nextHitMinBetAmount = dbLevel.getField("NextHitMinBetAmount").Long();
    int64_t nextHitMaxBetAmount = dbLevel.getField("NextHitMaxBetAmount").Long();

    uint32_t nextHitMinPlayedGames = dbLevel.getField("NextHitMinPlayedGames").Int();
    uint32_t nextHitMaxPlayedGames = dbLevel.getField("NextHitMaxPlayedGames").Int();

    uint32_t nextHitStartTime = dbLevel.getField("NextHitStartTime").Int();
    uint32_t nextHitEndTime = dbLevel.getField("NextHitEndTime").Int();
    uint8_t nextHitWeekDays = dbLevel.getField("NextHitWeekDays").Int();
    uint16_t nextHitMonths = dbLevel.getField("NextHitMonths").Int();

    int64_t nextHitMinDeductionAmount = dbLevel.getField("NextHitMinDeductionAmount").Long();
    int64_t nextHitMaxDeductionAmount = dbLevel.getField("NextHitMaxDeductionAmount").Long();
    int64_t nextMinBetToWin = dbLevel.getField("NextMinBetToWin").Long();

    uint32_t nextActiveStartTime = dbLevel.getField("NextActiveStartTime").Int();
    uint32_t nextActiveEndTime = dbLevel.getField("NextActiveEndTime").Int();
    uint8_t nextActiveWeekDays = dbLevel.getField("NextActiveWeekDays").Int();
    uint16_t nextActiveMonths = dbLevel.getField("NextActiveMonths").Int();

    uint16_t nextMinMachinesNumber = dbLevel.getField("NextMinMachinesNumber").Int();
    uint16_t nextMinMachinesPeriod = dbLevel.getField("NextMinMachinesPeriod").Int();
    uint16_t nextMaxNumberOfHits = dbLevel.getField("NextMaxNumberOfHits").Int();

    int64_t nextMinActiveBet = dbLevel.getField("NextMinActiveBet").Long();
    int64_t nextMaxActiveBet = dbLevel.getField("NextMaxActiveBet").Long();

    uint32_t lastActivationTime = dbLevel.getField("LastActivationTime").Int();
    uint32_t lastDeactivationTime = dbLevel.getField("LastDeactivationTime").Int();
    uint32_t lastChangeTime = dbLevel.getField("LastChangeTime").Int();
    uint32_t timesWon = dbLevel.getField("TimesWon").Int();
    uint64_t totalWon = dbLevel.getField("TotalWon").Long();
    int64_t totalDeduction = dbLevel.getField("TotalDeduction").Long();
    int64_t partialDeduction = dbLevel.getField("PartialDeduction").Long();
    uint32_t totalBetsNumber = dbLevel.getField("TotalBetsNumber").Int();
    uint32_t partialBetsNumber = dbLevel.getField("PartialBetsNumber").Int();
    uint64_t totalBet = dbLevel.getField("TotalBet").Long();
    uint32_t partialBet = dbLevel.getField("PartialBet").Int();
    int64_t minWin = dbLevel.getField("MinWin").Long();
    int64_t maxWin = dbLevel.getField("MaxWin").Long();

    bool isLocked = dbLevel.getField("Locked").Bool();
    bool isOnFocus = dbLevel.getField("OnFocus").Bool();

    std::shared_ptr<ProgressiveLevel> level(new ProgressiveLevel(
            type,
            internalId,
            externalId,
            sessionId,
            denomIndex));

    level->setApplyNextSettings(applyNextSettings);
    level->setStatus(status);
    level->setBaseValue(baseValue);
    level->setVisibleValue(visibleValue);
    level->setVisibleLimitValue(visibleLimitValue);
    level->setVisiblePercentage(visiblePercentage);

    level->setUseVisibleMiddleValue(useVisibleMiddleValue);
    level->setVisibleMiddleValue(visibleMiddleValue);
    level->setVisibleMiddlePercentage(visibleMiddlePercentage);

    level->setHiddenValue(hiddenValue);
    level->setHiddenPercentage(hiddenPercentage);
    level->setHiddenValueAdd(hiddenValueAdd);

    level->setAutomaticOverflow(automaticOverflow);
    level->setOverflowValue(overflowValue);
    level->setOverflowPercentage(overflowPercentage);

    level->setReserveValue(reserveValue);
    level->setReserveLimitValue(reserveLimitValue);
    level->setReservePercentage(reservePercentage);

    level->setMinBaseValue(minBaseValue);
    level->setMaxBaseValue(maxBaseValue);

    level->setHitMinTriggerValue(hitMinTriggerValue);
    level->setHitMaxTriggerValue(hitMaxTriggerValue);
    level->setHitTriggerValue(hitTriggerValue);

    level->setHitMinBetAmount(hitMinBetAmount);
    level->setHitMaxBetAmount(hitMaxBetAmount);
    level->setHitBetAmount(hitBetAmount);

    level->setHitMinPlayedGames(hitMinPlayedGames);
    level->setHitMaxPlayedGames(hitMaxPlayedGames);
    level->setHitPlayedGames(hitPlayedGames);

    level->setHitStartTime(hitStartTime);
    level->setHitEndTime(hitEndTime);
    level->setHitTime(hitTime);
    level->setHitWeekDays(hitWeekDays);
    level->setHitMonths(hitMonths);

    level->setHitMinDeductionAmount(hitMinDeductionAmount);
    level->setHitMaxDeductionAmount(hitMaxDeductionAmount);
    level->setHitDeductionAmount(hitDeductionAmount);

    level->setMinBetToWin(minBetToWin);
    level->setActiveStartTime(activeStartTime);
    level->setActiveEndTime(activeEndTime);
    level->setActiveWeekDays(activeWeekDays);
    level->setActiveMonths(activeMonths);

    level->setMinMachinesNumber(minMachinesNumber);
    level->setMinMachinesPeriod(minMachinesPeriod);
    level->setMaxNumberOfHits(maxNumberOfHits);
    level->setMinActiveBet(minActiveBet);
    level->setMaxActiveBet(maxActiveBet);

    level->setNextStatus(nextStatus);
    level->setNextBaseValue(nextBaseValue);
    level->setNextVisibleValue(nextVisibleValue);
    level->setNextVisibleLimitValue(nextVisibleLimitValue);
    level->setNextVisiblePercentage(nextVisiblePercentage);

    level->setNextUseVisibleMiddleValue(nextUseVisibleMiddleValue);
    level->setNextVisibleMiddleValue(nextVisibleMiddleValue);
    level->setNextVisibleMiddlePercentage(nextVisibleMiddlePercentage);

    level->setNextHiddenValue(nextHiddenValue);
    level->setNextHiddenPercentage(nextHiddenPercentage);
    level->setNextHiddenValueAdd(nextHiddenValueAdd);

    level->setNextOverflowValue(nextOverflowValue);
    level->setNextOverflowPercentage(nextOverflowPercentage);

    level->setNextReserveValue(nextReserveValue);
    level->setNextReserveLimitValue(nextReserveLimitValue);
    level->setNextReservePercentage(nextReservePercentage);

    level->setNextMinBaseValue(nextMinBaseValue);
    level->setNextMaxBaseValue(nextMaxBaseValue);

    level->setNextHitMinTriggerValue(nextHitMinTriggerValue);
    level->setNextHitMaxTriggerValue(nextHitMaxTriggerValue);

    level->setNextHitMinBetAmount(nextHitMinBetAmount);
    level->setNextHitMaxBetAmount(nextHitMaxBetAmount);

    level->setNextHitMinPlayedGames(nextHitMinPlayedGames);
    level->setNextHitMaxPlayedGames(nextHitMaxPlayedGames);

    level->setNextHitStartTime(nextHitStartTime);
    level->setNextHitEndTime(nextHitEndTime);
    level->setNextHitWeekDays(nextHitWeekDays);
    level->setNextHitMonths(nextHitMonths);

    level->setNextHitMinDeductionAmount(nextHitMinDeductionAmount);
    level->setNextHitMaxDeductionAmount(nextHitMaxDeductionAmount);

    level->setNextMinBetToWin(nextMinBetToWin);
    level->setNextActiveStartTime(nextActiveStartTime);
    level->setNextActiveEndTime(nextActiveEndTime);
    level->setNextActiveWeekDays(nextActiveWeekDays);
    level->setNextActiveMonths(nextActiveMonths);

    level->setNextMinMachinesNumber(nextMinMachinesNumber);
    level->setNextMinMachinesPeriod(nextMinMachinesPeriod);
    level->setNextMaxNumberOfHits(nextMaxNumberOfHits);
    level->setNextMinActiveBet(nextMinActiveBet);
    level->setNextMaxActiveBet(nextMaxActiveBet);

    level->setLastActivationTime(lastActivationTime);
    level->setLastDeactivationTime(lastDeactivationTime);
    level->setLastChangeTime(lastChangeTime);
    level->setTimesWon(timesWon);
    level->setTotalWon(totalWon);
    level->setTotalDeduction(totalDeduction);
    level->setPartialDeduction(partialDeduction);
    level->setTotalBetsNumber(totalBetsNumber);
    level->setPartialBetsNumber(partialBetsNumber);
    level->setTotalBet(totalBet);
    level->setPartialBet(partialBet);
    level->setMinWin(minWin);
    level->setMaxWin(maxWin);
    level->setTotalHiddenAddition(totalHiddenAddition);
    level->setLocked(isLocked);
    level->setOnFocus(isOnFocus);

    return level;
}

bool MongoLevels::isLevelExists(const mongo::BSONObj& query) const
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

const std::string MongoLevels::buildErrorMessage(
                        const std::string& message,
                        const mongo::DBException &exc) const
{
    std::string excMessage( exc.what() );
    std::string final(message + excMessage);

    return final;
}

}//database

