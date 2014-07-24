/*
 * TestMongoMultilevels.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef TESTMONGOMULTILEVELS_H_
#define TESTMONGOMULTILEVELS_H_

#include <memory>

#include "Settings/Jackpots/ProgressiveMultilevel.h"
#include "Settings/Jackpots/Definitions/MultilevelType.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoMultilevels
{
private:
    TestMongoMultilevels();

    virtual ~TestMongoMultilevels();

public:
    void static Run();
};

} /* namespace test */
#endif /* TESTMONGOMULTILEVELS_H_ */
