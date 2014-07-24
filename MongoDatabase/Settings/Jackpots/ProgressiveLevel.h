/**
 * ProgressiveLevel.h
 *
 * $id$
 *
 * Description: Base class definition of a progressive level
 * Author: Stamen Rakov
 *
 * Copyright (c) 2010, Euro Games Technology Ltd.
 * All rights reserved
 *
 * More information at: http://www.egt-bg.com
 */

#ifndef PROGRESSIVE_LEVEL_H
#define PROGRESSIVE_LEVEL_H

#include <sstream>
#include <memory>
#include <cstdint>
#include <map>

#include "Utils/Money.h"
#include "Utils/Percent.h"
#include "Settings/Jackpots/Definitions/LevelType.h"
#include "Settings/Jackpots/Definitions/LevelStatus.h"

/**
 */
class ProgressiveLevel
{

private:
    /**
     * The default constructor is forbidden.
     */
	ProgressiveLevel();

public:
    /**
     */
    ProgressiveLevel(const LevelType type,
                     const uint32_t internalId,
                     const uint32_t externalId,
                     const uint32_t sessionId,
                     const int16_t denomIndex);

    /**
     */
    ProgressiveLevel & operator = (const ProgressiveLevel & level);

    /**
     */
    virtual bool operator== (const ProgressiveLevel & level)
    {
        return (this->type == level.getType()) &&
               (this->internalId == level.getInternalId()) &&
               (this->externalId == level.getExternalId()) &&
               (this->sessionId == level.getSessionId()) &&
               (this->denomIndex == level.getDenomIndex()) &&
               (this->applyNextSettings == level.getApplyNextSettings()) &&
               (this->status == level.getStatus()) &&
               (this->baseValue == level.getBaseValue()) &&
               (this->visibleValue == level.getVisibleValue()) &&
               (this->visibleLimitValue == level.getVisibleLimitValue()) &&
               (this->visibleDeductionPercentage == level.getVisiblePercentage()) &&
               (this->hiddenValue == level.getHiddenValue()) &&
               (this->hiddenDeductionPercentage == level.getHiddenPercentage()) &&
               (this->overflowValue == level.getOverflowValue()) &&
               (this->overflowDeductionPercentage ==
                level.getOverflowPercentage()) &&
               (this->reserveValue == level.getReserveValue()) &&
               (this->reserveLimitValue == level.getReserveLimitValue()) &&
               (this->reserveDeductionPercentage == level.getReservePercentage()) &&
               (this->nextStatus == level.getNextStatus()) &&
               (this->nextBaseValue == level.getNextBaseValue()) &&
               (this->nextVisibleValue == level.getNextVisibleValue()) &&
               (this->nextVisibleLimitValue == level.getNextVisibleLimitValue()) &&
               (this->nextVisibleDeductionPercentage ==
                level.getNextVisiblePercentage()) &&
               (this->nextHiddenValue == level.getNextHiddenValue()) &&
               (this->nextHiddenDeductionPercentage ==
                level.getNextHiddenPercentage()) &&
               (this->nextOverflowValue == level.getNextOverflowValue()) &&
               (this->nextOverflowDeductionPercentage ==
                level.getNextOverflowPercentage()) &&
               (this->nextReserveValue == level.getNextReserveValue()) &&
               (this->nextReserveLimitValue == level.getNextReserveLimitValue()) &&
               (this->nextReserveDeductionPercentage ==
                level.getNextReservePercentage());
    }

    /**
     */
    virtual ~ProgressiveLevel();


#ifdef EGT_DEBUG
    /**
     */
    virtual void dumpValues();
#endif // EGT_DEBUG

public:
    /**
     */
    const LevelType & getType() const;

    /**
     */
    void setInternalId(uint32_t internalId);

    /**
     */
    const uint32_t & getInternalId() const;

    /**
     */
    void setExternalId(uint32_t externalId);

    /**
     */
    const uint32_t & getExternalId() const;

