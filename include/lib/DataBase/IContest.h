#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

struct ContestStruct {
	int contest_id;
	int start_time;
	int end_time;
	string description;
};

class IContest {
public:
	ContestStruct virtual getContest(int contestID) = 0;

	ContestStruct virtual getContest(string title) = 0;

	vector<ContestStruct> virtual getContestsList() = 0;

	bool virtual setContest(int start_time, int end_time, string description) = 0;
};