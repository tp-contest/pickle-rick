#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ILogs {
public:
    string virtual getLog(un int logID);
    string virtual getLogsForContest(un int contestID);
    string virtual getLogsFormUser(un int userID);
};