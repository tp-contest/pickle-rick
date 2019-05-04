#pragma once

#include <iostream>
#include "stdlib.h"
#include "IContest.h"
#include "Competitors.h"
#include "Logs.h"
#include "Tasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

#define un unsigned

class Contest : public IContest {
public:
	Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* dataDase) {
		this->dataBase = dataBase;
		cout << "contest created" << endl;
	}
	un int getID(string title) {
		return 1;
	}
	string getInfo(un int ID) {
		return "[{}]";
	}
	string getStartTime(un int ID) {
		return "[{}]";
	}
	string getEndTime(un int ID) {
		return "[{}]";
	}
	bool addContest(string title, string infom, string settings) {
		return true;
	}
	bool setInfo(un int ID, string newInfo) {
		return true;
	}
	bool setEndTime(un int ID, string newEndTime) {
		return true;
	}

private:

	IDataBase* dataBase;

};