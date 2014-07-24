/*
 * TestMongoCommonParams.h
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#ifndef TESTMONGOCOMMONPARAMS_H_
#define TESTMONGOCOMMONPARAMS_H_

#include <memory>

#include "Settings/Common/CommonParams.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoCommonParams
{
private:

    TestMongoCommonParams();

    virtual ~TestMongoCommonParams();

public:

    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOCOMMONPARAMS_H_ */