    /**
     */
    bool isExternal() const;

    /**
     */
    void setSessionId(uint32_t sessionId);

    /**
     */
    const uint32_t & getSessionId() const;

    /**
     */
    void setDenomIndex(int16_t denomIndex);

    /**
     */
    const int16_t & getDenomIndex() const;

public:
    /**
     */
    void setApplyNextSettings(bool apply);

    /**
     */
    const bool getApplyNextSettings() const;

    /**
     */
    void setStatus(const LevelStatus status);

    /**
     */
    const LevelStatus & getStatus() const;

    /**
     */
    void setBaseValue(const utils::Money & baseValue);

    /**
     */
    const utils::Money & getBaseValue() const;

    /**
     */
    void setVisibleValue(const utils::Money & visibleValue);

    /**
     */
    const utils::Money & getVisibleValue() const;

    /**
     */
    void setVisibleLimitValue(const utils::Money & visibleLimitValue);

    /**
     */
    const utils::Money & getVisibleLimitValue() const;

    /**
     */
    void setVisiblePercentage(const utils::Percent & visibleDeductionPercentage);

    /**
     */
    const utils::Percent & getVisiblePercentage() const;

    /**
     */
    void setUseVisibleMiddleValue(const uint8_t useVisibleMiddleValue);

    /**
     */
    const uint8_t & getUseVisibleMiddleValue() const;

    /**
     */
    void setVisibleMiddleValue(const utils::Money middleValue);

    /**
     */
    const utils::Money & getVisibleMiddleValue() const;

    /**
     */
    void setVisibleMiddlePercentage(const utils::Percent & visibleMiddlePercentage);

    /**
     */
    const utils::Percent & getVisibleMiddlePercentage() const;

    /**
     */
    void setHiddenValue(const utils::Money & hiddenValue);

    /**
     */
    const utils::Money & getHiddenValue() const;

    /**
     */
    void setHiddenPercentage(const utils::Percent & hiddenDeductionPercentage);

    /**
     */
    const utils::Percent & getHiddenPercentage() const;

    /**
     */
    void setHiddenValueAdd(const utils::Money & hiddenValueAdd);

    /**
     */
    const utils::Money & getHiddenValueAdd() const;


    /**
     */
    void setAutomaticOverflow(bool automaticOverflow);

    /**
     */
    const bool getAutomaticOverflow() const;

    /**
     */
    void setOverflowValue(const utils::Money & overflowValue);

    /**
     */
    const utils::Money & getOverflowValue() const;

    /**
     */
    void setOverflowPercentage(const utils::Percent & overflowDeductionPercentage);

    /**
     */
    const utils::Percent & getOverflowPercentage() const;

    /**
     */
    void setReserveValue(const utils::Money & reserveValue);

    /**
     */
    const utils::Money & getReserveValue() const;

    /**
     */
    void setReserveLimitValue(const utils::Money & reserveLimitValue);

    /**
     */
    const utils::Money & getReserveLimitValue() const;

    /**
     */
    void setReservePercentage(const utils::Percent & reserveDeductionPercentage);

    /**
     */
    const utils::Percent & getReservePercentage() const;

    /**
     */
    void setMinBaseValue(const utils::Money & minBaseValue);

    /**
     */
    const utils::Money & getMinBaseValue() const;

    /**
     */
    void setMaxBaseValue(const utils::Money & maxBaseValue);

    /**
     */
    const utils::Money & getMaxBaseValue() const;

    /**
     */
    void setHitMinTriggerValue(const utils::Money & minTriggerValue);

    /**
     */
    const utils::Money & getHitMinTriggerValue() const;

    /**
     */
    void setHitMaxTriggerValue(const utils::Money & maxTriggerValue);

    /**
     */
    const utils::Money & getHitMaxTriggerValue() const;

    /**
     */
    void setHitTriggerValue(const utils::Money & minTriggerValue);

    /**
     */
    const utils::Money & getHitTriggerValue() const;

