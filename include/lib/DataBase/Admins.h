#pragma once

#include <iostream>
#include "stdlib.h"
#include "IAdmins.h"
#include "ITable.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Admins : public IAdmins, public ITable {
public:
	Admins(IDataBase* dataDase = NULL) {
		this->dataBase = dataBase;
		//cout << "admins created" << endl;
	}
	string getAdminsForContest(un int contestID) {
		return "[{}]";
	}
	string getAdmin(un int adminID) {
		return "[{}]";
	}
	string getPermissions(un int adminD) {
		return "[{}]";
	}
	bool setPermissions(un int adminID, string permissions) {
		return true;
	}
	bool addAdmin(un int contestID, un int userID) {
		return true;
	}

private:

	string getTable() {
		return "none";
	}
	string getRow(un int ID) {
		return "none";
	}
	string getColumn(un int ID, string columnName) {
		return "none";
	}
	bool addRow(string row) {
		return true;
	}
	bool setRow(un int ID, string row) {
		return true;
	}
	bool deletRow(un int ID) {
		return true;
	}

	IDataBase* dataBase;
};