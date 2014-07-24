/*
 * TestMongoScenarioScreens.cpp
 *
 *  Created on: May 27, 2014
 *      Author: root
 */

#include "TestMongoScenarioScreens.h"

namespace test
{

TestMongoScenarioScreens::TestMongoScenarioScreens()
{

}

TestMongoScenarioScreens::~TestMongoScenarioScreens()
{

}

void TestMongoScenarioScreens::Run()
{
    std::cout << "checking scenario screens...  " ;

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
        dbClient->ScenarioScreens()->removeAll();


        //add screens
        dbClient->ScenarioScreens()->add(screen1);
        dbClient->ScenarioScreens()->add(screen2);

        //remove screens
        dbClient->ScenarioScreens()->remove(screen1->uniqueId());
        dbClient->ScenarioScreens()->remove(screen2->uniqueId());

        //add screen11 again
        dbClient->ScenarioScreens()->add(screen1);

        //update screen1
        std::shared_ptr<ScreenDescription> updateScreen1(
            new ScreenDescription(69, (ScreenType)1, "screen69", 69, 69, 69, 69, 69) );
        dbClient->ScenarioScreens()->update(screen1->uniqueId(), updateScreen1);

        //check updated textMessage
        std::shared_ptr<ScreenDescription> gotScreen =
            dbClient->ScenarioScreens()->get(updateScreen1->uniqueId());

        if ( !(*gotScreen == *updateScreen1) )
        {
            throw utils::CommonException("updated screen differs from original one.");
        }

        //add screen2
        dbClient->ScenarioScreens()->add(screen2);

        //get all screens
        std::vector<std::shared_ptr<ScreenDescription>> screensList =
            dbClient->ScenarioScreens()->getAll();

        if (screensList.size() != 2)
        {
            throw utils::CommonException("Scenario screens must be exact 2.");
        }

        //remove all screens
        dbClient->ScenarioScreens()->removeAll();

        if (dbClient->ScenarioScreens()->getAll().size() != 0)
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
