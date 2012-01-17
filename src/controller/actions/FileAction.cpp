#include "FileAction.h"
#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../model/FileStatuses.h"
#include "../../utils/cbGitFile.h"
#include "../../utils/cbGitProject.h"

FileAction::FileAction(const string& actionText, EventHandler* handler,
                       cbGitFile& file) :
    MenuAction(actionText, handler), m_file(file)
{
    //ctor
}

bool FileAction::isEnabled() const {
    auto_ptr<GitFileStatus> status = getStatus(m_file);
    return status.get() == NULL ? false : enabledFor(*status);
}

FileAction& FileAction::addValidStatus(GitFileStatus::FileStatus statusFlag) {
    m_validStatuses |= statusFlag;
}

auto_ptr<GitFileStatus> FileAction::getStatus(cbGitFile& file) const {
    string workDir = file.getProjectPath();
    string fileName = file.getRelativeFileName();
    GitModel gitModel(workDir);
    FileStatuses statuses;
    gitModel.getStatus(statuses, fileName);
    auto_ptr<GitFileStatus> result;
    if (!statuses.isEmpty()) {
        result.reset(new GitFileStatus(statuses.getStatus(fileName)));
    }
    return result;
}

bool FileAction::enabledFor(const GitFileStatus& status) const {
    return (m_validStatuses & status.getStatus()) > 0;
}

FileAction::~FileAction()
{
    //dtor
}
