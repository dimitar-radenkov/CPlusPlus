/*
 * MongoLevelsTest.cpp
 *
 *  Created on: May 22, 2014
 *      Author: root
 */

#include "TestMongoLevels.h"

namespace test
{

TestMongoLevels::TestMongoLevels()
{
    // TODO Auto-generated constructor stub

}

TestMongoLevels::~TestMongoLevels()
{
    // TODO Auto-generated destructor stub
}

void TestMongoLevels::Run()
{
    std::cout << "checking levels...  " ;

    std::shared_ptr<ProgressiveLevel> level1(
        new ProgressiveLevel(
                LevelType::InternalLevel,
                1,
                1,
                1,
                1));

    std::shared_ptr<ProgressiveLevel> level2(
        new ProgressiveLevel(
                LevelType::ExternalLevel,
                2,
                2,
                2,
                2));

    //change random level params
    level1->setVisibleValue(5000);
    level1->setHiddenValue(6000);
    level1->setOverflowValue(7000);

    level2->setVisiblePercentage(5000);
    level2->setHiddenPercentage(6000);
    level2->setOverflowPercentage(7000);

    database::MongoDriver::getInstance().connect("localhost");
    std::shared_ptr<database::DBClient> dbClient (new database::MongoClient);

    try
    {
        //remove all levels
        dbClient->Levels()->removeAll();

        //add levels
        dbClient->Levels()->add(level1);
        dbClient->Levels()->add(level2);

        //remove levels
        dbClient->Levels()->remove(level1->getInternalId());
        dbClient->Levels()->remove(level2->getInternalId());

        //add level1 again
        dbClient->Levels()->add(level1);

        //update level1
        level1->setDenomIndex(11);
        dbClient->Levels()->update(level1->getInternalId(), level1);

        //check updated level
        std::shared_ptr<ProgressiveLevel> updatedLevel =
                dbClient->Levels()->get(level1->getInternalId());

        if ( !(*level1 == *updatedLevel) )
        {
            throw utils::CommonException(
                    "updated level differs from original one.");
        }

        //add level2
        dbClient->Levels()->add(level2);

        //get all levels
        std::vector<std::shared_ptr<ProgressiveLevel>> levelsList =
            dbClient->Levels()->getAll();

        if (levelsList.size() != 2)
        {
            throw utils::CommonException("levels count must be exact 2.");
        }

        //remove all levels
        dbClient->Levels()->removeAll();

        std::cout << "OK" << std::endl;
    }
    catch(utils::CommonException &e)
    {
        std::cout<< e.what() << std::endl;
    }
}

} /* namespace test */
