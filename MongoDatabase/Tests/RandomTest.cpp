/*
 * RandomTest.cpp
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#include "RandomTest.h"

namespace test
{

RandomTest::RandomTest()
{
    // TODO Auto-generated constructor stub
}

RandomTest::~RandomTest()
{
    // TODO Auto-generated destructor stub
}

void RandomTest::Run()
{
    std::shared_ptr<Display> display1(
        new Display(1,1,1,1,1,1,true));

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        for(int a = 1 ; a <= 10000 ; ++a)
        {
            dbClient->Displays()->add(display1);
        }
    }
    catch(mongo::DBException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

}/*namespace test*/
