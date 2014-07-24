/*
 * TestMongoCommonParams.cpp
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#include "TestMongoCommonParams.h"

namespace test
{

TestMongoCommonParams::TestMongoCommonParams()
{

}

TestMongoCommonParams::~TestMongoCommonParams()
{

}

void TestMongoCommonParams::Run()
{
    std::cout << "checking common params...  " ;



    try
    {
        database::MongoDriver::getInstance().connect("localhost");
        std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

        std::shared_ptr<CommonParams> commonParams(
                new CommonParams(1, "1", "1", "1", true, 1));

        std::shared_ptr<CommonParams> commonParams2(
                        new CommonParams(2, "2", "2", "2", false, 2));


        dbClient->CommonParams()->add(commonParams);

        std::shared_ptr<CommonParams>dbParams =
            dbClient->CommonParams()->get();

        if(*commonParams !=  *dbParams)
        {
            throw utils::CommonException("serialize problem found.");
        }

        //try to override params
        dbClient->CommonParams()->add(commonParams2);

        if(*commonParams2 != *dbClient->CommonParams()->get())
        {
            throw utils::CommonException("override common params problem found.");
        }

        //remove
        dbClient->CommonParams()->remove();


        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

} /* namespace test */
