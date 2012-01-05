#include <iostream>
#include <string>
#include "UnitTest++.h"
#include "../src/Path.h"

using namespace std;

namespace
{

TEST(PathTestDir)
{
    string strTestPath("folder/subfolder/subsubfolder/");
    Path path(strTestPath);
    CHECK_EQUAL(true, path.isDirectory());
}

TEST(PathTestNonDir)
{
    string strTestPath("folder/subfolder/subsubfolder");
    Path path(strTestPath);
    CHECK_EQUAL(false, path.isDirectory());
}

TEST(EmptyPathTest)
{
    Path path("");
    CHECK_EQUAL(false, path.isDirectory());
}
}
