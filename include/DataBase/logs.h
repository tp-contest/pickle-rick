#pragma once

#include <iostream>
#include "stdlib.h"
#include "ILogs.h"
#include "ITable.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Logs : public ILogs, public ITable {
public:
    Logs(IDataBase* dataDase) {
        cout << "logs created" << endl;
    }
    string getLog(un int logID) {
        return "none";
    }
    string getLogsForContest(un int contestID) {
        return "none";
    }
    string getLogsFormUser(un int userID) {
        return "none";
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