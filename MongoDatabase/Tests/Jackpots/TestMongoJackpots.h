/*
 * TestMongoJackpots.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef TESTMONGOJACKPOTS_H_
#define TESTMONGOJACKPOTS_H_

#include <memory>

#include "Settings/Jackpots/Jackpot.h"
#include "Settings/Jackpots/Definitions/JackpotType.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoJackpots
{
private:
    TestMongoJackpots();
    virtual ~TestMongoJackpots();

public:
    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOJACKPOTS_H_ */
