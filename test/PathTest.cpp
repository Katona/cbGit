#include <iostream>
#include <string>
#include "UnitTest++.h"
#include "../src/Path.h"

using namespace std;

namespace
{

TEST(PathTest)
{
    string strTestPath("folder/subfolder/subsubfolder/file.txt");
    Path path(strTestPath);
    CHECK_EQUAL(false, path.endReached());
    CHECK_EQUAL("", path.getCurrentPath());
    path.step();
    CHECK_EQUAL(false, path.endReached());
    CHECK_EQUAL("folder", path.getCurrentPath());
    path.step();
    CHECK_EQUAL("folder/subfolder", path.getCurrentPath());
    path.step();
    CHECK_EQUAL("folder/subfolder/subsubfolder", path.getCurrentPath());
    CHECK_EQUAL(true, path.endReached());
    path.step();
    CHECK_EQUAL("folder/subfolder/subsubfolder", path.getCurrentPath());

}

TEST(EmptyPathTest)
{
    Path path("");
    CHECK_EQUAL(true, path.endReached());

    Path anotherPath("file.txt");
    CHECK_EQUAL(true, anotherPath.endReached());
}

TEST(FullPathTest)
{
    string strTestPath("folder/subfolder/subsubfolder/file.txt");
    Path path(strTestPath);
    CHECK_EQUAL("folder/subfolder/subsubfolder", path.getFullPath());
}
}
