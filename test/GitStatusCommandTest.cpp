#include <iostream>
#include <string>
#include "UnitTest++.h"
#include "../src/model/GitStatusCommand.h"
#include "../src/model/FileStatuses.h"

using namespace std;

const string STR_WORKTREE = "/home/katona/tmp/gittest/";

namespace
{

TEST(GitStatusCommandTestUntracked)
{
    const string strUntracked = "untracked";

    GitStatusCommand gitStatus(STR_WORKTREE);
    FileStatuses fileStatuses;
    gitStatus.getFileStatuses(fileStatuses);
    CHECK_EQUAL(GitFileStatus::untracked, fileStatuses.getStatus(strUntracked).getStatus());
}

TEST(GitStatusCommandTestNone)
{
    const string strUpToDate = "uptodate";

    GitStatusCommand gitStatus(STR_WORKTREE);
    FileStatuses fileStatuses;
    gitStatus.getFileStatuses(fileStatuses);
    CHECK_EQUAL(GitFileStatus::none, fileStatuses.getStatus(strUpToDate).getStatus());
}

TEST(GitStatusCommandTestUntrackedFolder) {
    const string strFileInUntracked = "untrackedfolder/file";

    GitStatusCommand gitStatus(STR_WORKTREE);
    FileStatuses fileStatuses;
    gitStatus.getFileStatuses(fileStatuses);
    CHECK_EQUAL(GitFileStatus::untracked, fileStatuses.getStatus(strFileInUntracked).getStatus());

}

}
