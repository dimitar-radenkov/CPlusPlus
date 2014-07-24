/*
 * TestMongoPriorityScreens.cpp
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#include "TestMongoPriorityScreens.h"

namespace test
{

TestMongoPriorityScreens::TestMongoPriorityScreens()
{

}

TestMongoPriorityScreens::~TestMongoPriorityScreens()
{

}

void TestMongoPriorityScreens::Run()
{
    std::cout << "checking priority screens...  " ;

    std::shared_ptr<ScreenDescription> screen1(
        new ScreenDescription(1, (ScreenType)1, "screen1", 1, 1, 1, 1, 1) );

    StatusLineDescription statusLine(
            StatusLineType::CustomStatusLineType,
            StatusLineTextProgramType::StaticTextProgramType,
            StatusLineTextProgramType::StaticTextProgramType,
            1,
            1,
            1);

    std::shared_ptr<ScreenDescription> screen2(
        new ScreenDescription(
                2,
                (ScreenType)2,
                "screen2",
                2,
                2,
                2,
                2,
                2,
                statusLine) );

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all screens
        dbClient->PriorityScreens()->removeAll();


        //add screens
        dbClient->PriorityScreens()->add(screen1);
        dbClient->PriorityScreens()->add(screen2);

        //remove screens
        dbClient->PriorityScreens()->remove(screen1->uniqueId());
        dbClient->PriorityScreens()->remove(screen2->uniqueId());

        //add screen11 again
        dbClient->PriorityScreens()->add(screen1);

        //update screen1
        std::shared_ptr<ScreenDescription> updateScreen1(
            new ScreenDescription(69, (ScreenType)1, "screen69", 69, 69, 69, 69, 69) );
        dbClient->PriorityScreens()->update(screen1->uniqueId(), updateScreen1);

        //check updated textMessage
        std::shared_ptr<ScreenDescription> gotScreen =
            dbClient->PriorityScreens()->get(updateScreen1->uniqueId());

        if ( !(*gotScreen == *updateScreen1) )
        {
            throw utils::CommonException("updated screen differs from original one.");
        }

        //add screen2
        dbClient->PriorityScreens()->add(screen2);

        //get all screens
        std::vector<std::shared_ptr<ScreenDescription>> screensList =
            dbClient->PriorityScreens()->getAll();

        if (screensList.size() != 2)
        {
            throw utils::CommonException("Priority screens must be exact 2.");
        }

        //remove all screens
        dbClient->PriorityScreens()->removeAll();

        if (dbClient->PriorityScreens()->getAll().size() != 0)
        {
            throw utils::CommonException("Collection must be empty.");
        }

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

} /* namespace test */
