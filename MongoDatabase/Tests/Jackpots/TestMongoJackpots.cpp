/*
 * TestMongoJackpots.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "TestMongoJackpots.h"

namespace test {

TestMongoJackpots::TestMongoJackpots()
{
    // TODO Auto-generated constructor stub
}

TestMongoJackpots::~TestMongoJackpots()
{
    // TODO Auto-generated destructor stub
}

void TestMongoJackpots::Run()
{
    std::cout << "checking jackpots...  " ;

    std::shared_ptr<Jackpot> jackpot1(
        new Jackpot(
                JackpotType::NoneSASProgressiveJackpot,
                1,
                "jackpot1",
                1,
                ProtocolType::Unknown,
                1,
                1,
                1,
                1,
                1,
                1));

    std::shared_ptr<Jackpot> jackpot2(
        new Jackpot(
                JackpotType::NoneSASProgressiveJackpot,
                2,
                "jackpot2",
                2,
                ProtocolType::Unknown,
                2,
                2,
                2,
                2,
                2,
                2));

    jackpot2->addMultilevel(1,1);
    jackpot2->addMultilevel(2,2);

    jackpot2->attachMachinesGroup(1);
    jackpot2->attachMachinesGroup(2);

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all jackpots
        dbClient->Jackpots()->removeAll();

        //add jackpots
        dbClient->Jackpots()->add(jackpot1);
        dbClient->Jackpots()->add(jackpot2);

        //remove jackpots
        dbClient->Jackpots()->remove(jackpot1->getInternalId());
        dbClient->Jackpots()->remove(jackpot2->getInternalId());

        //add jackpot1 again
        dbClient->Jackpots()->add(jackpot1);

        //update level1
        jackpot1->setName("updated name");
        dbClient->Jackpots()->update(jackpot1->getInternalId(), jackpot1);

        //check updated jackpot
        std::shared_ptr<Jackpot> updatedJackpot =
                dbClient->Jackpots()->get(jackpot1->getInternalId());

        if ( !(*jackpot1 == *updatedJackpot) )
        {
            throw utils::CommonException(
                    "updated jackpot differs from original one.");
        }

        //add jackpot2
        dbClient->Jackpots()->add(jackpot2);

        //get all jackpots
        std::vector<std::shared_ptr<Jackpot>> jackpotsList =
            dbClient->Jackpots()->getAll();

        if (jackpotsList.size() != 2)
        {
            throw utils::CommonException("jackpots count must be exact 2.");
        }

        //remove all levels
        dbClient->Jackpots()->removeAll();

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

} /* namespace test */
