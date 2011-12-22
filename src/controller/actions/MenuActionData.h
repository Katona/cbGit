#ifndef MENUACTIONDATA_H
#define MENUACTIONDATA_H

#include <cbproject.h>
#include "../../model/GitFileStatus.h"

class MenuActionData
{
    public:
        MenuActionData(ProjectFile& projectFile, const GitFileStatus& fileStatus);
        ProjectFile& getProjectFile() const;
        GitFileStatus& getFileStatus() const;
        virtual ~MenuActionData();
    protected:
    private:
        ProjectFile& m_projectFile;
        GitFileStatus m_fileStatus;
};

#endif // MENUACTIONDATA_H
