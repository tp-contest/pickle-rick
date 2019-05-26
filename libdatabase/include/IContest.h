#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

struct ContestStruct {
	int contest_id;
	int user_id;
	int input_file_id;
	int output_file_id;
	int description_file_id;
};

struct ContestData {
	int user_id;
	int input_file_id;
	int output_file_id;
	int description_file_id;
};
const int contest_field_count = 4;

class IContest {
public:
	ContestStruct virtual GetContest(int contestID) = 0;

	ContestStruct virtual GetContest(string title) = 0;

	vector<ContestStruct> virtual GetContestsList() = 0;

	bool virtual SetContest(int start_time, int end_time, string description) = 0;

	ContestStruct virtual CreateContest(ContestData contestData) = 0;
};