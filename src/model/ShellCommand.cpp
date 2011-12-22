#include "ShellCommand.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <wx/wxprec.h>

#include <logmanager.h>

const int ShellCommand::RESULT_FAILURE = -1;
const int ShellCommand::RESULT_SUCCESS = 0;

ShellCommand::ShellCommand(const string& shellCmd) : m_cmd(shellCmd)
{
    //ctor
}

int ShellCommand::execute() {
//    string msg = "Executing command: " + m_cmd;
//    logger.Log(wxString(msg.c_str(), wxConvUTF8));
    string cmd = composeCommand();
    cout << "Executing command: " << cmd << endl;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return -1;
    char buffer[128];
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
                m_result += buffer;
    }
    pclose(pipe);
//    msg = "Result is: " + m_result;
//    logger.Log(wxString(msg.c_str(), wxConvUTF8));

    return 0;
}

const string& ShellCommand::getOutput() {
    return m_result;
}

void ShellCommand::getOutputLines(vector<string>& lines) {
    split(m_result, '\n', lines);
}

void ShellCommand::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

void ShellCommand::addArgument(const string& arg) {
    m_arguments.push_back(arg);
}

void ShellCommand::addArguments(const vector<string>& args) {
    for (vector<string>::size_type i = 0; i < args.size(); i++) {
        m_arguments.push_back(args[i]);
    }
}

const string ShellCommand::composeCommand() {
    string result = m_cmd;
    for (vector<string>::size_type i = 0; i < m_arguments.size(); i++) {
        result += " " + m_arguments[i];
    }
    return result;
}

ShellCommand::~ShellCommand()
{
    //dtor
}
