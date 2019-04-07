#pragma once

#include <iostream>
#include "stdlib.h"
#include "ICompetitors.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Competitors : public ICompetitors {
public:
    Competitors(IDataBase* dataDase) {
        cout << "competitors created" << endl;
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
    bool addCompetitor(un int contestID, un int userID) {
        return true;
    }

};