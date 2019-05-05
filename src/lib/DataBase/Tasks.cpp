#include "Tasks.h"

Tasks::Tasks(IDataBase* dataDase) {
	this->dataBase = dataBase;
	cout << "tasks created" << endl;
}
TaskStruct Tasks::getTask(int taskID) {
	TaskStruct task;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Tasks", "task_id =" + to_string(taskID));
	task.task_id = atoi(result_vector[0].c_str());
	task.description = result_vector[1];
	task.settings = result_vector[2];
	return task;
}

TaskStruct Tasks::getTasksForContest(int contestID) {
	TaskStruct task;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Tasks", "contest_id =" + to_string(contestID));
	task.task_id = atoi(result_vector[0].c_str());
	task.description = result_vector[1];
	task.settings = result_vector[2];
	return task;
}

bool Tasks::addTask(string description, string settings) {
	string values = "(" + description + ", " + settings + ")";
	dataBase->insert("Logs", "(user_id, contest_id, path)", values);
	return true;
}