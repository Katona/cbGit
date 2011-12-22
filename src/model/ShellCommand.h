#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

using namespace std;

class LogManager;

class ShellCommand
{
    public:
        static const int RESULT_SUCCESS;
        static const int RESULT_FAILURE;

        ShellCommand(const string& shellCmd);
        virtual int execute();
        const string& getOutput();
        void getOutputLines(vector<string>& lines);
        virtual ~ShellCommand();
    protected:
        void addArgument(const string& arg);
        void addArguments(const vector<string>& args);
    private:
        string m_cmd;
        vector<string> m_arguments;
        string m_result;

        void split(const string &s, char delim, vector<string> &elems);
        const string composeCommand();

};

#endif // COMMAND_H
