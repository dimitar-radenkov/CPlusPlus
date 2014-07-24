/*
 * RandomTest.h
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#ifndef RANDOMTEST_H_
#define RANDOMTEST_H_

#include <memory>
#include <string>

#include "mongo/client/dbclient.h"
#include "Utils/CommonException.h"
#include "Database/Driver/MongoDriver.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"


namespace test
{

class RandomTest
{

private:
    RandomTest();

    virtual ~RandomTest();

public:

    static void Run();
};

}/*namespace test*/

#endif /* RANDOMTEST_H_ */
