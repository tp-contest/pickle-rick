#include "Tasks.h"

Tasks::Tasks(IDataBase* DB) {
	this->dataBase = DB;
}
TaskStruct Tasks::getTask(int taskID) {
	TaskStruct task;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Tasks", "task_id =" + to_string(taskID));
	if (result_vector.size() == 1) {
		task.task_id = -1;
		return task;
	}
	task.task_id = atoi(result_vector[0].c_str());
	task.description = result_vector[1];
	task.settings = result_vector[2];
	return task;
}

vector<TaskStruct> Tasks::getTasksForContest(int contestID) {
	vector<TaskStruct> tasksList;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Tasks", "contest_id =" + to_string(contestID));
	if (result_vector.size() == 1) {
		TaskStruct task;
		task.task_id = -1;
		tasksList.push_back(task);
		return tasksList;
	}
	for (int i = 0; i < result_vector.size();)
	{
		TaskStruct task;
		task.task_id = atoi(result_vector[0].c_str());
		task.description = result_vector[1];
		task.settings = result_vector[2];
		i = i + task_field_count;
	}
	return tasksList;
}

bool Tasks::addTask(string description, string settings) {
	string values = "(" + description + ", " + settings + ")";
	dataBase->insert("Logs", "(user_id, contest_id, path)", values);
	return true;
}