#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class IContest {
public:
    un int virtual getID(string title) = 0;
    string virtual getInfo(un int ID) = 0;
    string virtual getStartTime(un int ID) = 0;
    string virtual getEndTime(un int ID) = 0;
    bool virtual setInfo(un int ID, string newInfo) = 0;
    bool virtual setEndTime(un int ID, string newEndTime) = 0;
};