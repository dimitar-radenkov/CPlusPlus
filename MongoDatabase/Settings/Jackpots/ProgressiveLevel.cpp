/*
 * ProgressiveLevel.cpp
 *
 *  Created on: May 16, 2014
 *      Author: root
 */

#include "ProgressiveLevel.h"

ProgressiveLevel::ProgressiveLevel():
    type(LevelType::UnknownLevel),
    internalId (0),
    externalId (0),
    sessionId (0),
    denomIndex (0),
    applyNextSettings (false),
    status (LevelStatus::NotSet),
    baseValue (0),
    visibleValue (0),
    visibleLimitValue (0),
    visibleDeductionPercentage (0),
    useVisibleMiddleValue(0),
    visibleMiddleValue(0),
    visibleMiddlePercentage(0),
    hiddenValue (0),
    hiddenDeductionPercentage (0),
    hiddenValueAdd (0),
    automaticOverflow(false),
    overflowValue (0),
    overflowDeductionPercentage (0),
    reserveValue (0),
    reserveLimitValue (0),
    reserveDeductionPercentage (0),
    minBaseValue (0),
    maxBaseValue (0),
    hitMinTriggerValue (0),
    hitMaxTriggerValue (0),
    hitTriggerValue (0),
    hitMinBetAmount (0),
    hitMaxBetAmount (0),
    hitBetAmount (0),
    hitMinPlayedGames (0),
    hitMaxPlayedGames (0),
    hitPlayedGames (0),
    hitStartTime (0),
    hitEndTime (0),
    hitTime (0),
    hitWeekDays (0),
    hitMonths (0),
    hitMinDeductionAmount (0),
    hitMaxDeductionAmount (0),
    hitDeductionAmount (0),
    minBetToWin (0),
    activeStartTime (0),
    activeEndTime (0),
    activeWeekDays (0),
    activeMonths (0),
    minMachinesNumber (0),
    minMachinesPeriod (0),
    maxNumberOfHits (0),
    minActiveBet (0),
    maxActiveBet (0),
    nextStatus (LevelStatus::NotSet),
    nextBaseValue (0),
    nextVisibleValue (0),
    nextVisibleLimitValue (0),
    nextVisibleDeductionPercentage (0),
    nextUseVisibleMiddleValue(0),
    nextVisibleMiddleValue(0),
    nextVisibleMiddlePercentage(0),
    nextHiddenValue (0),
    nextHiddenDeductionPercentage (0),
    nextHiddenValueAdd (0),
    nextOverflowValue (0),
    nextOverflowDeductionPercentage (0),
    nextReserveValue (0),
    nextReserveLimitValue (0),
    nextReserveDeductionPercentage (0),
    nextMinBaseValue (0),
    nextMaxBaseValue (0),
    nextHitMinTriggerValue (0),
    nextHitMaxTriggerValue (0),
    nextHitMinBetAmount (0),
    nextHitMaxBetAmount (0),
    nextHitMinPlayedGames (0),
    nextHitMaxPlayedGames (0),
    nextHitStartTime (0),
    nextHitEndTime (0),
    nextHitWeekDays (0),
    nextHitMonths (0),
    nextHitMinDeductionAmount (0),
    nextHitMaxDeductionAmount (0),
    nextMinBetToWin (0),
    nextActiveStartTime (0),
    nextActiveEndTime (0),
    nextActiveWeekDays (0),
    nextActiveMonths (0),
    nextMinMachinesNumber (0),
    nextMinMachinesPeriod (0),
    nextMaxNumberOfHits (0),
    nextMinActiveBet (0),
    nextMaxActiveBet (0),
    lastActivationTime (0),
    lastDeactivationTime (0),
    lastChangeTime (0),
    timesWon (0),
    totalWon (0),
    totalDeduction (0),
    partialDeduction (0),
    totalBetsNumber (0),
    partialBetsNumber (0),
    totalBet (0),
    partialBet (0),
    minWin(0),
    maxWin(0),
    totalHiddentAddition(0),
    locked (false),
    onFocus (false)
{
}

ProgressiveLevel::ProgressiveLevel(const LevelType type,
                                   const uint32_t internalId,
                                   const uint32_t externalId,
                                   const uint32_t sessionId,
                                   const int16_t denomIndex):
    type (type),
    internalId (internalId),
    externalId (externalId),
    sessionId (sessionId),
    denomIndex (denomIndex),
    applyNextSettings (false),
    status (LevelStatus::NotSet),
    baseValue (0),
    visibleValue (0),
    visibleLimitValue (0),
    visibleDeductionPercentage (0),
    useVisibleMiddleValue(0),
    visibleMiddleValue(0),
    visibleMiddlePercentage(0),
    hiddenValue (0),
    hiddenDeductionPercentage (0),
    hiddenValueAdd (0),
    automaticOverflow(false),
    overflowValue (0),
    overflowDeductionPercentage (0),
    reserveValue (0),
    reserveLimitValue (0),
    reserveDeductionPercentage (0),
    minBaseValue (0),
    maxBaseValue (0),
    hitMinTriggerValue (0),
    hitMaxTriggerValue (0),
    hitTriggerValue (0),
    hitMinBetAmount (0),
    hitMaxBetAmount (0),
    hitBetAmount (0),
    hitMinPlayedGames (0),
    hitMaxPlayedGames (0),
    hitPlayedGames (0),
    hitStartTime (0),
    hitEndTime (0),
    hitTime (0),
    hitWeekDays (0),
    hitMonths (0),
    hitMinDeductionAmount (0),
    hitMaxDeductionAmount (0),
    hitDeductionAmount (0),
    minBetToWin (0),
    activeStartTime (0),
    activeEndTime (0),
    activeWeekDays (0),
    activeMonths (0),
    minMachinesNumber (0),
    minMachinesPeriod (0),
    maxNumberOfHits (0),
    minActiveBet (0),
    maxActiveBet (0),
    nextStatus (LevelStatus::NotSet),
    nextBaseValue (0),
    nextVisibleValue (0),
    nextVisibleLimitValue (0),
    nextVisibleDeductionPercentage (0),
    nextUseVisibleMiddleValue(0),
    nextVisibleMiddleValue(0),
    nextVisibleMiddlePercentage(0),
    nextHiddenValue (0),
    nextHiddenDeductionPercentage (0),
    nextHiddenValueAdd (0),
    nextOverflowValue (0),
    nextOverflowDeductionPercentage (0),
    nextReserveValue (0),
    nextReserveLimitValue (0),
    nextReserveDeductionPercentage (0),
    nextMinBaseValue (0),
    nextMaxBaseValue (0),
    nextHitMinTriggerValue (0),
    nextHitMaxTriggerValue (0),
    nextHitMinBetAmount (0),
    nextHitMaxBetAmount (0),
    nextHitMinPlayedGames (0),
    nextHitMaxPlayedGames (0),
    nextHitStartTime (0),
    nextHitEndTime (0),
    nextHitWeekDays (0),
    nextHitMonths (0),
    nextHitMinDeductionAmount (0),
    nextHitMaxDeductionAmount (0),
    nextMinBetToWin (0),
    nextActiveStartTime (0),
    nextActiveEndTime (0),
    nextActiveWeekDays (0),
    nextActiveMonths (0),
    nextMinMachinesNumber (0),
    nextMinMachinesPeriod (0),
    nextMaxNumberOfHits (0),
    nextMinActiveBet (0),
    nextMaxActiveBet (0),
    lastActivationTime(0),
    lastDeactivationTime(0),
    lastChangeTime(0),
    timesWon (0),
    totalWon (0),
    totalDeduction (0),
    partialDeduction (0),
    totalBetsNumber (0),
    partialBetsNumber (0),
    totalBet (0),
    partialBet (0),
    minWin(0),
    maxWin(0),
    totalHiddentAddition(0),
    locked (false),
    onFocus (false)
{
}

