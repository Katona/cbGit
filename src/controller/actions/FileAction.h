#ifndef FILEACTION_H
#define FILEACTION_H

#include <memory>
#include "MenuAction.h"
#include "../../model/GitFileStatus.h"

using namespace std;

class cbGitFile;

class FileAction : public MenuAction
{
    public:
        FileAction(const string& actionText, EventHandler* handler,
                   cbGitFile& file);
        FileAction& addValidStatus(GitFileStatus::FileStatus statusFlag);
        bool isEnabled() const;
        virtual ~FileAction();
    protected:
        virtual bool enabledFor(const GitFileStatus& status) const;
    private:
        auto_ptr<GitFileStatus> getStatus(cbGitFile& projectFile) const;

        cbGitFile& m_file;
        int m_validStatuses;
};

#endif // FILEACTION_H
