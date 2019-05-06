#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

struct TaskStruct {
	int task_id;
	string description;
	string settings;
};
const int task_field_count = 3;

class ITasks {
public:
	TaskStruct virtual getTask(int taskID) = 0;

	vector<TaskStruct> virtual getTasksForContest(int contestID) = 0;

	bool virtual addTask(string description, string settings) = 0;
};
