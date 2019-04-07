#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class IAdmins {
public:
    string virtual getAdminsForContest(un int contestID) = 0;
    string virtual getAdmin(un int adminID) = 0;
    string virtual getPermissions(un int adminD) = 0;
    bool virtual setPermissions(un int adminID) = 0;
    bool virtual addAdmin(un int userID) = 0;
};