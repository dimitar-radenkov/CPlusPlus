/*
 * TestMongoTextMessages.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef TESTMONGOTEXTMESSAGES_H_
#define TESTMONGOTEXTMESSAGES_H_

#include "Settings/Displays/StatusLineText.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoTextMessages
{
private:

    TestMongoTextMessages();

    virtual ~TestMongoTextMessages();

public:
    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOTEXTMESSAGES_H_ */
