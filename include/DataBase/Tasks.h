#pragma once

#include <iostream>
#include "stdlib.h"
#include "ITasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Tasks : public ITasks {
public:
    Tasks(IDataBase* dataDase) {
        cout << "tasks created" << endl;
    }
    string virtual getTasksForContest(un int contestID) {
        return "none";
    }
    string virtual getTask(un int taskID) {
        return "none";
    }
    string virtual getinfo(un int taskID) {
        return "none";
    }
    string virtual getSettings(un int taskID) {
        return "none";
    }
    bool virtual setInfo(un int taskID) {
        return true;
    }
    bool virtual setSettings(un int taskID) {
        return true;
    }
};