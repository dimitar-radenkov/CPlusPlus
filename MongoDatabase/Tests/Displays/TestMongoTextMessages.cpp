/*
 * TestMongoTextMessages.cpp
 *
 *  Created on: May 26, 2014
 *      Author: root
 */

#include "TestMongoTextMessages.h"

namespace test
{

TestMongoTextMessages::TestMongoTextMessages()
{

}

TestMongoTextMessages::~TestMongoTextMessages()
{

}

void TestMongoTextMessages::Run()
{

    std::cout << "checking texts...  " ;

    std::shared_ptr<StatusLineText> textMessage1(
            new StatusLineText(1, "message1"));

    std::shared_ptr<StatusLineText> textMessage2(
                new StatusLineText(2, "message2"));

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all text messages
        dbClient->TextMessages()->removeAll();


        //add text messages
        dbClient->TextMessages()->add(textMessage1);
        dbClient->TextMessages()->add(textMessage2);

        //remove text messages
        dbClient->TextMessages()->remove(textMessage1->uniqueId);
        dbClient->TextMessages()->remove(textMessage2->uniqueId);

        //add textMessage1 again
        dbClient->TextMessages()->add(textMessage1);

        //update textMessage1
        textMessage1->messageText = "updated message";
        dbClient->TextMessages()->update(textMessage1->uniqueId, textMessage1);

        //check updated textMessage
        std::shared_ptr<StatusLineText> updatedTextMessage =
                dbClient->TextMessages()->get(textMessage1->uniqueId);

        if ( !(*textMessage1 == *updatedTextMessage) )
        {
            throw utils::CommonException("updated textMessage differs from original one.");
        }

        //add textMessage2
        dbClient->TextMessages()->add(textMessage2);

        //get all text messages
        std::vector<std::shared_ptr<StatusLineText>> textMessagesList =
            dbClient->TextMessages()->getAll();

        if (textMessagesList.size() != 2)
        {
            throw utils::CommonException("Text Messages must be exact 2.");
        }

        //remove all text messages
        dbClient->TextMessages()->removeAll();

        if (dbClient->TextMessages()->getAll().size() != 0)
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
