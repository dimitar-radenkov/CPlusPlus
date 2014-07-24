/*
 * DBClient.h
 *
 *  Created on: May 12, 2014
 *      Author: root
 */

#ifndef DBCLIENT_H_
#define DBCLIENT_H_

#include "Database/DBClient/DBClientType.h"
#include "Database/Settings/Interfaces/IMachinesQueryable.h"
#include "Database/Settings/Interfaces/IMachinesGroupsQueryable.h"
#include "Database/Settings/Interfaces/ILevelsQueryable.h"
#include "Database/Settings/Interfaces/IMultilevelsQueryable.h"
#include "Database/Settings/Interfaces/IJackpotsQueryable.h"
#include "Database/Settings/Interfaces/IDisplaysQueryable.h"
#include "Database/Settings/Interfaces/ITextMessagesQueryable.h"
#include "Database/Settings/Interfaces/ITextMessagesConfigurationsQueryable.h"
#include "Database/Settings/Interfaces/IGeneralOptionsConfigurationsQueryable.h"
#include "Database/Settings/Interfaces/IScenarioScreensConfigurationsQueryable.h"
#include "Database/Settings/Interfaces/IPriorityScreensConfigurationsQueryable.h"
#include "Database/Settings/Interfaces/IScenarioScreensQueryable.h"
#include "Database/Settings/Interfaces/IPriorityScreensQueryable.h"
#include "Database/Settings/Interfaces/ICommonParamsQueryable.h"

namespace database
{

class DBClient
{
protected:
	DBClientType type;

	std::shared_ptr<IMachinesQueryable> machines;

	std::shared_ptr<IMachinesGroupsQueryable> machinesGroups;


	std::shared_ptr<ILevelsQueryable> levels;

	std::shared_ptr<IMultilevelsQueryable> multilevels;

	std::shared_ptr<IJackpotsQueryable> jackpots;



	std::shared_ptr<IDisplaysQueryable> displays;

	std::shared_ptr<ITextMessagesQueryable> textMessages;

	std::shared_ptr<ITextMessagesConfigurationsQueryable> textMessagesConfigurations;

	std::shared_ptr<IGeneralOptionsConfigurationsQueryable> generalOptionsConfigurations;

	std::shared_ptr<IScenarioScreensConfigurationsQueryable> scenarioScreensConfigurations;

	std::shared_ptr<IPriorityScreensConfigurationsQueryable> priorityScreensConfigurations;

	std::shared_ptr<IScenarioScreensQueryable> scenarioScreens;

	std::shared_ptr<IPriorityScreensQueryable> priorityScreens;

	/*Common Params*/
	std::shared_ptr<ICommonParamsQueryable> commonParams;

	DBClient();

public:

	virtual ~DBClient();

	virtual DBClientType getType() const;

	/*Machines*/
	std::shared_ptr<IMachinesQueryable> Machines() const;

	std::shared_ptr<IMachinesGroupsQueryable> MachinesGroups() const;


	/*Jackpots*/
	std::shared_ptr<ILevelsQueryable> Levels() const;

	std::shared_ptr<IMultilevelsQueryable> Multilevels() const;

	std::shared_ptr<IJackpotsQueryable> Jackpots() const;


	/*Displays*/
	std::shared_ptr<IDisplaysQueryable> Displays() const;

	std::shared_ptr<ITextMessagesQueryable> TextMessages() const;

	std::shared_ptr<ITextMessagesConfigurationsQueryable> TextMessagesConfigurations() const;

	std::shared_ptr<IGeneralOptionsConfigurationsQueryable> GeneralOptionsConfigurations() const;

	std::shared_ptr<IScenarioScreensConfigurationsQueryable> ScenarioScreensConfigurations() const;

    std::shared_ptr<IScenarioScreensQueryable> ScenarioScreens() const;

	std::shared_ptr<IPriorityScreensConfigurationsQueryable> PriorityScreensConfigurations() const;

	std::shared_ptr<IPriorityScreensQueryable> PriorityScreens() const;

	std::shared_ptr<ICommonParamsQueryable> CommonParams() const;
};

}

#endif /* DBCLIENT_H_ */
