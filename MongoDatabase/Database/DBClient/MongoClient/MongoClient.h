/*
 * MongoClient.h
 *
 *  Created on: May 12, 2014
 *      Author: root
 */

#ifndef MONGOCLIENT_H_
#define MONGOCLIENT_H_

#include "Database/DBClient/DBClient.h"
#include "Database/Settings/Mongo/Machines/MongoMachines.h"
#include "Database/Settings/Mongo/Machines/MongoMachinesGroups.h"

#include "Database/Settings/Mongo/Jackpots/MongoLevels.h"
#include "Database/Settings/Mongo/Jackpots/MongoMultilevels.h"
#include "Database/Settings/Mongo/Jackpots/MongoJackpots.h"

#include "Database/Settings/Mongo/Displays/MongoDisplays.h"
#include "Database/Settings/Mongo/Displays/MongoTextMessages.h"
#include "Database/Settings/Mongo/Displays/MongoTextMessagesConfigurations.h"
#include "Database/Settings/Mongo/Displays/MongoGeneralOptionsConfigurations.h"
#include "Database/Settings/Mongo/Displays/MongoScenarioScreensConfigurations.h"
#include "Database/Settings/Mongo/Displays/MongoPriorityScreensConfigurations.h"
#include "Database/Settings/Mongo/Displays/MongoScenarioScreens.h"
#include "Database/Settings/Mongo/Displays/MongoPriorityScreens.h"

#include "Database/Settings/Mongo/Common/MongoCommonParams.h"

namespace database
{

class MongoClient : public DBClient
{

public:

	MongoClient();

	virtual ~MongoClient();
};

}

#endif /* MONGOCLIENT_H_ */