    /**
     */
    void setHitMinBetAmount(const utils::Money & minBetAmount);

    /**
     */
    const utils::Money & getHitMinBetAmount() const;

    /**
     */
    void setHitMaxBetAmount(const utils::Money & maxBetAmount);

    /**
     */
    const utils::Money & getHitMaxBetAmount() const;

    /**
     */
    void setHitBetAmount(const utils::Money & betAmount);

    /**
     */
    const utils::Money & getHitBetAmount() const;

    /**
     */
    void setHitMinPlayedGames(const uint32_t hitMinPlayedGames);

    /**
     */
    const uint32_t & getHitMinPlayedGames() const;

    /**
     */
    void setHitMaxPlayedGames(const uint32_t hitMaxPlayedGames);

    /**
     */
    const uint32_t & getHitMaxPlayedGames() const;

    /**
     */
    void setHitPlayedGames(const uint32_t hitPlayedGames);

    /**
     */
    const uint32_t & getHitPlayedGames() const;

    /**
     */
    void setHitStartTime(const uint32_t hitStartTime);

    /**
     */
    const uint32_t & getHitStartTime() const;

    /**
     */
    void setHitEndTime(const uint32_t hitEndTime);

    /**
     */
    const uint32_t & getHitEndTime() const;

    /**
     */
    void setHitTime(const uint32_t hitTime);

    /**
     */
    const uint32_t & getHitTime() const;

    /**
     */
    void setHitWeekDays(const uint8_t hitWeekDays);

    /**
     */
    const uint8_t & getHitWeekDays() const;

    /**
     */
    void setHitMonths(const uint16_t hitTime);

    /**
     */
    const uint16_t & getHitMonths() const;

    /**
     */
    void setHitMinDeductionAmount(const utils::Money & hitMinDeductionAmount);

    /**
     */
    const utils::Money & getHitMinDeductionAmount() const;

    /**
     */
    void setHitMaxDeductionAmount(const utils::Money & hitMaxDeductionAmount);

    /**
     */
    const utils::Money & getHitMaxDeductionAmount() const;

    /**
     */
    void setHitDeductionAmount(const utils::Money & hitDeductionAmount);

    /**
     */
    const utils::Money & getHitDeductionAmount() const;

    /**
     */
    void setMinBetToWin(const utils::Money & minBetToWin);

    /**
     */
    const utils::Money & getMinBetToWin() const;

    /**
     */
    void setActiveStartTime(const uint32_t activeStartTime);

    /**
     */
    const uint32_t & getActiveStartTime() const;

    /**
     */
    void setActiveEndTime(const uint32_t activeEndTime);

    /**
     */
    const uint32_t & getActiveEndTime() const;

    /**
     */
    void setActiveWeekDays(const uint8_t activeWeekDays);

    /**
     */
    const uint8_t & getActiveWeekDays() const;

    /**
     */
    void setActiveMonths(const uint16_t activeMonths);

    /**
     */
    const uint16_t & getActiveMonths() const;

    /**
     */
    void setMinMachinesNumber(const uint16_t minMachinesNumber);

    /**
     */
    const uint16_t & getMinMachinesNumber() const;

    /**
     */
    void setMinMachinesPeriod(const uint16_t minMachinesPeriod);

    /**
     */
    const uint16_t & getMinMachinesPeriod() const;

    /**
     */
    void setMaxNumberOfHits(const uint16_t maxNumberOfHits);

    /**
     */
    const uint16_t & getMaxNumberOfHits() const;

    /**
     */
    void setMinActiveBet(const utils::Money minActiveBet);

    /**
     */
    const utils::Money & getMinActiveBet() const;

    /**
     */
    void setMaxActiveBet(const utils::Money maxActiveBet);

    /**
     */
    const utils::Money & getMaxActiveBet() const;


public:
    /**
     */
    void setNextStatus(const LevelStatus status);

    /**
     */
    const LevelStatus & getNextStatus() const;

