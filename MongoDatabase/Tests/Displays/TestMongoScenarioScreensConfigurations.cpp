/*
 * TestMongoScenarioScreensConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "TestMongoScenarioScreensConfigurations.h"

namespace test
{

TestMongoScenarioScreensConfigurations::TestMongoScenarioScreensConfigurations()
{

}

TestMongoScenarioScreensConfigurations::~TestMongoScenarioScreensConfigurations()
{

}

void TestMongoScenarioScreensConfigurations::Run()
{
    std::cout << "checking scenario screens configurations...  " ;

    std::vector<uint16_t> screensIds {1,2,3,4};

    std::shared_ptr<ScenarioScreensConfiguration> configuration1(
            new ScenarioScreensConfiguration() );

    configuration1->configurationId = 1;
    configuration1->screensIds = screensIds;

    std::shared_ptr<ScenarioScreensConfiguration> configuration2(
            new ScenarioScreensConfiguration() );

    configuration2->configurationId = 2;

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient ( new database::MongoClient );

    try
    {
        //remove all configurations
        dbClient->ScenarioScreensConfigurations()->removeAll();


        //add configurations
        dbClient->ScenarioScreensConfigurations()->add(configuration1);
        dbClient->ScenarioScreensConfigurations()->add(configuration2);

        //remove configurations
        dbClient->ScenarioScreensConfigurations()->remove(configuration1->configurationId);
        dbClient->ScenarioScreensConfigurations()->remove(configuration2->configurationId);

        //add configuration1 again
        dbClient->ScenarioScreensConfigurations()->add(configuration1);

        //update configuration1
        configuration1->screensIds.push_back(69);
        configuration1->screensIds.push_back(79);
        dbClient->ScenarioScreensConfigurations()->update(
                configuration1->configurationId, configuration1);

        //check updated configuration
        std::shared_ptr<ScenarioScreensConfiguration> updatedConfiguration =
            dbClient->ScenarioScreensConfigurations()->get(configuration1->configurationId);

        if ( !(*configuration1 == *updatedConfiguration) )
        {
            throw utils::CommonException("updated configuration differs from original one.");
        }

        //add configuration2
        dbClient->ScenarioScreensConfigurations()->add(configuration2);

        //get all configurations
        std::vector<std::shared_ptr<ScenarioScreensConfiguration>> configurationsList =
            dbClient->ScenarioScreensConfigurations()->getAll();

        if (configurationsList.size() != 2)
        {
            throw utils::CommonException("Configurations must be exact 2.");
        }

        //remove all configuration
        dbClient->ScenarioScreensConfigurations()->removeAll();

        if (dbClient->ScenarioScreensConfigurations()->getAll().size() != 0)
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

} /* namespace database */
