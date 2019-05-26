#pragma once

#include <iostream>
#include "stdlib.h"
#include "IContest.h"
#include "Competitors.h"
#include "Logs.h"
#include "Tasks.h"
#include "Admins.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"



class Contest : public IContest {
public:
	Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* DB);

	ContestStruct GetContest(int contestID) override;

	ContestStruct GetContest(string title) override;

	vector<ContestStruct> GetContestsList() override;

	bool SetContest(int start_time, int end_time, string description) override;

	ContestStruct CreateContest(ContestData contestData) override;

private:

	IDataBase* dataBase = NULL;

};