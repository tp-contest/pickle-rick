#pragma once

#include <iostream>
#include "stdlib.h"
#include "ITasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Tasks : public ITasks {
public:
	Tasks(IDataBase* dataDase);

	TaskStruct getTask(int taskID) override;

	TaskStruct getTasksForContest(int contestID) override;

	bool addTask(string description, string settings) override;

private:

	IDataBase* dataBase;
};