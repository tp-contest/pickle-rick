#pragma once

#include <iostream>
#include "stdlib.h"
#include "ICompetitors.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Competitors : public ICompetitors {
public:
	Competitors(IDataBase* DB) {
		this->dataBase = DB;
	}

	CompetitorStruct getCompetitor(int competitorID) override;

	vector<CompetitorStruct> getCompetitorsForContest(int contestID) override;

	bool virtual setCompetitor(int contestID, int userID, int competitorID = -1) override;

private:

	IDataBase* dataBase = NULL;

};