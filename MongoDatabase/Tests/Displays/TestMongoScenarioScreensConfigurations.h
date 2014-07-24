/*
 * TestMongoScenarioScreensConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef TESTMONGOSCENARIOSCREENSCONFIGURATIONS_H_
#define TESTMONGOSCENARIOSCREENSCONFIGURATIONS_H_

#include "Settings/Displays/ScenarioScreensConfiguration.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoScenarioScreensConfigurations
{

private:

    TestMongoScenarioScreensConfigurations();

    virtual ~TestMongoScenarioScreensConfigurations();

public:

    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOSCENARIOSCREENSCONFIGURATIONS_H_ */
