/*
 * TestMongoLevels.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef TESTMONGOLEVELS_H_
#define TESTMONGOLEVELS_H_

#include <memory>

#include "Settings/Jackpots/ProgressiveLevel.h"
#include "Settings/Jackpots/Definitions/LevelType.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"


namespace test
{

class TestMongoLevels
{
private:
    TestMongoLevels();
    virtual ~TestMongoLevels();

public:
    void static Run();
};

} /* namespace test */
#endif /* TESTMONGOLEVELS_H_ */
