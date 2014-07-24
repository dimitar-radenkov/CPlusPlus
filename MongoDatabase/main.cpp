/*
 * main.cpp
 *
 *  Created on: May 10, 2014
 *      Author: root
 */
#include <cstdlib>
#include <iostream>
#include "Tests/RandomTest.h"

#include "Tests/Machines/TestMongoMachines.h"
#include "Tests/Machines/TestMongoMachinesGroups.h"

#include "Tests/Jackpots/TestMongoLevels.h"
#include "Tests/Jackpots/TestMongoMultilevels.h"
#include "Tests/Jackpots/TestMongoJackpots.h"

#include "Tests/Displays/TestMongoDisplays.h"
#include "Tests/Displays/TestMongoTextMessages.h"
#include "Tests/Displays/TestMongoTextMessagesConfigurations.h"
#include "Tests/Displays/TestMongoGeneralOptionsConfigurations.h"
#include "Tests/Displays/TestMongoScenarioScreensConfigurations.h"
#include "Tests/Displays/TestMongoScenarioScreens.h"
#include "Tests/Displays/TestMongoPriorityScreensConfigurations.h"
#include "Tests/Displays/TestMongoPriorityScreens.h"

#include "Tests/Common/TestMongoCommonParams.h"

int main()
{

    /*test::TestMongoMachines::Run();
    test::TestMongoMachinesGroups::Run();
    std::cout << std::endl;

    test::TestMongoLevels::Run();
    test::TestMongoMultilevels::Run();
    test::TestMongoJackpots::Run();
    std::cout << std::endl;

    test::TestMongoDisplays::Run();
    test::TestMongoTextMessages::Run();
    test::TestMongoTextMessagesConfigurations::Run();
    test::TestMongoGeneralOptionsConfigurations::Run();
    test::TestMongoScenarioScreensConfigurations::Run();
    test::TestMongoScenarioScreens::Run();
    test::TestMongoPriorityScreensConfigurations::Run();
    test::TestMongoPriorityScreens::Run();
    std::cout << std::endl;

    test::TestMongoCommonParams::Run();
    std::cout << std::endl;*/

    test::RandomTest::Run();


	std::cout << "end" << std::endl;

	return 0;
}
