/*
 * TestMongoMachinesGroups.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "TestMongoMachinesGroups.h"

namespace test {

TestMongoMachinesGroups::TestMongoMachinesGroups()
{
    // TODO Auto-generated constructor stub

}

TestMongoMachinesGroups::~TestMongoMachinesGroups()
{
    // TODO Auto-generated destructor stub
}

void TestMongoMachinesGroups::Run()
{
    std::cout << "checking machines groups...  " ;

    std::shared_ptr<MachinesGroup> machineGroup1(
        new MachinesGroup(1,1,1,"mg1"));

    std::shared_ptr<MachinesGroup> machineGroup2(
            new MachinesGroup(2,2,2,"mg2"));

    machineGroup1->addMachine(1);

    machineGroup2->addMachine(1);
    machineGroup2->addMachine(2);

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all machines groups
        dbClient->MachinesGroups()->removeAll();

        //add machines groups
        dbClient->MachinesGroups()->add(machineGroup1);
        dbClient->MachinesGroups()->add(machineGroup2);

        //remove machines groups
        dbClient->MachinesGroups()->remove(machineGroup1->getId());
        dbClient->MachinesGroups()->remove(machineGroup2->getId());

        //add machines group1 again
        dbClient->MachinesGroups()->add(machineGroup1);

        //update machine1
        machineGroup1->setName("updated machine group1");
        dbClient->MachinesGroups()->update(machineGroup1->getId(), machineGroup1);

        //check updated machine
        std::shared_ptr<MachinesGroup> updatedMachinesGroup =
                dbClient->MachinesGroups()->get(1);

        if ( !(*machineGroup1 == *updatedMachinesGroup) )
        {
            throw utils::CommonException(
                    "updated machines group differs from original one.");
        }

        //add machine2
        dbClient->MachinesGroups()->add(machineGroup2);

        //get all machines
        std::vector<std::shared_ptr<MachinesGroup>> machinesGroupsList =
            dbClient->MachinesGroups()->getAll();

        if (machinesGroupsList.size() != 2)
        {
            throw utils::CommonException("Machines groups must be exact 2.");
        }

        //remove all machines
        dbClient->MachinesGroups()->removeAll();

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

} /* namespace test */
