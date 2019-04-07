#pragma once

#include <iostream>
#include "stdlib.h"
#include "ICompetitors.h"
#include "ITable.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Competitors : public ICompetitors, public ITable {
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