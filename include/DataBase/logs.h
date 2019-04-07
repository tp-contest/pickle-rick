#pragma once

#include <iostream>
#include "stdlib.h"
#include "ILogs.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Logs : public ILogs {
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
};