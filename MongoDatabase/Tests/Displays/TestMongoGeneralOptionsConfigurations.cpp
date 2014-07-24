/*
 * TestMongoGeneralOptionsConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "TestMongoGeneralOptionsConfigurations.h"

namespace test
{

TestMongoGeneralOptionsConfigurations::TestMongoGeneralOptionsConfigurations()
{

}

TestMongoGeneralOptionsConfigurations::~TestMongoGeneralOptionsConfigurations()
{

}

void TestMongoGeneralOptionsConfigurations::Run()
{
    std::cout << "checking general options configurations...  " ;

    std::shared_ptr<GeneralOptionsConfiguration> configuration1(
            new GeneralOptionsConfiguration(1, 1, 1, 1, 1, "BGN", 1) );

    std::shared_ptr<GeneralOptionsConfiguration> configuration2(
                new GeneralOptionsConfiguration(2, 2, 2, 2, 2, "EUR", 2) );

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient ( new database::MongoClient );

    try
    {
        //remove all configurations
        dbClient->GeneralOptionsConfigurations()->removeAll();


        //add configurations
        dbClient->GeneralOptionsConfigurations()->add(configuration1);
        dbClient->GeneralOptionsConfigurations()->add(configuration2);

        //remove configurations
        dbClient->GeneralOptionsConfigurations()->remove(configuration1->configurationId);
        dbClient->GeneralOptionsConfigurations()->remove(configuration2->configurationId);

        //add configuration1 again
        dbClient->GeneralOptionsConfigurations()->add(configuration1);

        //update configuration1
        configuration1->currencyCode = "Update";
        dbClient->GeneralOptionsConfigurations()->update(
                configuration1->configurationId, configuration1);

        //check updated configuration
        std::shared_ptr<GeneralOptionsConfiguration> updatedConfiguration =
            dbClient->GeneralOptionsConfigurations()->get(configuration1->configurationId);

        if ( !(*configuration1 == *updatedConfiguration) )
        {
            throw utils::CommonException("updated configuration differs from original one.");
        }

        //add configuration2
        dbClient->GeneralOptionsConfigurations()->add(configuration2);

        //get all configurations
        std::vector<std::shared_ptr<GeneralOptionsConfiguration>> configurationsList =
            dbClient->GeneralOptionsConfigurations()->getAll();

        if (configurationsList.size() != 2)
        {
            throw utils::CommonException("Configurations must be exact 2.");
        }

        //remove all configuration
        dbClient->GeneralOptionsConfigurations()->removeAll();

        if (dbClient->GeneralOptionsConfigurations()->getAll().size() != 0)
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
