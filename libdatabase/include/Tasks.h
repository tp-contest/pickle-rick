#pragma once

#include <iostream>
#include "stdlib.h"
#include "ITasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Tasks : public ITasks {
public:
	Tasks(IDataBase* DB);

	TaskStruct getTask(int taskID) override;

	vector<TaskStruct> getTasksForContest(int contestID) override;

	bool addTask(string description, string settings) override;

private:

	IDataBase* dataBase = NULL;
};