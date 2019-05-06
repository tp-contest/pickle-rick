#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

struct LogStruct {
	int log_id;
	int user_id;
	int contest_id;
	string path;
};
const int log_field_count = 4;

class ILogs {
public:
	LogStruct virtual getLog(int logID) = 0;

	vector<LogStruct> virtual getLogsForContest(int contestID) = 0;

	vector<LogStruct> virtual getLogsForUser(int userID) = 0;

	bool virtual addLog(string path, int user_id, int contest_id) = 0;
};