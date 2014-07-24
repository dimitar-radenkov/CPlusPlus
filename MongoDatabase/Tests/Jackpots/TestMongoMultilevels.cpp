/*
 * TestMongoMultilevels.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "TestMongoMultilevels.h"

namespace test
{

TestMongoMultilevels::TestMongoMultilevels()
{
    // TODO Auto-generated constructor stub
}

TestMongoMultilevels::~TestMongoMultilevels()
{
    // TODO Auto-generated destructor stub
}

void TestMongoMultilevels::Run()
{
    std::cout << "checking multilevels...  " ;

    std::shared_ptr<ProgressiveMultilevel> multilevel1(
        new ProgressiveMultilevel(
                MultilevelType::InternalMultilevel,
                1,
                1,
                1,
                1));

    std::shared_ptr<ProgressiveMultilevel> multilevel2(
        new ProgressiveMultilevel(
                MultilevelType::ExternalMultilevel,
                2,
                2,
                2,
                2));

    //change random level params
    multilevel1->setName("multigroup1");
    multilevel1->addLevel(1);

    multilevel2->setName("multigroup2");
    multilevel2->addLevel(1);
    multilevel2->addLevel(2);

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all levels
        dbClient->Multilevels()->removeAll();

        //add levels
        dbClient->Multilevels()->add(multilevel1);
        dbClient->Multilevels()->add(multilevel2);

        //remove levels
        dbClient->Multilevels()->remove(multilevel1->getInternalId());
        dbClient->Multilevels()->remove(multilevel2->getInternalId());

        //add level1 again
        dbClient->Multilevels()->add(multilevel1);

        //update level1
        multilevel1->setName("updated multi");
        dbClient->Multilevels()->update(multilevel1->getInternalId(), multilevel1);

        //check updated level
        std::shared_ptr<ProgressiveMultilevel> updatedMultilevel =
                dbClient->Multilevels()->get(multilevel1->getInternalId());

        if ( !(*multilevel1 == *updatedMultilevel) )
        {
            throw utils::CommonException(
                    "updated multilevel differs from original one.");
        }

        //add level2
        dbClient->Multilevels()->add(multilevel2);

        //get all levels
        std::vector<std::shared_ptr<ProgressiveMultilevel>> multilevelsList =
            dbClient->Multilevels()->getAll();

        if (multilevelsList.size() != 2)
        {
            throw utils::CommonException("levels count must be exact 2.");
        }

        //remove all levels
        dbClient->Multilevels()->removeAll();

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

} /* namespace test */
