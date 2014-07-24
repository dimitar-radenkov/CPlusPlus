/*
 * TestMongoMachines.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "TestMongoMachines.h"

namespace test
{

TestMongoMachines::TestMongoMachines()
{
    // TODO Auto-generated constructor stub

}

TestMongoMachines::~TestMongoMachines()
{
    // TODO Auto-generated destructor stub
}

void TestMongoMachines::Run()
{
    std::cout << "checking machines...  " ;

    GameInfo info1;
    info1.denominationId = 1;
    info1.gameId = 1;
    info1.gameVersion = "test Version";
    info1.maxBetPerLine = 1;
    info1.minBetPerLine = 1;
    info1.minNumberOfLines = 1;
    info1.numberOfLines = 1;
    info1.theoreticalPercentage = 1;

    GameInfo info2;
    info2.denominationId = 2;
    info2.gameId = 2;
    info2.gameVersion = "test Version 2";
    info2.maxBetPerLine = 2;
    info2.minBetPerLine = 2;
    info2.minNumberOfLines = 2;
    info2.numberOfLines = 2;
    info2.theoreticalPercentage = 2;

    std::vector<GameInfo> gamesInfoList {info1, info2};

    std::shared_ptr<Machine> machine1(
            new Machine(1,"m1",1,1,gamesInfoList,false));

    std::shared_ptr<Machine> machine2(
            new Machine(2,"m2",2,2,gamesInfoList,true));

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all machines
        dbClient->Machines()->removeAll();


        //add machines
        dbClient->Machines()->add(machine1);
        dbClient->Machines()->add(machine2);

        //remove machines
        dbClient->Machines()->remove(machine1->getSerialNumber());
        dbClient->Machines()->remove(machine2->getSerialNumber());

        //add machine1 again
        dbClient->Machines()->add(machine1);

        //update machine1
        machine1->setName("updated machine1");
        dbClient->Machines()->update(machine1->getSerialNumber(), machine1);

        //check updated machine
        std::shared_ptr<Machine> updatedMachine =
                dbClient->Machines()->get(1);

        if ( !(*machine1 == *updatedMachine) )
        {
            throw utils::CommonException("updated machine differs from original one.");
        }


        //add machine2
        dbClient->Machines()->add(machine2);

        //get all machines
        std::vector<std::shared_ptr<Machine>> machinesList =
            dbClient->Machines()->getAll();

        if (machinesList.size() != 2)
        {
            throw utils::CommonException("Machines must be exact 2.");
        }

        //remove all machines
        dbClient->Machines()->removeAll();

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

}// namespace test

