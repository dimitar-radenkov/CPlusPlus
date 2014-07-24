/*
 * DBClient.cpp
 *
 *  Created on: May 12, 2014
 *      Author: root
 */

#include "DBClient.h"

namespace database
{

DBClient::DBClient()
{
	this->type = DBClientType::Unknown;
}

DBClient::~DBClient()
{

}

DBClientType DBClient::getType() const
{
	return this->type;
}

/*Machines*/
std::shared_ptr<IMachinesQueryable> DBClient::Machines() const
{
	return this->machines;
}

std::shared_ptr<IMachinesGroupsQueryable> DBClient::MachinesGroups() const
{
	return this->machinesGroups;
}


/*Jackpots*/
std::shared_ptr<ILevelsQueryable> DBClient::Levels() const
{
    return this->levels;
}

std::shared_ptr<IMultilevelsQueryable> DBClient::Multilevels() const
{
    return this->multilevels;
}

std::shared_ptr<IJackpotsQueryable> DBClient::Jackpots() const
{
    return this->jackpots;
}


/*Displays*/
std::shared_ptr<IDisplaysQueryable> DBClient::Displays() const
{
    return this->displays;
}

std::shared_ptr<ITextMessagesQueryable> DBClient::TextMessages() const
{
    return this->textMessages;
}

std::shared_ptr<ITextMessagesConfigurationsQueryable> DBClient::TextMessagesConfigurations() const
{
    return this->textMessagesConfigurations;
}

std::shared_ptr<IGeneralOptionsConfigurationsQueryable> DBClient::GeneralOptionsConfigurations() const
{
    return this->generalOptionsConfigurations;
}

std::shared_ptr<IScenarioScreensConfigurationsQueryable> DBClient::ScenarioScreensConfigurations() const
{
    return this->scenarioScreensConfigurations;
}

std::shared_ptr<IPriorityScreensConfigurationsQueryable> DBClient::PriorityScreensConfigurations() const
{
    return this->priorityScreensConfigurations;
}

std::shared_ptr<IScenarioScreensQueryable> DBClient::ScenarioScreens() const
{
    return this->scenarioScreens;
}

std::shared_ptr<IPriorityScreensQueryable> DBClient::PriorityScreens() const
{
    return this->priorityScreens;
}

std::shared_ptr<ICommonParamsQueryable> DBClient::CommonParams() const
{
    return this->commonParams;
}

}
