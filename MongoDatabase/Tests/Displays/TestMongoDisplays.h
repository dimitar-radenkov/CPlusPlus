/*
 * TestMongoDisplays.h
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#ifndef TESTMONGODISPLAYS_H_
#define TESTMONGODISPLAYS_H_

#include <memory>

#include "Settings/Displays/Display.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoDisplays
{
private:
    TestMongoDisplays();
    virtual ~TestMongoDisplays();

public:
    static void Run();
};

}/*namespace test*/

#endif /* TESTMONGODISPLAYS_H_ */