ProgressiveLevel::~ProgressiveLevel()
{
}

ProgressiveLevel & ProgressiveLevel::operator = (
                   const ProgressiveLevel & level)
{
    this->applyNextSettings = level.getApplyNextSettings();
    this->status = level.getStatus();
    this->baseValue = level.getBaseValue();
    this->visibleValue = level.getVisibleValue();
    this->visibleLimitValue = level.getVisibleLimitValue();
    this->visibleDeductionPercentage = level.getVisiblePercentage();
    this->useVisibleMiddleValue = level.getUseVisibleMiddleValue();
    this->visibleMiddleValue = level.getVisibleMiddleValue();
    this->visibleMiddlePercentage = level.getVisibleMiddlePercentage();
    this->hiddenValue = level.getHiddenValue();
    this->hiddenValueAdd = level.getHiddenValueAdd();
    this->hiddenDeductionPercentage = level.getHiddenPercentage();
    this->automaticOverflow = level.getAutomaticOverflow();
    this->overflowValue = level.getOverflowValue();
    this->overflowDeductionPercentage = level.getOverflowPercentage();
    this->reserveValue = level.getReserveValue();
    this->reserveLimitValue = level.getReserveLimitValue();
    this->reserveDeductionPercentage = level.getReservePercentage();

    this->minBaseValue = level.getMinBaseValue();
    this->maxBaseValue = level.getMaxBaseValue();
    this->hitMinTriggerValue = level.getHitMinTriggerValue();
    this->hitMaxTriggerValue = level.getHitMaxTriggerValue();
    this->hitTriggerValue = level.getHitTriggerValue();
    this->hitMinBetAmount = level.getHitMinBetAmount();
    this->hitMaxBetAmount = level.getHitMaxBetAmount();
    this->hitBetAmount = level.getHitBetAmount();
    this->hitMinPlayedGames = level.getHitMinPlayedGames();
    this->hitMaxPlayedGames = level.getHitMaxPlayedGames();
    this->hitPlayedGames = level.getHitPlayedGames();
    this->hitStartTime = level.getHitStartTime();
    this->hitEndTime = level.getHitEndTime();
    this->hitTime = level.getHitTime();
    this->hitWeekDays = level.getHitWeekDays();
    this->hitMonths = level.getHitMonths();
    this->hitMinDeductionAmount = level.getHitMinDeductionAmount();
    this->hitMaxDeductionAmount = level.getHitMaxDeductionAmount();
    this->hitDeductionAmount = level.getHitDeductionAmount();
    this->minBetToWin = level.getMinBetToWin();
    this->activeStartTime = level.getActiveStartTime();
    this->activeEndTime = level.getActiveEndTime();
    this->activeWeekDays = level.getActiveWeekDays();
    this->activeMonths = level.getActiveMonths();
    this->minMachinesNumber = level.getMinMachinesNumber();
    this->minMachinesPeriod = level.getMinMachinesPeriod();
    this->maxNumberOfHits = level.getMaxNumberOfHits();
    this->minActiveBet = level.getMinActiveBet();
    this->maxActiveBet = level.getMaxActiveBet();
    this->nextStatus = level.getNextStatus();
    this->nextBaseValue = level.getNextBaseValue();
    this->nextVisibleValue = level.getNextVisibleValue();
    this->nextVisibleLimitValue = level.getNextVisibleLimitValue();
    this->nextVisibleDeductionPercentage = level.getNextVisiblePercentage();
    this->nextUseVisibleMiddleValue = level.getNextUseVisibleMiddleValue();
    this->nextVisibleMiddleValue = level.getNextVisibleMiddleValue();
    this->nextVisibleMiddlePercentage = level.getNextVisibleMiddlePercentage();
    this->nextHiddenValue = level.getNextHiddenValue();
    this->nextHiddenDeductionPercentage = level.getNextHiddenPercentage();
    this->nextHiddenValueAdd = level.getNextHiddenValueAdd();
    this->nextOverflowValue = level.getNextOverflowValue();
    this->nextOverflowDeductionPercentage = level.getNextOverflowPercentage();
    this->nextReserveValue = level.getNextReserveValue();
    this->nextReserveLimitValue = level.getNextReserveLimitValue();
    this->nextReserveDeductionPercentage = level.getNextReservePercentage();

    this->nextMinBaseValue = level.getNextMinBaseValue();
    this->nextMaxBaseValue = level.getNextMaxBaseValue();
    this->nextHitMinTriggerValue = level.getNextHitMinTriggerValue();
    this->nextHitMaxTriggerValue = level.getNextHitMaxTriggerValue();
    this->nextHitMinBetAmount = level.getNextHitMinBetAmount();
    this->nextHitMaxBetAmount = level.getNextHitMaxBetAmount();
    this->nextHitMinPlayedGames = level.getNextHitMinPlayedGames();
    this->nextHitMaxPlayedGames = level.getNextHitMaxPlayedGames();
    this->nextHitStartTime = level.getNextHitStartTime();
    this->nextHitEndTime = level.getNextHitEndTime();
    this->nextHitWeekDays = level.getNextHitWeekDays();
    this->nextHitMonths = level.getNextHitMonths();
    this->nextHitMinDeductionAmount = level.getNextHitMinDeductionAmount();
    this->nextHitMaxDeductionAmount = level.getNextHitMaxDeductionAmount();
    this->nextMinBetToWin = level.getNextMinBetToWin();
    this->nextActiveStartTime = level.getNextActiveStartTime();
    this->nextActiveEndTime = level.getNextActiveEndTime();
    this->nextActiveWeekDays = level.getNextActiveWeekDays();
    this->nextActiveMonths = level.getNextActiveMonths();
    this->nextMinMachinesNumber = level.getNextMinMachinesNumber();
    this->nextMinMachinesPeriod = level.getNextMinMachinesPeriod();
    this->nextMaxNumberOfHits = level.getNextMaxNumberOfHits();
    this->nextMinActiveBet = level.getNextMinActiveBet();
    this->nextMaxActiveBet = level.getNextMaxActiveBet();

    this->lastActivationTime = level.getLastActivationTime();
    this->lastDeactivationTime = level.getLastDeactivationTime();
    this->lastChangeTime = level.getLastChangeTime();
    this->timesWon = level.getTimesWon();
    this->totalWon = level.getTotalWon();
    this->totalDeduction = level.getTotalDeduction();
    this->partialDeduction = level.getPartialDeduction();
    this->totalBetsNumber = level.getTotalBetsNumber();
    this->partialBetsNumber = level.getPartialBetsNumber();
    this->totalBet = level.getTotalBet();
    this->partialBet = level.getPartialBet();
    this->minWin = level.getMinWin();
    this->maxWin = level.getMaxWin();
    this->totalHiddentAddition = level.getTotalHiddenAddition();

    this->onFocus = level.isOnFocus();
    this->locked = level.isLocked();

    return *this;
}

