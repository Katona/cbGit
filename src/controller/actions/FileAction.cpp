#include "FileAction.h"
#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../Utils.h"

FileAction::FileAction(const string& actionText, MenuActionHandler* handler,
                       ProjectFile& projectFile) :
    MenuAction(actionText, handler), m_projectFile(projectFile)
{
    //ctor
}

bool FileAction::isEnabled() const {
    auto_ptr<GitFileStatus> status = getStatus(m_projectFile);
    return status.get() == NULL ? false : enabledFor(*status);
}

auto_ptr<GitFileStatus> FileAction::getStatus(ProjectFile& projectFile) const {
    string workDir = toString(
        projectFile.GetParentProject()->GetCommonTopLevelPath());
    string fileName = toString(projectFile.relativeFilename);
    GitModel gitModel(workDir);
    vector<GitFileStatus> statuses;
    gitModel.getStatus(statuses, fileName);
    auto_ptr<GitFileStatus> result;
    if (!statuses.empty()) {
        result.reset(new GitFileStatus(statuses[0]));
    }
    return result;
}

FileAction::~FileAction()
{
    //dtor
}
