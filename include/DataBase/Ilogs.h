#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ILogs {
public:
    string virtual getLog(un int logID) = 0;
    string virtual getLogsForContest(un int contestID) = 0;
    string virtual getLogsFormUser(un int userID) = 0;
};