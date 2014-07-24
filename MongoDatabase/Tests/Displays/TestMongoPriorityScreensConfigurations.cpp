/*
 * TestMongoPriorityScreensConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "TestMongoPriorityScreensConfigurations.h"

namespace test
{

TestMongoPriorityScreensConfigurations::TestMongoPriorityScreensConfigurations()
{

}

TestMongoPriorityScreensConfigurations::~TestMongoPriorityScreensConfigurations()
{

}

void TestMongoPriorityScreensConfigurations::Run()
{
    std::cout << "checking priority screens configurations...  " ;

    std::vector<uint16_t> screensIds {1,2,3,4};

    std::shared_ptr<PriorityScreensConfiguration> configuration1(
            new PriorityScreensConfiguration() );

    configuration1->configurationId = 1;
    configuration1->screensIds = screensIds;

    std::shared_ptr<PriorityScreensConfiguration> configuration2(
            new PriorityScreensConfiguration() );

    configuration2->configurationId = 2;

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient ( new database::MongoClient );

    try
    {
        //remove all configurations
        dbClient->PriorityScreensConfigurations()->removeAll();


        //add configurations
        dbClient->PriorityScreensConfigurations()->add(configuration1);
        dbClient->PriorityScreensConfigurations()->add(configuration2);

        //remove configurations
        dbClient->PriorityScreensConfigurations()->remove(configuration1->configurationId);
        dbClient->PriorityScreensConfigurations()->remove(configuration2->configurationId);

        //add configuration1 again
        dbClient->PriorityScreensConfigurations()->add(configuration1);

        //update configuration1
        configuration1->screensIds.push_back(69);
        configuration1->screensIds.push_back(79);
        dbClient->PriorityScreensConfigurations()->update(
            configuration1->configurationId, configuration1);

        //check updated configuration
        std::shared_ptr<PriorityScreensConfiguration> updatedConfiguration =
            dbClient->PriorityScreensConfigurations()->get(configuration1->configurationId);

        if ( !(*configuration1 == *updatedConfiguration) )
        {
            throw utils::CommonException("updated configuration differs from original one.");
        }

        //add configuration2
        dbClient->PriorityScreensConfigurations()->add(configuration2);

        //get all configurations
        std::vector<std::shared_ptr<PriorityScreensConfiguration>> configurationsList =
            dbClient->PriorityScreensConfigurations()->getAll();

        if (configurationsList.size() != 2)
        {
            throw utils::CommonException("Configurations must be exact 2.");
        }

        //remove all configuration
        dbClient->PriorityScreensConfigurations()->removeAll();

        if (dbClient->PriorityScreensConfigurations()->getAll().size() != 0)
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
