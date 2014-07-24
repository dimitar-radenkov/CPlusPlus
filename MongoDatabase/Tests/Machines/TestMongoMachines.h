/*
 * TestMongoMachines.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef TESTMONGOMACHINES_H_
#define TESTMONGOMACHINES_H_

#include <memory>

#include "Settings/Machines/GameInfo.h"
#include "Settings/Machines/Machine.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test {

class TestMongoMachines {

private:
    TestMongoMachines();
    virtual ~TestMongoMachines();

public:
    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOMACHINES_H_ */

