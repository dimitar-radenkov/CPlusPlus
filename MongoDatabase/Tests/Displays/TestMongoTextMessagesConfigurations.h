/*
 * TestMongoTextMessagesConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef TESTMONGOTEXTMESSAGESCONFIGURATIONS_H_
#define TESTMONGOTEXTMESSAGESCONFIGURATIONS_H_

#include "Settings/Displays/StatusLineTextsConfiguration.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoTextMessagesConfigurations
{
private:

    TestMongoTextMessagesConfigurations();

    virtual ~TestMongoTextMessagesConfigurations();

public:

    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOTEXTMESSAGESCONFIGURATIONS_H_ */