const LevelType& ProgressiveLevel::getType() const
{
    return this->type;
}

void ProgressiveLevel::setInternalId(uint32_t internalId)
{
    this->internalId = internalId;
}

const uint32_t& ProgressiveLevel::getInternalId() const
{
    return this->internalId;
}

void ProgressiveLevel::setExternalId(uint32_t externalId)
{
    this->externalId = externalId;
}

const uint32_t& ProgressiveLevel::getExternalId() const
{
    return this->externalId;
}


void ProgressiveLevel::setSessionId(uint32_t sessionId)
{
    this->sessionId = sessionId;
}

const uint32_t& ProgressiveLevel::getSessionId() const
{
    return this->sessionId;
}

void ProgressiveLevel::setDenomIndex(int16_t denomIndex)
{
    this->denomIndex = denomIndex;
}

const int16_t& ProgressiveLevel::getDenomIndex() const
{
    return this->denomIndex;
}

void ProgressiveLevel::setApplyNextSettings(bool apply)
{
    this->applyNextSettings = apply;
}

const bool ProgressiveLevel::getApplyNextSettings() const
{
    return this->applyNextSettings;
}

void ProgressiveLevel::setStatus(const LevelStatus status)
{
    this->status = status;
}

const LevelStatus& ProgressiveLevel::getStatus() const
{
    return this->status;
}

void ProgressiveLevel::setBaseValue(const utils::Money& baseValue)
{
    this->baseValue = baseValue;
}

const utils::Money& ProgressiveLevel::getBaseValue() const
{
    return this->baseValue;
}

void ProgressiveLevel::setVisibleValue(const utils::Money& visibleValue)
{
    this->visibleValue = visibleValue;
}

const utils::Money& ProgressiveLevel::getVisibleValue() const
{
    return this->visibleValue;
}

void ProgressiveLevel::setVisibleLimitValue(
        const utils::Money& visibleLimitValue)
{
    this->visibleLimitValue = visibleLimitValue;
}

const utils::Money& ProgressiveLevel::getVisibleLimitValue() const
{
    return this->visibleLimitValue;
}

