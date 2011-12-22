    #include <iostream>
    #include <string>
    #include "UnitTest++.h"
    #include "../src/model/ShellCommand.h"

    using namespace std;

    namespace
    {

    TEST(CommandTest)
    {
        const string TEST_OUTPUT = "TestOutput";
        ShellCommand cmd("echo " + TEST_OUTPUT);
        int result = cmd.execute();
        CHECK_EQUAL(ShellCommand::RESULT_SUCCESS, result);
        string output = cmd.getOutput();
        CHECK_EQUAL(TEST_OUTPUT, output.erase(output.size() - 1, 1));

    }

    }
