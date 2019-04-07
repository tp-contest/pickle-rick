#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class IContest {
public:
    un int virtual getID(string title);
    string virtual getInfo(un int ID);
    bool virtual setInfo(un int ID, string newInfo);
    string virtual getStartTime(un int ID);
    string virtual getEndTime(un int ID);
    bool virtual setEndTime(un int ID, string newEndTime);
};