#ifndef FILEACTION_H
#define FILEACTION_H

#include <memory>
#include "MenuAction.h"

using namespace std;

class cbGitFile;

class FileAction : public MenuAction
{
    public:
        FileAction(const string& actionText, EventHandler* handler,
                   cbGitFile& file);
        bool isEnabled() const;
        virtual ~FileAction();
    protected:
        virtual bool enabledFor(const GitFileStatus& status) const = 0;
    private:
        cbGitFile& m_file;
        auto_ptr<GitFileStatus> getStatus(cbGitFile& projectFile) const;
};

#endif // FILEACTION_H
