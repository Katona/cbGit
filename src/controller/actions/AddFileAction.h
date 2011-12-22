#ifndef ADDMENUACTION_H
#define ADDMENUACTION_H

#include "FileAction.h"
#include "../../model/GitFileStatus.h"

class ProjectFile;

class AddFileAction : public FileAction
{
    public:
        AddFileAction(ProjectFile& file);
        bool enabledFor(const GitFileStatus& gitFileStatus) const;
        virtual ~AddFileAction();
    protected:
    private:
        static MenuActionHandler* HANDLER;
        GitFileStatus m_fileStatus;
};

#endif // ADDMENUACTION_H
