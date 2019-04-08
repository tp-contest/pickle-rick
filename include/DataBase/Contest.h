#pragma once

#include <iostream>
#include "stdlib.h"
#include "IContest.h"
#include "ITable.h"
#include "Competitors.h"
#include "Logs.h"
#include "Tasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

#define un unsigned

class Contest : public IContest, public ITable {
public:
    Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* dataDase) {
        this->dataBase = dataBase;
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

private:
    IDataBase* dataBase;
};