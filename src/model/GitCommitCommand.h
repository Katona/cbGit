#ifndef GITCOMMITCOMMAND_H
#define GITCOMMITCOMMAND_H

#include "GitCommand.h"


class GitCommitCommand : public GitCommand
{
    public:
        static GitCommitCommand all(const string& workDir,
                                    const string& message = EMPTY_MESSAGE);
        static GitCommitCommand file(const string& workDir,
                                     const string& fileName,
                                     const string& message = EMPTY_MESSAGE);
        static GitCommitCommand files(const string& workDir,
                                      const vector<string>& files,
                                      const string& message = EMPTY_MESSAGE);
        virtual ~GitCommitCommand();
    protected:
    private:
        GitCommitCommand(const string& workDir, const string& message);
        static string EMPTY_MESSAGE;

};

#endif // GITCOMMITCOMMAND_H
