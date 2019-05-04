#pragma once

#include <iostream>
#include "stdlib.h"
#include "ITasks.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Tasks : public ITasks {
public:
	Tasks(IDataBase* dataDase) {
		this->dataBase = dataBase;
		cout << "tasks created" << endl;
	}
	TaskStruct getTask(int taskID) override {
		TaskStruct task;
		vector<string> result_vector;
		result_vector = dataBase->select("*", "Tasks", "task_id =" + to_string(taskID));
		task.task_id = atoi(result_vector[0].c_str());
		task.description = result_vector[1];
		task.settings = result_vector[2];
		return task;
	}

	TaskStruct getTasksForContest(int contestID) override {
		TaskStruct task;
		vector<string> result_vector;
		result_vector = dataBase->select("*", "Tasks", "contest_id =" + to_string(contestID));
		task.task_id = atoi(result_vector[0].c_str());
		task.description = result_vector[1];
		task.settings = result_vector[2];
		return task;
	}

	bool addTask(string description, string settings) override {
		string values = "(" + description + ", " + settings + ")";
		dataBase->insert("Logs", "(user_id, contest_id, path)", values);
		return true;
	}

private:

	IDataBase* dataBase;
};