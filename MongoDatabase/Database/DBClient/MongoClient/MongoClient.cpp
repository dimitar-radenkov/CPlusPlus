/*
 * MongoClient.cpp
 *
 *  Created on: May 12, 2014
 *      Author: root
 */

#include "MongoClient.h"

namespace database
{

MongoClient::MongoClient()
{
	//init base class members
	DBClient::type = DBClientType::Mongo;

	DBClient::machines.reset(new MongoMachines);

	DBClient::machinesGroups.reset(new MongoMachinesGroups);


	DBClient::levels.reset(new MongoLevels);

	DBClient::multilevels.reset(new MongoMultilevels);

	DBClient::jackpots.reset(new MongoJackpots);


	DBClient::displays.reset(new MongoDisplays);

	DBClient::textMessages.reset(new MongoTextMessages);

	DBClient::textMessagesConfigurations.reset(new MongoTextMessagesConfigurations);

	DBClient::generalOptionsConfigurations.reset(new MongoGeneralOptionsConfigurations);

	DBClient::scenarioScreensConfigurations.reset(new MongoScenarioScreensConfigurations);

	DBClient::priorityScreensConfigurations.reset(new MongoPriorityScreensConfigurations);

	DBClient::scenarioScreens.reset(new MongoScenarioScreens);

	DBClient::priorityScreens.reset(new MongoPriorityScreens);


	DBClient::commonParams.reset(new MongoCommonParams);
}

MongoClient::~MongoClient()
{

}

} /*namespace database*/

