#include "GitCheckoutCommand.h"

GitCheckoutCommand::GitCheckoutCommand(const string& workDir)
    : GitCommand(workDir), m_toStage(false)
{
    addArgument("checkout");
}

GitCheckoutCommand& GitCheckoutCommand::file(const string& fileName) {
    m_fileNames.push_back(fileName);
    return (*this);
}

GitCheckoutCommand& GitCheckoutCommand::revertToStagingIndex() {
    m_toStage = true;
    return (*this);
}

int GitCheckoutCommand::execute() {
    if (m_toStage) {
        addArgument("--");
    } else {
        addArgument("HEAD");
    }
    addArguments(m_fileNames);
    GitCommand::execute();
}

GitCheckoutCommand::~GitCheckoutCommand()
{
    //dtor
}
