#ifndef FILEACTION_H
#define FILEACTION_H

#include <memory>
#include <cbproject.h>
#include "MenuAction.h"

using namespace std;

class FileAction : public MenuAction
{
    public:
        FileAction(const string& actionText, MenuActionHandler* handler,
                   ProjectFile& projectFile);
//        virtual bool enabledFor(ProjectFile& projectFile) const;
        bool isEnabled() const;
        virtual ~FileAction();
    protected:
        virtual bool enabledFor(const GitFileStatus& status) const = 0;
    private:
        ProjectFile& m_projectFile;
        auto_ptr<GitFileStatus> getStatus(ProjectFile& projectFile) const;
};

#endif // FILEACTION_H
