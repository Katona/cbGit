#include <iostream>
#include <string>
#include "UnitTest++.h"
#include "../src/model/GitStatusCommand.h"

using namespace std;

namespace
{

TEST(GitStatusCommandTest)
{
    GitStatusCommand gitStatus("/home/katona/tmp/gittest/");
    vector<GitFileStatus> fileStatuses;
    bool isGitRepo = gitStatus.isGitRepository();
    CHECK_EQUAL(true, isGitRepo);
    gitStatus.getFileStatuses(fileStatuses);
    CHECK_EQUAL(false, fileStatuses.empty());
    CHECK_EQUAL(GitFileStatus::none, fileStatuses[0].getWorkTreeStatus());

    GitStatusCommand gitStatusNonGitRepo("/home/");
    isGitRepo = gitStatusNonGitRepo.isGitRepository();
    CHECK_EQUAL(false, isGitRepo);

}

}
