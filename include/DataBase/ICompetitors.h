#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ICompetitors {
public:
    string virtual getAdminsForContest(un int contestID);
    string virtual getAdmin(un int adminID);
    string virtual getPermissions(un int adminD);
    bool virtual setPermissions(un int adminID);
    bool virtual addCompetitor(un int contestID, un int userID);
};