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

	ContestStruct getContest(int contestID) override;

	ContestStruct getContest(string title) override;

	vector<ContestStruct> getContestsList() override;

	bool setContest(int start_time, int end_time, string description) override;

private:

	IDataBase* dataBase = NULL;

};