    /**
     */
    void setNextBaseValue(const utils::Money & baseValue);

    /**
     */
    const utils::Money & getNextBaseValue() const;

    /**
     */
    void setNextVisibleValue(const utils::Money & visibleValue);

    /**
     */
    const utils::Money & getNextVisibleValue() const;

    /**
     */
    void setNextVisibleLimitValue(const utils::Money & visibleLimitValue);

    /**
     */
    const utils::Money & getNextVisibleLimitValue() const;
    /**
     */
    void setNextVisiblePercentage(const utils::Percent & visibleDeductionPercentage);

    /**
     */
    const utils::Percent & getNextVisiblePercentage() const;

    /**
     */
    const uint8_t & getNextUseVisibleMiddleValue() const;

    /**
     */
    void setNextUseVisibleMiddleValue(const uint8_t nextUseVisibleMiddleValue);

    /**
     */
    const utils::Money & getNextVisibleMiddleValue() const;
    /**
     */
    void setNextVisibleMiddleValue(const utils::Money & nextVisibleMiddleValue);

    /**
     */
    const utils::Percent & getNextVisibleMiddlePercentage() const;
    /**
     */
    void setNextVisibleMiddlePercentage(const utils::Percent & nextVisibleMiddlePercentage);

    /**
     */
    void setNextHiddenValue(const utils::Money & hiddenValue);

    /**
     */
    const utils::Money & getNextHiddenValue() const;

    /**
     */
    void setNextHiddenPercentage(const utils::Percent & hiddenDeductionPercentage);

    /**
     */
    const utils::Percent & getNextHiddenPercentage() const;

    /**
     */
    void setNextHiddenValueAdd(const utils::Money & nextHiddenValueAdd);

    /**
     */
    const utils::Money & getNextHiddenValueAdd() const;

    /**
     */
    void setNextOverflowValue(const utils::Money & overflowValue);

    /**
     */
    const utils::Money & getNextOverflowValue() const;

    /**
     */
    void setNextOverflowPercentage(const utils::Percent & overflowDeductionPercentage);

    /**
     */
    const utils::Percent & getNextOverflowPercentage() const;

    /**
     */
    void setNextReserveValue(const utils::Money & reserveValue);

    /**
     */
    const utils::Money & getNextReserveValue() const;

    /**
     */
    void setNextReserveLimitValue(const utils::Money & reserveLimitValue);

    /**
     */
    const utils::Money & getNextReserveLimitValue() const;

    /**
     */
    void setNextReservePercentage(
            const utils::Percent & nextReserveDeductionPercentage);

    /**
     */
    const utils::Percent & getNextReservePercentage() const;

    /**
     */
    void setNextMinBaseValue(const utils::Money & nextMinBaseValue);

    /**
     */
    const utils::Money & getNextMinBaseValue() const;

    /**
     */
    void setNextMaxBaseValue(const utils::Money & nextMaxBaseValue);

    /**
     */
    const utils::Money & getNextMaxBaseValue() const;

    /**
     */
    void setNextHitMinTriggerValue(const utils::Money & nextHitMinTriggerValue);

    /**
     */
    const utils::Money & getNextHitMinTriggerValue() const;

    /**
     */
    void setNextHitMaxTriggerValue(const utils::Money & nextHitMaxTriggerValue);

    /**
     */
    const utils::Money & getNextHitMaxTriggerValue() const;

    /**
     */
    void setNextHitMinBetAmount(const utils::Money & nextHitMinBetAmount);

    /**
     */
    const utils::Money & getNextHitMinBetAmount() const;

    /**
     */
    void setNextHitMaxBetAmount(const utils::Money & nextHitMaxBetAmount);

    /**
     */
    const utils::Money & getNextHitMaxBetAmount() const;

    /**
     */
    void setNextHitMinPlayedGames(const uint32_t nextHitMinPlayedGames);

    /**
     */
    const uint32_t & getNextHitMinPlayedGames() const;