void ProgressiveLevel::setVisiblePercentage(
        const utils::Percent& visibleDeductionPercentage)
{
    this->visibleDeductionPercentage = visibleDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getVisiblePercentage() const
{
    return this->visibleDeductionPercentage;
}

void ProgressiveLevel::setUseVisibleMiddleValue(
        const uint8_t useVisibleMiddleValue)
{
    this->useVisibleMiddleValue = useVisibleMiddleValue;
}

const uint8_t& ProgressiveLevel::getUseVisibleMiddleValue() const
{
    return this->useVisibleMiddleValue;
}

void ProgressiveLevel::setVisibleMiddleValue(const utils::Money middleValue)
{
    this->visibleMiddleValue = middleValue;
}

const utils::Money& ProgressiveLevel::getVisibleMiddleValue() const
{
    return this->visibleMiddleValue;
}

void ProgressiveLevel::setVisibleMiddlePercentage(
        const utils::Percent& visibleMiddlePercentage)
{
    this->visibleMiddlePercentage = visibleMiddlePercentage;
}

const utils::Percent& ProgressiveLevel::getVisibleMiddlePercentage() const
{
    return this->visibleMiddlePercentage;
}

void ProgressiveLevel::setHiddenValue(const utils::Money& hiddenValue)
{
    this->hiddenValue = hiddenValue;
}

const utils::Money& ProgressiveLevel::getHiddenValue() const
{
    return this->hiddenValue;
}

void ProgressiveLevel::setHiddenPercentage(
        const utils::Percent& hiddenDeductionPercentage)
{
    this->hiddenDeductionPercentage = hiddenDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getHiddenPercentage() const
{
    return this->hiddenDeductionPercentage;
}


void ProgressiveLevel::setHiddenValueAdd(const utils::Money & hiddenValueAdd)
{
    this->hiddenValueAdd = hiddenValueAdd;
}


const utils::Money & ProgressiveLevel::getHiddenValueAdd() const
{
    return this->hiddenValueAdd;
}


void ProgressiveLevel::setAutomaticOverflow(bool automaticOverflow)
{
    this->automaticOverflow = automaticOverflow;
}

const bool ProgressiveLevel::getAutomaticOverflow() const
{
    return this->automaticOverflow;
}

void ProgressiveLevel::setOverflowValue(const utils::Money& overflowValue)
{
    this->overflowValue = overflowValue;
}

const utils::Money& ProgressiveLevel::getOverflowValue() const
{
    return this->overflowValue;
}

void ProgressiveLevel::setOverflowPercentage(
        const utils::Percent& overflowDeductionPercentage)
{
    this->overflowDeductionPercentage = overflowDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getOverflowPercentage() const
{
    return this->overflowDeductionPercentage;
}

void ProgressiveLevel::setReserveValue(const utils::Money& reserveValue)
{
    this->reserveValue = reserveValue;
}

const utils::Money& ProgressiveLevel::getReserveValue() const
{
    return this->reserveValue;
}

void ProgressiveLevel::setReserveLimitValue(
        const utils::Money& reserveLimitValue)
{
    this->reserveLimitValue = reserveLimitValue;
}

const utils::Money& ProgressiveLevel::getReserveLimitValue() const
{
    return this->reserveLimitValue;
}

void ProgressiveLevel::setReservePercentage(
        const utils::Percent& reserveDeductionPercentage)
{
    this->reserveDeductionPercentage = reserveDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getReservePercentage() const
{
    return this->reserveDeductionPercentage;
}

void ProgressiveLevel::setMinBaseValue(const utils::Money& minBaseValue)
{
    this->minBaseValue = minBaseValue;
}

const utils::Money& ProgressiveLevel::getMinBaseValue() const
{
    return this->minBaseValue;
}

void ProgressiveLevel::setMaxBaseValue(const utils::Money& maxBaseValue)
{
    this->maxBaseValue = maxBaseValue;
}

const utils::Money& ProgressiveLevel::getMaxBaseValue() const
{
    return this->maxBaseValue;
}

void ProgressiveLevel::setHitMinTriggerValue(
        const utils::Money& minTriggerValue)
{
    this->hitMinTriggerValue = minTriggerValue;
}

const utils::Money& ProgressiveLevel::getHitMinTriggerValue() const
{
    return this->hitMinTriggerValue;
}

void ProgressiveLevel::setHitMaxTriggerValue(
        const utils::Money& maxTriggerValue)
{
    this->hitMaxTriggerValue = maxTriggerValue;
}

void ProgressiveLevel::setHitTriggerValue(const utils::Money & minTriggerValue)
{
    this->hitTriggerValue = minTriggerValue;
}

const utils::Money & ProgressiveLevel::getHitTriggerValue() const
{
    return this->hitTriggerValue;
}

const utils::Money& ProgressiveLevel::getHitMaxTriggerValue() const
{
    return this->hitMaxTriggerValue;
}

void ProgressiveLevel::setHitMinBetAmount(const utils::Money& minBetAmount)
{
    this->hitMinBetAmount = minBetAmount;
}

const utils::Money& ProgressiveLevel::getHitMinBetAmount() const
{
    return this->hitMinBetAmount;
}

void ProgressiveLevel::setHitMaxBetAmount(const utils::Money& maxBetAmount)
{
    this->hitMaxBetAmount = maxBetAmount;
}

const utils::Money& ProgressiveLevel::getHitMaxBetAmount() const
{
    return this->hitMaxBetAmount;
}

void ProgressiveLevel::setHitBetAmount(const utils::Money& betAmount)
{
    this->hitBetAmount = betAmount;
}

const utils::Money& ProgressiveLevel::getHitBetAmount() const
{
    return this->hitBetAmount;
}

void ProgressiveLevel::setHitMinPlayedGames(const uint32_t hitMinPlayedGames)
{
    this->hitMinPlayedGames = hitMinPlayedGames;
}

const uint32_t& ProgressiveLevel::getHitMinPlayedGames() const
{
    return this->hitMinPlayedGames;
}

void ProgressiveLevel::setHitMaxPlayedGames(const uint32_t hitMaxPlayedGames)
{
    this->hitMaxPlayedGames = hitMaxPlayedGames;
}

const uint32_t& ProgressiveLevel::getHitMaxPlayedGames() const
{
    return this->hitMaxPlayedGames;
}

void ProgressiveLevel::setHitPlayedGames(const uint32_t hitPlayedGames)
{
    this->hitPlayedGames = hitPlayedGames;
}

const uint32_t& ProgressiveLevel::getHitPlayedGames() const
{
    return this->hitPlayedGames;
}

void ProgressiveLevel::setHitStartTime(const uint32_t hitStartTime)
{
    this->hitStartTime = hitStartTime;
}

const uint32_t& ProgressiveLevel::getHitStartTime() const
{
    return this->hitStartTime;
}

void ProgressiveLevel::setHitEndTime(const uint32_t hitEndTime)
{
    this->hitEndTime = hitEndTime;
}

const uint32_t& ProgressiveLevel::getHitEndTime() const
{
    return this->hitEndTime;
}

void ProgressiveLevel::setHitTime(const uint32_t hitTime)
{
    this->hitTime = hitTime;
}

const uint32_t& ProgressiveLevel::getHitTime() const
{
    return this->hitTime;
}

void ProgressiveLevel::setHitWeekDays(const uint8_t hitWeekDays)
{
    this->hitWeekDays = hitWeekDays;
}

const uint8_t& ProgressiveLevel::getHitWeekDays() const
{
    return this->hitWeekDays;
}

void ProgressiveLevel::setHitMonths(const uint16_t hitMonths)
{
    this->hitMonths = hitMonths;
}

const uint16_t& ProgressiveLevel::getHitMonths() const
{
    return this->hitMonths;
}

void ProgressiveLevel::setHitMinDeductionAmount(
        const utils::Money& hitMinDeductionAmount)
{
    this->hitMinDeductionAmount = hitMinDeductionAmount;
}

const utils::Money& ProgressiveLevel::getHitMinDeductionAmount() const
{
    return this->hitMinDeductionAmount;
}

void ProgressiveLevel::setHitMaxDeductionAmount(
        const utils::Money& hitMaxDeductionAmount)
{
    this->hitMaxDeductionAmount = hitMaxDeductionAmount;
}

const utils::Money& ProgressiveLevel::getHitMaxDeductionAmount() const
{
    return this->hitMaxDeductionAmount;
}

void ProgressiveLevel::setHitDeductionAmount(
        const utils::Money& hitDeductionAmount)
{
    this->hitDeductionAmount = hitDeductionAmount;
}

const utils::Money& ProgressiveLevel::getHitDeductionAmount() const
{
    return this->hitDeductionAmount;
}

void ProgressiveLevel::setMinBetToWin(const utils::Money& minBetToWin)
{
    this->minBetToWin = minBetToWin;
}

const utils::Money& ProgressiveLevel::getMinBetToWin() const
{
    return this->minBetToWin;
}

void ProgressiveLevel::setActiveStartTime(const uint32_t activeStartTime)
{
    this->activeStartTime = activeStartTime;
}

const uint32_t& ProgressiveLevel::getActiveStartTime() const
{
    return this->activeStartTime;
}

void ProgressiveLevel::setActiveEndTime(const uint32_t activeEndTime)
{
    this->activeEndTime = activeEndTime;
}

const uint32_t& ProgressiveLevel::getActiveEndTime() const
{
    return this->activeEndTime;
}

void ProgressiveLevel::setActiveWeekDays(const uint8_t activeWeekDays)
{
    this->activeWeekDays = activeWeekDays;
}

const uint8_t& ProgressiveLevel::getActiveWeekDays() const
{
    return this->activeWeekDays;
}

void ProgressiveLevel::setActiveMonths(const uint16_t activeMonths)
{
    this->activeMonths = activeMonths;
}

const uint16_t& ProgressiveLevel::getActiveMonths() const
{
    return this->activeMonths;
}

void ProgressiveLevel::setMinMachinesNumber(const uint16_t minMachinesNumber)
{
    this->minMachinesNumber = minMachinesNumber;
}

const uint16_t& ProgressiveLevel::getMinMachinesNumber() const
{
    return this->minMachinesNumber;
}

void ProgressiveLevel::setMinMachinesPeriod(const uint16_t minMachinesPeriod)
{
    this->minMachinesPeriod = minMachinesPeriod;
}

const uint16_t& ProgressiveLevel::getMinMachinesPeriod() const
{
    return this->minMachinesPeriod;
}

void ProgressiveLevel::setMaxNumberOfHits(const uint16_t maxNumberOfHits)
{
    this->maxNumberOfHits = maxNumberOfHits;
}

const uint16_t& ProgressiveLevel::getMaxNumberOfHits() const
{
    return this->maxNumberOfHits;
}

void ProgressiveLevel::setMinActiveBet(const utils::Money minActiveBet)
{
    this->minActiveBet = minActiveBet;
}

const utils::Money& ProgressiveLevel::getMinActiveBet() const
{
    return this->minActiveBet;
}

void ProgressiveLevel::setMaxActiveBet(const utils::Money maxActiveBet)
{
    this->maxActiveBet = maxActiveBet;
}

const utils::Money& ProgressiveLevel::getMaxActiveBet() const
{
    return this->maxActiveBet;
}

void ProgressiveLevel::setNextStatus(const LevelStatus status)
{
    this->nextStatus = status;
}

const LevelStatus& ProgressiveLevel::getNextStatus() const
{
    return this->nextStatus;
}

void ProgressiveLevel::setNextBaseValue(const utils::Money& baseValue)
{
    this->nextBaseValue = baseValue;
}

const utils::Money& ProgressiveLevel::getNextBaseValue() const
{
    return this->nextBaseValue;
}

void ProgressiveLevel::setNextVisibleValue(const utils::Money& visibleValue)
{
    this->nextVisibleValue = visibleValue;
}

const utils::Money& ProgressiveLevel::getNextVisibleValue() const
{
    return this->nextVisibleValue;
}

void ProgressiveLevel::setNextVisibleLimitValue(
        const utils::Money& visibleLimitValue)
{
    this->nextVisibleLimitValue = visibleLimitValue;
}

const utils::Money& ProgressiveLevel::getNextVisibleLimitValue() const
{
    return this->nextVisibleLimitValue;
}

void ProgressiveLevel::setNextVisiblePercentage(
        const utils::Percent& visibleDeductionPercentage)
{
    this->nextVisibleDeductionPercentage = visibleDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getNextVisiblePercentage() const
{
    return this->nextVisibleDeductionPercentage;
}

const uint8_t& ProgressiveLevel::getNextUseVisibleMiddleValue() const
{
    return this->nextUseVisibleMiddleValue;
}

void ProgressiveLevel::setNextUseVisibleMiddleValue(
        const uint8_t nextUseVisibleMiddleValue)
{
    this->nextUseVisibleMiddleValue = nextUseVisibleMiddleValue;
}

const utils::Money& ProgressiveLevel::getNextVisibleMiddleValue() const
{
    return this->nextVisibleMiddleValue;
}

void ProgressiveLevel::setNextVisibleMiddleValue(
        const utils::Money& nextVisibleMiddleValue)
{
    this->nextVisibleMiddleValue = nextVisibleMiddleValue;
}

const utils::Percent& ProgressiveLevel::getNextVisibleMiddlePercentage() const
{
    return this->nextVisibleMiddlePercentage;
}

void ProgressiveLevel::setNextVisibleMiddlePercentage(
        const utils::Percent& nextVisibleMiddlePercentage)
{
    this->nextVisibleMiddlePercentage = nextVisibleMiddlePercentage;
}

void ProgressiveLevel::setNextHiddenValue(const utils::Money& hiddenValue)
{
    this->nextHiddenValue = hiddenValue;
}

const utils::Money& ProgressiveLevel::getNextHiddenValue() const
{
    return this->nextHiddenValue;
}

void ProgressiveLevel::setNextHiddenPercentage(
        const utils::Percent& hiddenDeductionPercentage)
{
    this->nextHiddenDeductionPercentage = hiddenDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getNextHiddenPercentage() const
{
    return this->nextHiddenDeductionPercentage;
}

void ProgressiveLevel::setNextHiddenValueAdd(
        const utils::Money& nextHiddenValueAdd)
{
    this->nextHiddenValueAdd = nextHiddenValueAdd;
}

const utils::Money& ProgressiveLevel::getNextHiddenValueAdd() const
{
    return this->nextHiddenValueAdd;
}

void ProgressiveLevel::setNextOverflowValue(const utils::Money& overflowValue)
{
    this->nextOverflowValue = overflowValue;
}

const utils::Money& ProgressiveLevel::getNextOverflowValue() const
{
    return this->nextOverflowValue;
}

void ProgressiveLevel::setNextOverflowPercentage(
        const utils::Percent& overflowDeductionPercentage)
{
    this->nextOverflowDeductionPercentage = overflowDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getNextOverflowPercentage() const
{
    return this->nextOverflowDeductionPercentage;
}

void ProgressiveLevel::setNextReserveValue(const utils::Money& reserveValue)
{
    this->nextReserveValue = reserveValue;
}

const utils::Money& ProgressiveLevel::getNextReserveValue() const
{
    return this->nextReserveValue;
}

void ProgressiveLevel::setNextReserveLimitValue(
        const utils::Money& reserveLimitValue)
{
    this->nextReserveLimitValue = reserveLimitValue;
}

const utils::Money& ProgressiveLevel::getNextReserveLimitValue() const
{
    return this->nextReserveLimitValue;
}

void ProgressiveLevel::setNextReservePercentage(
        const utils::Percent& nextReserveDeductionPercentage)
{
    this->nextReserveDeductionPercentage = nextReserveDeductionPercentage;
}

const utils::Percent& ProgressiveLevel::getNextReservePercentage() const
{
    return this->nextReserveDeductionPercentage;
}

void ProgressiveLevel::setNextMinBaseValue(
        const utils::Money& nextMinBaseValue)
{
    this->nextMinBaseValue = nextMinBaseValue;
}

const utils::Money& ProgressiveLevel::getNextMinBaseValue() const
{
    return this->nextMinBaseValue;
}

void ProgressiveLevel::setNextMaxBaseValue(
        const utils::Money& nextMaxBaseValue)
{
    this->nextMaxBaseValue = nextMaxBaseValue;
}

const utils::Money& ProgressiveLevel::getNextMaxBaseValue() const
{
    return this->nextMaxBaseValue;
}

void ProgressiveLevel::setNextHitMinTriggerValue(
        const utils::Money& nextHitMinTriggerValue)
{
    this->nextHitMinTriggerValue = nextHitMinTriggerValue;
}

const utils::Money& ProgressiveLevel::getNextHitMinTriggerValue() const
{
    return this->nextHitMinTriggerValue;
}

void ProgressiveLevel::setNextHitMaxTriggerValue(
        const utils::Money& nextHitMaxTriggerValue)
{
    this->nextHitMaxTriggerValue = nextHitMaxTriggerValue;
}

const utils::Money& ProgressiveLevel::getNextHitMaxTriggerValue() const
{
    return this->nextHitMaxTriggerValue;
}

void ProgressiveLevel::setNextHitMinBetAmount(
        const utils::Money& nextHitMinBetAmount)
{
    this->nextHitMinBetAmount = nextHitMinBetAmount;
}

const utils::Money& ProgressiveLevel::getNextHitMinBetAmount() const
{
    return this->nextHitMinBetAmount;
}

void ProgressiveLevel::setNextHitMaxBetAmount(
        const utils::Money& nextHitMaxBetAmount)
{
    this->nextHitMaxBetAmount = nextHitMaxBetAmount;
}

const utils::Money& ProgressiveLevel::getNextHitMaxBetAmount() const
{
    return this->nextHitMaxBetAmount;
}

void ProgressiveLevel::setNextHitMinPlayedGames(
        const uint32_t nextHitMinPlayedGames)
{
    this->nextHitMinPlayedGames = nextHitMinPlayedGames;
}

const uint32_t& ProgressiveLevel::getNextHitMinPlayedGames() const
{
    return this->nextHitMinPlayedGames;
}

void ProgressiveLevel::setNextHitMaxPlayedGames(
        const uint32_t nextHitMaxPlayedGames)
{
    this->nextHitMaxPlayedGames = nextHitMaxPlayedGames;
}

const uint32_t& ProgressiveLevel::getNextHitMaxPlayedGames() const
{
    return this->nextHitMaxPlayedGames;
}

void ProgressiveLevel::setNextHitStartTime(const uint32_t nextHitStartTime)
{
    this->nextHitStartTime = nextHitStartTime;
}

const uint32_t& ProgressiveLevel::getNextHitStartTime() const
{
    return this->nextHitStartTime;
}

void ProgressiveLevel::setNextHitEndTime(const uint32_t nextHitEndTime)
{
    this->nextHitEndTime = nextHitEndTime;
}

const uint32_t& ProgressiveLevel::getNextHitEndTime() const
{
    return this->nextHitEndTime;
}

void ProgressiveLevel::setNextHitWeekDays(const uint8_t nextWeekDays)
{
    this->nextHitWeekDays = nextWeekDays;
}

const uint8_t& ProgressiveLevel::getNextHitWeekDays() const
{
    return this->nextHitWeekDays;
}

void ProgressiveLevel::setNextHitMonths(const uint16_t nextMonths)
{
    this->nextHitMonths = nextMonths;
}

const uint16_t& ProgressiveLevel::getNextHitMonths() const
{
    return this->nextHitMonths;
}

void ProgressiveLevel::setNextHitMinDeductionAmount(
        const utils::Money& nextHitMinDeductionAmount)
{
    this->nextHitMinDeductionAmount = nextHitMinDeductionAmount;
}

const utils::Money& ProgressiveLevel::getNextHitMinDeductionAmount() const
{
    return this->nextHitMinDeductionAmount;
}

void ProgressiveLevel::setNextHitMaxDeductionAmount(
        const utils::Money& nextHitMinDeductionAmount)
{
    this->nextHitMinDeductionAmount = nextHitMinDeductionAmount;
}

const utils::Money& ProgressiveLevel::getNextHitMaxDeductionAmount() const
{
    return this->nextHitMaxDeductionAmount;
}

void ProgressiveLevel::setNextMinBetToWin(const utils::Money& nextMinBetToWin)
{
    this->nextMinBetToWin = nextMinBetToWin;
}

const utils::Money& ProgressiveLevel::getNextMinBetToWin() const
{
    return this->nextMinBetToWin;
}

void ProgressiveLevel::setNextActiveStartTime(
        const uint32_t nextActiveStartTime)
{
    this->nextActiveStartTime = nextActiveStartTime;
}

const uint32_t& ProgressiveLevel::getNextActiveStartTime() const
{
    return this->nextActiveStartTime;
}

void ProgressiveLevel::setNextActiveEndTime(const uint32_t nextActiveEndTime)
{
    this->nextActiveEndTime = nextActiveEndTime;
}

const uint32_t& ProgressiveLevel::getNextActiveEndTime() const
{
    return this->nextActiveEndTime;
}

void ProgressiveLevel::setNextActiveWeekDays(const uint8_t nextActiveWeekDays)
{
    this->nextActiveWeekDays = nextActiveWeekDays;
}

const uint8_t& ProgressiveLevel::getNextActiveWeekDays() const
{
    return this->nextActiveWeekDays;
}

void ProgressiveLevel::setNextActiveMonths(const uint16_t nextActiveMonths)
{
    this->nextActiveMonths = nextActiveMonths;
}

const uint16_t& ProgressiveLevel::getNextActiveMonths() const
{
    return this->nextActiveMonths;
}

void ProgressiveLevel::setNextMinMachinesNumber(
        const uint16_t nextMinMachinesNumber)
{
    this->nextMinMachinesNumber = nextMinMachinesNumber;
}

const uint16_t& ProgressiveLevel::getNextMinMachinesNumber() const
{
    return this->nextMinMachinesNumber;
}

void ProgressiveLevel::setNextMinMachinesPeriod(
        const uint16_t nextMinMachinesPeriod)
{
    this->nextMinMachinesPeriod = nextMinMachinesPeriod;
}

const uint16_t& ProgressiveLevel::getNextMinMachinesPeriod() const
{
    return this->nextMinMachinesPeriod;
}

void ProgressiveLevel::setNextMaxNumberOfHits(
        const uint16_t nextMaxNumberOfHits)
{
    this->nextMaxNumberOfHits = nextMaxNumberOfHits;
}

const uint16_t& ProgressiveLevel::getNextMaxNumberOfHits() const
{
    return this->nextMaxNumberOfHits;
}

void ProgressiveLevel::setNextMinActiveBet(
        const utils::Money& nextMinActiveBet)
{
    this->nextMinActiveBet = nextMinActiveBet;
}

const utils::Money& ProgressiveLevel::getNextMinActiveBet() const
{
    return this->nextMinActiveBet;
}

void ProgressiveLevel::setNextMaxActiveBet(
        const utils::Money& nextMaxActiveBet)
{
    this->nextMaxActiveBet = nextMaxActiveBet;
}

const utils::Money& ProgressiveLevel::getNextMaxActiveBet() const
{
    return this->nextMaxActiveBet;
}

void ProgressiveLevel::setLastActivationTime(uint32_t activationTime)
{
    this->lastActivationTime = activationTime;
}

const uint32_t& ProgressiveLevel::getLastActivationTime() const
{
    return this->lastActivationTime;
}

void ProgressiveLevel::setLastDeactivationTime(uint32_t deactivationTime)
{
    this->lastDeactivationTime = deactivationTime;
}

const uint32_t& ProgressiveLevel::getLastDeactivationTime() const
{
    return this->lastDeactivationTime;
}

void ProgressiveLevel::setLastChangeTime(uint32_t changeTime)
{
    this->lastChangeTime = changeTime;
}

const uint32_t& ProgressiveLevel::getLastChangeTime() const
{
    return this->lastChangeTime;
}

void ProgressiveLevel::setTimesWon(uint32_t timesWon)
{
    this->timesWon = timesWon;
}

const uint32_t& ProgressiveLevel::getTimesWon() const
{
    return this->timesWon;
}

void ProgressiveLevel::setTotalWon(uint64_t totalWon)
{
    this->totalWon = totalWon;
}

const uint64_t& ProgressiveLevel::getTotalWon() const
{
    return this->totalWon;
}

void ProgressiveLevel::setTotalDeduction(const utils::Money& totalDeduction)
{
    this->totalDeduction = totalDeduction;
}

const utils::Money& ProgressiveLevel::getTotalDeduction() const
{
    return this->totalDeduction;
}

void ProgressiveLevel::setPartialDeduction(
        const utils::Money& partialDeduction)
{
    this->partialDeduction = partialDeduction;
}

const utils::Money& ProgressiveLevel::getPartialDeduction() const
{
    return this->partialDeduction;
}

void ProgressiveLevel::setTotalBetsNumber(uint32_t betsNumber)
{
    this->totalBetsNumber = betsNumber;
}

const uint32_t& ProgressiveLevel::getTotalBetsNumber() const
{
    return this->totalBetsNumber;
}

void ProgressiveLevel::setPartialBetsNumber(uint32_t partialBetsNumber)
{
    this->partialBetsNumber = partialBetsNumber;
}

const uint32_t& ProgressiveLevel::getPartialBetsNumber() const
{
    return this->partialBetsNumber;
}

void ProgressiveLevel::setTotalBet(uint64_t totalBet)
{
    this->totalBet = totalBet;
}

const uint64_t& ProgressiveLevel::getTotalBet() const
{
    return this->totalBet;
}

void ProgressiveLevel::setPartialBet(uint32_t partialBet)
{
    this->partialBet = partialBet;
}

const uint32_t& ProgressiveLevel::getPartialBet() const
{
    return this->partialBet;
}

void ProgressiveLevel::setMinWin(const utils::Money& minWin)
{
    this->minWin = minWin;
}

const utils::Money& ProgressiveLevel::getMinWin() const
{
    return this->minWin;
}

void ProgressiveLevel::setMaxWin(const utils::Money& maxWin)
{
    this->maxWin = maxWin;
}

const utils::Money& ProgressiveLevel::getMaxWin() const
{
    return this->maxWin;
}

void ProgressiveLevel::setTotalHiddenAddition(
        const utils::Money& totalHiddenAddition)
{
    this->totalHiddentAddition = totalHiddenAddition;
}

const utils::Money& ProgressiveLevel::getTotalHiddenAddition() const
{
    return this->totalHiddentAddition;
}

void ProgressiveLevel::setLocked(bool locked)
{
    this->locked = locked;
}

const bool ProgressiveLevel::isLocked() const
{
    return this->locked;
}

void ProgressiveLevel::setOnFocus(bool onFocus)
{
    this->onFocus = onFocus;
}

const bool ProgressiveLevel::isOnFocus() const
{
    return this->onFocus;
}

const std::string ProgressiveLevel::toString() const
{
    std::stringstream ss;

    ss << "##### LEVEL ID (" << this->internalId << ", " <<
            this->externalId << "), SESSION ID " <<
            this-sessionId << ", DENOM IDX " << this-denomIndex << " #####" << std::endl;
    ss << std::endl;

    switch ( this->type )
    {
        case LevelType::InternalLevel:
            ss << "Type: internal" << std::endl;
            break;
        case LevelType::TriggerLevel:
            ss << "Type: internal trigger" << std::endl;
            break;
        case LevelType::ExternalLevel:
            ss << "Type: external" << std::endl;
            break;
        default:
            ss << "Type: unknown" << std::endl;
    }
    ss << "Locked: " << (this->locked ? "true": "false") << std::endl;
    ss << "On focus: " << (this->onFocus ? "true": "false") << std::endl;

    ss << "Apply next settings: " <<
        (this-applyNextSettings ? "true": "false") << std::endl;
    ss << "Status: ";
    switch ( this->status )
    {
        case LevelStatus::NotSet:
            ss << "Not set" << std::endl;
            break;
        case LevelStatus::Active:
            ss << "Active" << std::endl;
            break;
        case LevelStatus::Inactive:
            ss << "Inactive" << std::endl;
            break;
        default:
            ss << "Unknown" << std::endl;
    }
    ss << "BaseValue: " <<
        (std::string) this->baseValue << std::endl;
    ss << std::endl;

    ss << "VisibleValue: " <<
        (std::string) this->visibleValue << std::endl;
    ss << "VisibleLimit: " <<
        (std::string) this->visibleLimitValue << std::endl;
    ss << "VisiblePercent: " <<
        (std::string) this->visibleDeductionPercentage << std::endl;
    ss << "UseVisibleMiddleValue: " <<
         this->useVisibleMiddleValue << std::endl;
    ss << "VisibleMiddleValue: " <<
        (std::string) this->visibleMiddleValue << std::endl;
    ss << "VisibleMiddlePercent: " <<
        (std::string) this->visibleMiddlePercentage << std::endl;
    ss << std::endl;

    ss << "HiddenValue: " <<
        (std::string) this->hiddenValue << std::endl;
    ss << "HiddenPercent: " <<
        (std::string) this->hiddenDeductionPercentage << std::endl;
    ss << "HiddenValueAdd: " <<
        (std::string) this->hiddenValueAdd << std::endl;
    ss << std::endl;

    ss << "Overflow (Automatic): " <<
        (this-automaticOverflow ? "true": "false") << std::endl;
    ss << "OverflowValue: " <<
        (std::string) this->overflowValue << std::endl;
    ss << "OverflowPercent: " <<
        (std::string) this->overflowDeductionPercentage << std::endl;
    ss << std::endl;

    ss << "ReserveValue: " <<
        (std::string) this->reserveValue << std::endl;
    ss << "ReserveLimit: " <<
        (std::string) this->reserveLimitValue << std::endl;
    ss << "ReservePercent: " <<
        (std::string) this->reserveDeductionPercentage << std::endl;
    ss << std::endl;
    ss << "Min Base Value: " <<
        (std::string) this->minBaseValue << std::endl;
    ss << "Max Base Value: " <<
        (std::string) this->maxBaseValue << std::endl;
    ss << std::endl;

    ss << "Hit Min Trigger Value: " <<
        (std::string) this->hitMinTriggerValue << std::endl;
    ss << "Hit Max Trigger Value: " <<
        (std::string) this->hitMaxTriggerValue << std::endl;
    ss << "Hit Trigger Value: " <<
        (std::string) this->hitTriggerValue << std::endl;
    ss << std::endl;

    ss << "Hit Min Played Bet Amount: " <<
        (std::string) this->hitMinBetAmount << std::endl;
    ss << "Hit Max Played Bet Amount: " <<
        (std::string) this->hitMaxBetAmount << std::endl;
    ss << "Hit Played Bet Amount: " <<
        (std::string) this->hitBetAmount << std::endl;
    ss << std::endl;

    ss << "Hit Min Played Games: " << this->hitMinPlayedGames << std::endl;
    ss << "Hit Max Played Games: " << this->hitMaxPlayedGames << std::endl;
    ss << "Hit Played Games: " << this->hitPlayedGames << std::endl;
    ss << std::endl;

    time_t dateTime = this->hitStartTime;
    ss << "Hit Start Time: " << ctime(&dateTime) << std::endl;
    dateTime = this->hitEndTime;
    ss << "Hit End Time: " << ctime(&dateTime) << std::endl;
    dateTime = this->hitTime;
    ss << "Hit Time: " << ctime(&dateTime) << std::endl;
    ss << "Hit Week Days: 0x" << std::hex <<
        static_cast<int>(this->hitWeekDays) << std::dec << std::endl;
    ss << "Hit Months: 0x" << std::hex <<
            this-hitMonths << std::dec << std::endl;
    ss << std::endl;

    ss << "Hit Min Deduction Amount: " <<
        (std::string) this->hitMinDeductionAmount << std::endl;
    ss << "Hit Max Deduction Amount: " <<
        (std::string) this->hitMaxDeductionAmount << std::endl;
    ss << "Hit Deduction Amount: " <<
        (std::string) this->hitDeductionAmount << std::endl;
    ss << std::endl;

    ss << "Min Bet To Win: " <<
        (std::string) this->minBetToWin << std::endl;
    dateTime = this->activeStartTime;
    ss << "Active Start Time: " << ctime(&dateTime) << std::endl;
    dateTime = this->activeEndTime;
    ss << "Active End Time: " << ctime(&dateTime) << std::endl;
    ss << "Active Week Days: 0x" << std::hex <<
        static_cast<int>(this->activeWeekDays) << std::dec << std::endl;
    ss << "Active Months: 0x" << std::hex <<
            this-activeMonths << std::dec << std::endl;
    ss << "Min Machines Number: " << this-minMachinesNumber << std::endl;
    ss << "Min Machines Period: " << this-minMachinesPeriod << std::endl;
    ss << "Max Number Of Hits: " << this-maxNumberOfHits << std::endl;
    ss << "Min Active Bet Amount: " <<
        (std::string) this->minActiveBet << std::endl;
    ss << "Max Active Bet Amount: " <<
        (std::string) this->maxActiveBet << std::endl;
    ss << std::endl;

    ss << "Next status: ";
    switch ( this->nextStatus )
    {
        case LevelStatus::NotSet:
            ss << "Not set" << std::endl;
            break;
        case LevelStatus::Active:
            ss << "Active" << std::endl;
            break;
        case LevelStatus::Inactive:
            ss << "Inactive" << std::endl;
            break;
        default:
            ss << "Unknown" << std::endl;
    }
    ss << "Next BaseValue: " <<
        (std::string) this->nextBaseValue << std::endl;
    ss << std::endl;

    ss << "Next VisibleValue: " <<
        (std::string) this->nextVisibleValue << std::endl;
    ss << "Next VisibleLimit: " <<
        (std::string) this->nextVisibleLimitValue << std::endl;
    ss << "Next VisiblePercent: " <<
        (std::string) this->nextVisibleDeductionPercentage << std::endl;
    ss << std::endl;

    ss << "Next HiddenValue: " <<
        (std::string) this->nextHiddenValue << std::endl;
    ss << "Next HiddenPercent: " <<
        (std::string) this->nextHiddenDeductionPercentage << std::endl;
    ss << "Next HiddenValueAdd: " <<
        (std::string) this->nextHiddenValueAdd << std::endl;
    ss << std::endl;

    ss << "Next OverflowValue: " <<
        (std::string) this->nextOverflowValue << std::endl;
    ss << "Next OverflowPercent: " <<
        (std::string) this->nextOverflowDeductionPercentage << std::endl;
    ss << std::endl;

    ss << "Next ReserveValue: " <<
        (std::string) this->nextReserveValue << std::endl;
    ss << "Next ReserveLimit: " <<
        (std::string) this->nextReserveLimitValue << std::endl;
    ss << "Next ReservePercent: " <<
        (std::string) this->nextReserveDeductionPercentage << std::endl;
    ss << std::endl;

    ss << "Next Min Base Value: " <<
        (std::string) this->nextMinBaseValue << std::endl;
    ss << "Next Max Base Value: " <<
        (std::string) this->nextMaxBaseValue << std::endl;
    ss << std::endl;

    ss << "Next Hit Min Trigger Value: " <<
        (std::string) this->nextHitMinTriggerValue << std::endl;
    ss << "Next Hit Max Trigger Value: " <<
        (std::string) this->nextHitMaxTriggerValue << std::endl;
    ss << std::endl;

    ss << "Next Hit Min Played Bet Amount: " <<
        (std::string) this->nextHitMinBetAmount << std::endl;
    ss << "Next Hit Max Played Bet Amount: " <<
        (std::string) this->nextHitMaxBetAmount << std::endl;
    ss << std::endl;

    ss << "Next Hit Min Played Games: " <<
            this-nextHitMinPlayedGames << std::endl;
    ss << "Next Hit Max Played Games: " <<
            this-nextHitMaxPlayedGames << std::endl;
    ss << std::endl;

    dateTime = this->nextHitStartTime;
    ss << "Next Hit Start Time: " << ctime(&dateTime);
    dateTime = this->nextHitEndTime;
    ss << "Next Hit End Time: " << ctime(&dateTime);
    ss << "Next Hit Week Days: 0x" << std::hex <<
        static_cast<int>(this->nextHitWeekDays) << std::dec << std::endl;
    ss << "Next Hit Months: 0x" << std::hex <<
            this-nextHitMonths << std::dec << std::endl;
    ss << std::endl;

    ss << "Next Hit Min Deduction Amount: " <<
        (std::string) this->nextHitMinDeductionAmount << std::endl;
    ss << "Next Hit Max Deduction Amount: " <<
        (std::string) this->nextHitMaxDeductionAmount << std::endl;
    ss << std::endl;

    ss << "Next Min Bet To Win: " <<
        (std::string) this->nextMinBetToWin << std::endl;
    dateTime = this->nextActiveStartTime;
    ss << "Next Active Start Time: " << ctime(&dateTime);
    dateTime = this->nextActiveEndTime;
    ss << "Next Active End Time: " << ctime(&dateTime);
    ss << "Next Active Week Days: 0x" << std::hex <<
        static_cast<int>(this->nextActiveWeekDays) << std::dec << std::endl;
    ss << "Next Active Months: 0x" << std::hex <<
            this-nextActiveMonths << std::dec << std::endl;
    ss << "Next Min Machines Number: " <<
            this-nextMinMachinesNumber << std::endl;
    ss << "Next Min Machines Period: " <<
            this-nextMinMachinesPeriod << std::endl;
    ss << "Next Max Number Of Hits: " <<
            this-nextMaxNumberOfHits << std::endl;
    ss << "Next Min Active Bet Amount: " <<
        (std::string) this->nextMinActiveBet << std::endl;
    ss << "Next Max Active Bet Amount: " <<
        (std::string) this->nextMaxActiveBet << std::endl;
    ss << std::endl;

    ss << "STATISTICS" << std::endl;
    dateTime = this->lastActivationTime;
    ss << "Last activation time: " << ctime(&dateTime);
    dateTime = this->lastDeactivationTime;
    ss << "Last deactivation time: " << ctime(&dateTime);
    dateTime = this->lastChangeTime;
    ss << "Last change time: " << ctime(&dateTime);
    ss << "Times won: " << this->timesWon << std::endl;
    ss << "Total won in cents: " << this->totalWon << std::endl;
    ss << "Total deduction: " <<
        (std::string) this->totalDeduction << std::endl;
    ss << "Partial deduction (since last win): " <<
        (std::string) this->partialDeduction << std::endl;
    ss << "Total number of bets: " << this->totalBetsNumber << std::endl;
    ss << "Partial number of bets (since last win): " <<
        this->partialBetsNumber << std::endl;
    ss << "Total bet in cents: " << this->totalBet << std::endl;
    ss << "Partial bet in cents (since last win): " <<
            this->partialBet << std::endl;
    ss << "Min win: " << (std::string) this->minWin << std::endl;
    ss << "Max win: " << (std::string) this->maxWin << std::endl;
    ss << std::endl;

    return ss.str();
}
