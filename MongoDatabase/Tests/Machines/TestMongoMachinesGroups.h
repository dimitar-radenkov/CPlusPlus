/*
 *  TestMongoMachinesGroups.h
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#ifndef TESTMONGOMACHINESGROUPS_H_
#define TESTMONGOMACHINESGROUPS_H_

#include <memory>

#include "Settings/Machines/MachinesGroup.h"

#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoMachinesGroups
{
private:
    TestMongoMachinesGroups();
    virtual ~TestMongoMachinesGroups();

public:

    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOMACHINESGROUPS_H_ */
