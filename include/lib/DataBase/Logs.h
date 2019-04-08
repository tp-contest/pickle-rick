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
    this->dataBase = dataBase;
    // cout << "logs created" << endl;
  }
  string getLog(un int logID) { return "[{}]"; }
  string getLogsForContest(un int contestID) { return "[{}]"; }
  string getLogsForUser(un int userID) { return "[{}]"; }
  bool addLog(string log) { return true; }

 private:
  string getTable() { return "none"; }
  string getRow(un int ID) { return "none"; }
  string getColumn(un int ID, string columnName) { return "none"; }
  bool addRow(string row) { return true; }
  bool setRow(un int ID, string row) { return true; }
  bool deletRow(un int ID) { return true; }
  IDataBase* dataBase;
};