    /**
     */
    void setNextHitMaxPlayedGames(const uint32_t nextHitMaxPlayedGames);

    /**
     */
    const uint32_t & getNextHitMaxPlayedGames() const;

    /**
     */
    void setNextHitStartTime(const uint32_t nextHitStartTime);

    /**
     */
    const uint32_t & getNextHitStartTime() const;

    /**
     */
    void setNextHitEndTime(const uint32_t nextHitEndTime);

    /**
     */
    const uint32_t & getNextHitEndTime() const;

    /**
     */
    void setNextHitWeekDays(const uint8_t nextWeekDays);

    /**
     */
    const uint8_t & getNextHitWeekDays() const;

    /**
     */
    void setNextHitMonths(const uint16_t nextMonths);

    /**
     */
    const uint16_t & getNextHitMonths() const;

    /**
     */
    void setNextHitMinDeductionAmount(const utils::Money & nextHitMinDeductionAmount);

    /**
     */
    const utils::Money & getNextHitMinDeductionAmount() const;

    /**
     */
    void setNextHitMaxDeductionAmount(const utils::Money & nextHitMinDeductionAmount);

    /**
     */
    const utils::Money & getNextHitMaxDeductionAmount() const;

    /**
     */
    void setNextMinBetToWin(const utils::Money & nextMinBetToWin);

    /**
     */
    const utils::Money & getNextMinBetToWin() const;

    /**
     */
    void setNextActiveStartTime(const uint32_t nextActiveStartTime);

    /**
     */
    const uint32_t & getNextActiveStartTime() const;

    /**
     */
    void setNextActiveEndTime(const uint32_t nextActiveEndTime);

    /**
     */
    const uint32_t & getNextActiveEndTime() const;

    /**
     */
    void setNextActiveWeekDays(const uint8_t nextActiveWeekDays);

    /**
     */
    const uint8_t & getNextActiveWeekDays() const;

    /**
     */
    void setNextActiveMonths(const uint16_t nextActiveMonths);

    /**
     */
    const uint16_t & getNextActiveMonths() const;

    /**
     */
    void setNextMinMachinesNumber(const uint16_t nextMinMachinesNumber);

    /**
     */
    const uint16_t & getNextMinMachinesNumber() const;

    /**
     */
    void setNextMinMachinesPeriod(const uint16_t nextMinMachinesPeriod);

    /**
     */
    const uint16_t & getNextMinMachinesPeriod() const;

    /**
     */
    void setNextMaxNumberOfHits(const uint16_t nextMaxNumberOfHits);

    /**
     */
    const uint16_t & getNextMaxNumberOfHits() const;

    /**
     */
    void setNextMinActiveBet(const utils::Money & nextMinActiveBet);

    /**
     */
    const utils::Money & getNextMinActiveBet() const;

    /**
     */
    void setNextMaxActiveBet(const utils::Money & nextMaxActiveBet);

    /**
     */
    const utils::Money & getNextMaxActiveBet() const;


public:
    /**
     */
    void setLastActivationTime(uint32_t activationTime);

    /**
     */
    const uint32_t & getLastActivationTime() const;

    /**
     */
    void setLastDeactivationTime(uint32_t deactivationTime);

    /**
     */
    const uint32_t & getLastDeactivationTime() const;

    /**
     */
    void setLastChangeTime(uint32_t changeTime);

    /**
     */
    const uint32_t & getLastChangeTime() const;

    /**
     */
    void setTimesWon(uint32_t timesWon);

    /**
     */
    const uint32_t & getTimesWon() const;

    /**
     */
    void setTotalWon(uint64_t totalWon);

    /**
     */
    const uint64_t & getTotalWon() const;

    /**
     */
    void setTotalDeduction(const utils::Money & totalDeduction);

    /**
     */
    const utils::Money & getTotalDeduction() const;

    /**
     */
    void setPartialDeduction(const utils::Money & partialDeduction);

    /**
     */
    const utils::Money & getPartialDeduction() const;

