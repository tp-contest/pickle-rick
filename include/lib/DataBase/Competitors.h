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
		this->dataBase = dataBase;
		//cout << "competitors created" << endl;
	}
	string getCompetitorsForContest(un int contestID) {
		return "[{}]";
	}
	string getCompetitor(un int competitorID) {
		return "[{}]";
	}
	un int getPersonalScore(un int competitorID) {
		return 42;
	}
	string getRateList(un int contestID) {
		return "[{}]";
	}
	string virtual getCompletedTasks(un int competitorID) {
		return "[{}]";
	}
	bool virtual setCompletedTasks(string completedTasks, un int competitorID) {
		return true;
	}
	bool addCompetitor(un int contestID, un int userID) {
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