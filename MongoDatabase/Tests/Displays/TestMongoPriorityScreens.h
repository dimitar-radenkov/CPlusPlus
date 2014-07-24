/*
 * TestMongoPriorityScreens.h
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#ifndef TESTMONGOPRIORITYSCREENS_H_
#define TESTMONGOPRIORITYSCREENS_H_


#include "Settings/Displays/ScreenDescription.h"
#include "Settings/Displays/StatusLineDescription.h"
#include "Settings/Displays/Definitions/StatusLineTextProgramType.h"
#include "Settings/Displays/Definitions/StatusLineType.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoPriorityScreens
{
private:

    TestMongoPriorityScreens();

    virtual ~TestMongoPriorityScreens();

public:
    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOPRIORITYSCREENS_H_ */
