/*
 * TestMongoPriorityScreensConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef TESTMONGOPRIORITYSCREENSCONFIGURATIONS_H_
#define TESTMONGOPRIORITYSCREENSCONFIGURATIONS_H_

#include "Settings/Displays/PriorityScreensConfiguration.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoPriorityScreensConfigurations
{
private:
    TestMongoPriorityScreensConfigurations();

    virtual ~TestMongoPriorityScreensConfigurations();

public:

    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOPRIORITYSCREENSCONFIGURATIONS_H_ */
