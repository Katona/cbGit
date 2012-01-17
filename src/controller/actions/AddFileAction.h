#ifndef ADDMENUACTION_H
#define ADDMENUACTION_H

#include "FileAction.h"
#include "../../model/GitFileStatus.h"

class cbGitFile;
class FileEventHandler;

class AddFileAction : public FileAction
{
    public:
        AddFileAction(cbGitFile& file);
        virtual ~AddFileAction();
    private:
        static FileEventHandler* HANDLER;
        GitFileStatus m_fileStatus;
};

#endif // ADDMENUACTION_H