    /**
     */
    void setTotalBetsNumber(uint32_t betsNumber);

    /**
     */
    const uint32_t & getTotalBetsNumber() const;

    /**
     */
    void setPartialBetsNumber(uint32_t partialBetsNumber);

    /**
     */
    const uint32_t & getPartialBetsNumber() const;

    /**
     */
    void setTotalBet(uint64_t totalBet);

    /**
     */
    const uint64_t & getTotalBet() const;

    /**
     */
    void setPartialBet(uint32_t partialBet);

    /**
     */
    const uint32_t & getPartialBet() const;

    /**
     */
    void setMinWin(const utils::Money & minWin);

    /**
     */
    const utils::Money & getMinWin() const;

    /**
     */
    void setMaxWin(const utils::Money & maxWin);

    /**
     */
    const utils::Money & getMaxWin() const;

    /**
     */
    void setTotalHiddenAddition(const utils::Money & totalHiddenAddition);

    /**
     */
    const utils::Money & getTotalHiddenAddition() const;
public:
    /**
     */
    void setLocked(bool locked);

    /**
     */
    const bool isLocked() const;

    /**
     */
    void setOnFocus(bool onFocus);

    /**
     */
    const bool isOnFocus() const;

    /**
     */
    const std::string toString() const;


protected:
    /**
     */
    LevelType type;

    /**
     */
    uint32_t internalId;

    /**
     */
    uint32_t externalId;

    /**
     */
    uint32_t sessionId;

    /**
     */
    int16_t denomIndex;

protected:
    /**
     */
    bool applyNextSettings;

    /**
     */
    LevelStatus status;

    /**
     */
    utils::Money baseValue;

    /**
     */
    utils::Money visibleValue;

    /**
     */
    utils::Money visibleLimitValue;

    /**
     */
    utils::Percent visibleDeductionPercentage;

    /**
     */
    uint8_t useVisibleMiddleValue;

    /**
     */
    utils::Money visibleMiddleValue;

    /**
     */
    utils::Percent visibleMiddlePercentage;

    /**
     */
    utils::Money hiddenValue;

    /**
     */
    utils::Percent hiddenDeductionPercentage;

    /**
     */
    utils::Money hiddenValueAdd;

    /**
     */
	bool automaticOverflow;

    /**
     */
	utils::Money overflowValue;

    /**
     */
	utils::Percent overflowDeductionPercentage;

    /**
     */
	utils::Money reserveValue;

    /**
     */
	utils::Money reserveLimitValue;

    /**
     */
	utils::Percent reserveDeductionPercentage;

	/**
     */
    utils::Money minBaseValue;

    /**
     */
    utils::Money maxBaseValue;

    /**
     */
    utils::Money hitMinTriggerValue;

    /**
     */
    utils::Money hitMaxTriggerValue;

    /**
     */
    utils::Money hitTriggerValue;

    /**
     */
    utils::Money hitMinBetAmount;

    /**
     */
    utils::Money hitMaxBetAmount;

    /**
     */
    utils::Money hitBetAmount;

    /**
     */
    uint32_t hitMinPlayedGames;

    /**
     */
    uint32_t hitMaxPlayedGames;

    /**
     */
    uint32_t hitPlayedGames;

    /**
     */
    uint32_t hitStartTime;

    /**
     */
    uint32_t hitEndTime;

    /**
     */
    uint32_t hitTime;

    /**
     */
    uint8_t hitWeekDays;

    /**
     */
    uint16_t hitMonths;

    /**
     */
    utils::Money hitMinDeductionAmount;

    /**
     */
    utils::Money hitMaxDeductionAmount;

    /**
     */
    utils::Money hitDeductionAmount;

    /**
     */
    utils::Money minBetToWin;

    /**
     */
    uint32_t activeStartTime;

    /**
     */
    uint32_t activeEndTime;

    /**
     */
    uint8_t activeWeekDays;

