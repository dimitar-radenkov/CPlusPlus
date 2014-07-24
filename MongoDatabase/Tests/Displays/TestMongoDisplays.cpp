/*
 * TestMongoDisplays.cpp
 *
 *  Created on: May 23, 2014
 *      Author: root
 */

#include "TestMongoDisplays.h"

namespace test
{

TestMongoDisplays::TestMongoDisplays()
{
    // TODO Auto-generated constructor stub

}

TestMongoDisplays::~TestMongoDisplays()
{
    // TODO Auto-generated destructor stub
}

void TestMongoDisplays::Run()
{
    std::cout << "checking displays...  " ;

    std::shared_ptr<Display> display1(
            new Display(1,1,1,1,1,1,true));

    std::shared_ptr<Display> display2(
                new Display(2,2,2,2,2,2,true));

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all displays
        dbClient->Displays()->removeAll();


        //add displays
        dbClient->Displays()->add(display1);
        dbClient->Displays()->add(display2);

        //remove displays
        dbClient->Displays()->remove(display1->getSerialNumber());
        dbClient->Displays()->remove(display2->getSerialNumber());

        //add display1 again
        dbClient->Displays()->add(display1);

        //update display1
        display1->setNumberInCasino(11);
        dbClient->Displays()->update(display1->getSerialNumber(), display1);

        //check updated display
        std::shared_ptr<Display> updatedDisplay =
                dbClient->Displays()->get(display1->getSerialNumber());

        if ( !(*display1 == *updatedDisplay) )
        {
            throw utils::CommonException("updated display differs from original one.");
        }

        //add display2
        dbClient->Displays()->add(display2);

        //get all displays
        std::vector<std::shared_ptr<Display>> displaysList =
            dbClient->Displays()->getAll();

        if (displaysList.size() != 2)
        {
            throw utils::CommonException("Displays must be exact 2.");
        }

        //remove all displays
        dbClient->Displays()->removeAll();

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

}/*namespace test*/

