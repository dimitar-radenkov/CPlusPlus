/*
 * TestMongoTextMessagesConfigurations.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "TestMongoTextMessagesConfigurations.h"

namespace test
{

TestMongoTextMessagesConfigurations::TestMongoTextMessagesConfigurations()
{

}

TestMongoTextMessagesConfigurations::~TestMongoTextMessagesConfigurations()
{

}

void TestMongoTextMessagesConfigurations::Run()
{
    std::cout << "checking texts configurations...  " ;

    std::vector<uint16_t> messagesIds1 { 1, 2, 3 };
    std::vector<uint16_t> messagesIds2 { 11, 22, 33 };

    std::shared_ptr<StatusLineTextsConfiguration> textsConfiguration1(
            new StatusLineTextsConfiguration());

    textsConfiguration1->uniqueId = 1;
    textsConfiguration1->messagesIds = messagesIds1;

    std::shared_ptr<StatusLineTextsConfiguration> textsConfiguration2(
                new StatusLineTextsConfiguration());

    textsConfiguration2->uniqueId = 2;
    textsConfiguration2->messagesIds = messagesIds2;

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all text configurations
        dbClient->TextMessagesConfigurations()->removeAll();


        //add text configurations
        dbClient->TextMessagesConfigurations()->add(textsConfiguration1);
        dbClient->TextMessagesConfigurations()->add(textsConfiguration2);

        //remove text configurations
        dbClient->TextMessagesConfigurations()->remove(textsConfiguration1->uniqueId);
        dbClient->TextMessagesConfigurations()->remove(textsConfiguration2->uniqueId);

        //add textMessage1 again
        dbClient->TextMessagesConfigurations()->add(textsConfiguration1);

        //update textMessage1
        textsConfiguration1->messagesIds.push_back(69);
        textsConfiguration1->messagesIds.push_back(6969);
        dbClient->TextMessagesConfigurations()->update(
                textsConfiguration1->uniqueId, textsConfiguration1);

        //check updated StatusLineTextsConfiguration
        std::shared_ptr<StatusLineTextsConfiguration> updatedTextConfigurations =
                dbClient->TextMessagesConfigurations()->get(textsConfiguration1->uniqueId);

        if ( !(*textsConfiguration1 == *updatedTextConfigurations) )
        {
            throw utils::CommonException("updated textMessage differs from original one.");
        }

        //add textsConfiguration2
        dbClient->TextMessagesConfigurations()->add(textsConfiguration2);

        //get all text configurations
        std::vector<std::shared_ptr<StatusLineTextsConfiguration>> textsConfigurationsList =
            dbClient->TextMessagesConfigurations()->getAll();

        if (textsConfigurationsList.size() != 2)
        {
            throw utils::CommonException("Text configurations must be exact 2.");
        }

        //remove all text configuration
        dbClient->TextMessagesConfigurations()->removeAll();

        if (dbClient->TextMessagesConfigurations()->getAll().size() != 0)
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
