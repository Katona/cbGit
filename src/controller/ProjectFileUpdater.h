#ifndef PROJECTFILEUPDATER_H
#define PROJECTFILEUPDATER_H

#include <cbproject.h>
#include "../model/GitFileStatus.h"

class ProjectFileUpdater
{
    public:
        ProjectFileUpdater();
        void updateFile(ProjectFile& projFile, const GitFileStatus& gitStatus);
        void updateFile(ProjectFile& projFile, GitFileStatus::FileStatus fileStatus);
        virtual ~ProjectFileUpdater();
    protected:
    private:
        FileVisualState convert(GitFileStatus::FileStatus fileStatus);
};

#endif // PROJECTFILEUPDATER_H
