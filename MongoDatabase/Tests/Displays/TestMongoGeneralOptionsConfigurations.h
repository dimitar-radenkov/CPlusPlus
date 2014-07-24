/*
 * TestMongoGeneralOptionsConfigurations.h
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#ifndef TESTMONGOGENERALOPTIONSCONFIGURATIONS_H_
#define TESTMONGOGENERALOPTIONSCONFIGURATIONS_H_

#include "Settings/Displays/GeneralOptionsConfiguration.h"
#include "Database/DBClient/DBClient.h"
#include "Database/DBClient/MongoClient/MongoClient.h"
#include "Database/Driver/MongoDriver.h"

namespace test
{

class TestMongoGeneralOptionsConfigurations
{
private:

    TestMongoGeneralOptionsConfigurations();

    virtual ~TestMongoGeneralOptionsConfigurations();

public:
    static void Run();
};

} /* namespace test */
#endif /* TESTMONGOGENERALOPTIONSCONFIGURATIONS_H_ */
