#include "MenuActionData.h"

MenuActionData::MenuActionData(ProjectFile& projectFile,
                               const GitFileStatus& fileStatus) :
    m_projectFile(projectFile), m_fileStatus(fileStatus);
{
    //ctor
}

MenuActionData::~MenuActionData()
{
    //dtor
}
