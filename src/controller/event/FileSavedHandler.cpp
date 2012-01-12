#include "FileSavedHandler.h"
#include <iostream>
#include <cbeditor.h>
#include "../ProjectFileUpdater.h"
#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../model/FileStatuses.h"
#include "../../utils/Utils.h"

using namespace std;

FileSavedHandler::FileSavedHandler()
{
    //ctor
}

void FileSavedHandler::handleEvent(cbGitFile& file, GitModel& gitModel) {
    updateStatus(file);
}

FileSavedHandler::~FileSavedHandler()
{
    //dtor
}
