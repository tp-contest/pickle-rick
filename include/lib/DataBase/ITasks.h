#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

struct TaskStruct {
	int task_id;
	string description;
	string settings;
};

class ITasks {
public:
	TaskStruct virtual getTask(int taskID) = 0;
	TaskStruct virtual getTasksForContest(int contestID) = 0;
	bool virtual addTask(string description, string settings) = 0;
};
