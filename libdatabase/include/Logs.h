#pragma once

#include <iostream>
#include "stdlib.h"
#include "ILogs.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"


class Logs : public ILogs {
public:
	Logs(IDataBase* DB);

	LogStruct getLog(int logID) override;

	vector<LogStruct> getLogsForContest(int contestID) override;

	vector<LogStruct> getLogsForUser(int userID) override;

	bool addLog(string path, int user_id, int contest_id) override;

private:

	IDataBase* dataBase = NULL;

};