#pragma once

#include <iostream>
#include "stdlib.h"
#include "IAdmins.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Admins : public IAdmins {
public:
    Admins(IDataBase* dataDase) {

    }
    string getAdminsForContest(un int contestID) {
        return "none";
    }
    string getAdmin(un int adminID) {
        return "none";
    }
    string getPermissions(un int adminD) {
        return "none";
    }
    bool setPermissions(un int adminID) {
        return true;
    }
    bool addAdmin(un int userID) {
        return true;
    }
};