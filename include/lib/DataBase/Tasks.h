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
    this->dataBase = dataBase;
    // cout << "tasks created" << endl;
  }
  string virtual getTasksForContest(un int contestID) { return "[{}]"; }
  string virtual getTask(un int taskID) { return "[{}]"; }
  string virtual getinfo(un int taskID) { return "[{}]"; }
  string virtual getSettings(un int taskID) { return "[{}]"; }
  bool virtual setInfo(un int taskID, string info) { return true; }
  bool virtual setSettings(un int taskID, string settings) { return true; }

 private:
  string getTable() { return "none"; }
  string getRow(un int ID) { return "none"; }
  string getColumn(un int ID, string columnName) { return "none"; }
  bool addRow(string row) { return true; }
  bool setRow(un int ID, string row) { return true; }
  bool deletRow(un int ID) { return true; }

  IDataBase* dataBase;
};