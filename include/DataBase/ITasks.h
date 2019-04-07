#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ITasks {
public:
    string virtual getTasksForContest(un int contestID);
    string virtual getTask(un int taskID);
    string virtual getinfo(un int taskID);
    string virtual getSettings(un int taskID);
    bool virtual setInfo(un int taskID);
    bool virtual setSettings(un int taskID);
};
