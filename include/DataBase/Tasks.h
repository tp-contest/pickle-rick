#pragma once

#include <iostream>
#include "stdlib.h"
#include "ITasks.h"
#include "ITable.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Tasks : public ITasks, public ITable {
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


    string virtual getTable() {
        return "none";
    }
    string virtual getRow(un int ID) {
        return "none";
    }
    string virtual getColumn(un int ID, string columnName) {
        return "none";
    }
    bool virtual addRow(string row) {
        return true;
    }
    bool virtual setRow(un int ID, string row) {
        return true;
    }
    bool virtual deletRow(un int ID) {
        return true;
    }
};