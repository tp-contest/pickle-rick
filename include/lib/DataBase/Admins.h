#pragma once

#include <iostream>
#include "stdlib.h"
#include "IAdmins.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Admins : public IAdmins {

public:
	Admins(IDataBase* dataDase) {
		this->dataBase = dataBase;
		cout << "admins created" << endl;
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

	IDataBase* dataBase;
};