    /**
     */
    uint16_t activeMonths;

    /**
     */
    uint16_t minMachinesNumber;

    /**
     */
    uint16_t minMachinesPeriod;

    /**
     */
    uint16_t maxNumberOfHits;

    /**
     */
    utils::Money minActiveBet;

    /**
     */
    utils::Money maxActiveBet;

protected:
    /**
     */
    LevelStatus nextStatus;

    /**
     */
    utils::Money nextBaseValue;

    /**
     */
    utils::Money nextVisibleValue;

    /**
     */
    utils::Money nextVisibleLimitValue;

    /**
     */
    utils::Percent nextVisibleDeductionPercentage;

    /**
     */
    uint8_t nextUseVisibleMiddleValue;

    /**
     */
    utils::Money nextVisibleMiddleValue;

    /**
     */
    utils::Percent nextVisibleMiddlePercentage;

    /**
     */
    utils::Money nextHiddenValue;

    /**
     */
    utils::Percent nextHiddenDeductionPercentage;

    /**
     */
    utils::Money nextHiddenValueAdd;

    /**
     */
    utils::Money nextOverflowValue;

    /**
     */
    utils::Percent nextOverflowDeductionPercentage;

    /**
     */
    utils::Money nextReserveValue;

    /**
     */
    utils::Money nextReserveLimitValue;

    /**
     */
    utils::Percent nextReserveDeductionPercentage;

    /**
     */
    utils::Money nextMinBaseValue;

    /**
     */
    utils::Money nextMaxBaseValue;

    /**
     */
    utils::Money nextHitMinTriggerValue;

    /**
     */
    utils::Money nextHitMaxTriggerValue;

    /**
     */
    utils::Money nextHitMinBetAmount;

    /**
     */
    utils::Money nextHitMaxBetAmount;

    /**
     */
    uint32_t nextHitMinPlayedGames;

    /**
     */
    uint32_t nextHitMaxPlayedGames;

    /**
     */
    uint32_t nextHitStartTime;

    /**
     */
    uint32_t nextHitEndTime;

    /**
     */
    uint8_t nextHitWeekDays;

    /**
     */
    uint16_t nextHitMonths;

    /**
     */
    utils::Money nextHitMinDeductionAmount;

    /**
     */
    utils::Money nextHitMaxDeductionAmount;

    /**
     */
    utils::Money nextMinBetToWin;

    /**
     */
    uint32_t nextActiveStartTime;

    /**
     */
    uint32_t nextActiveEndTime;

    /**
     */
    uint8_t nextActiveWeekDays;

    /**
     */
    uint16_t nextActiveMonths;

    /**
     */
    uint16_t nextMinMachinesNumber;

    /**
     */
    uint16_t nextMinMachinesPeriod;

    /**
     */
    uint16_t nextMaxNumberOfHits;

    /**
     */
    utils::Money nextMinActiveBet;

    /**
     */
    utils::Money nextMaxActiveBet;

protected:
    /**
     */
    uint32_t lastActivationTime;

    /**
     */
    uint32_t lastDeactivationTime;

    /**
     */
    uint32_t lastChangeTime;

    /**
     */
    uint32_t timesWon;

    /**
     */
    uint64_t totalWon;

    /**
     */
    utils::Money totalDeduction;

    /**
     */
    utils::Money partialDeduction;

    /**
     */
    uint32_t totalBetsNumber;

    /**
     */
    uint32_t partialBetsNumber;

    /**
     */
    uint64_t totalBet;

    /**
     */
    uint32_t partialBet;

    /**
     */
    utils::Money minWin;

    /**
     */
    utils::Money maxWin;

    /**
     */
    utils::Money totalHiddentAddition;

protected:
    /**
     */
    bool locked;

    /**
     */
    bool onFocus;
};

/**
 */
typedef std::map <unsigned int, std::shared_ptr <ProgressiveLevel> >
        ProgressiveLevelsList;

#endif // PROGRESSIVE_LEVEL_H
