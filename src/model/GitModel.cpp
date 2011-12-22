#include "GitModel.h"
#include "GitStatusCommand.h"
#include "GitCommitCommand.h"
#include "GitAddCommand.h"
#include "GitCheckoutCommand.h"
#include "GitResetCommand.h"

GitModel::GitModel(const string& workDir) : m_workDir(workDir)
{
    //ctor
}

void GitModel::getStatus(vector<GitFileStatus>& result, const string& fileName) {

    GitStatusCommand* cmd;
    if (fileName == "") {
        cmd = new GitStatusCommand(m_workDir);
    } else {
        cmd = new GitStatusCommand(m_workDir, fileName);
    }
    cmd->getFileStatuses(result);

    delete cmd;
}

void GitModel::add(const vector<string>& filesToAdd) {
    GitAddCommand addCmd(m_workDir, filesToAdd);
    addCmd.execute();
}

void GitModel::commitAll(const string& message) {
    GitCommitCommand commitAll = GitCommitCommand::all(m_workDir, message);
    commitAll.execute();
}

void GitModel::checkoutFile(const string& fileName) {
    GitCheckoutCommand(m_workDir).file(fileName).execute();
}

void GitModel::resetFile(const string& fileName) {
    GitResetCommand(m_workDir).file(fileName).execute();
}

GitModel::~GitModel()
{
    //dtor
}
