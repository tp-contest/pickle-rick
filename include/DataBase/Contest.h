#pragma once

#include <iostream>
#include "stdlib.h"
#include "IContest.h"
#include "Competitors.h"
#include "Logs.h"
#include "Tasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

#define un unsigned

class Contest : public IContest {
public:
    Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* dataDase) {
        cout << "contest created" << endl;
    }
    un int virtual getID(string title) {
        return 1;
    }
    string virtual getInfo(un int ID) {
        return "none";
    }
    string virtual getStartTime(un int ID) {
        return "none";
    }
    string virtual getEndTime(un int ID) {
        return "none";
    }
    bool virtual setInfo(un int ID, string newInfo) {
        return true;
    }
    bool virtual setEndTime(un int ID, string newEndTime) {
        return true;
    }
};