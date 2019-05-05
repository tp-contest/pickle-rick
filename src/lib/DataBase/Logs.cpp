#include "Logs.h"

Logs::Logs(IDataBase* dataDase) {
	this->dataBase = dataBase;
	cout << "logs created" << endl;
}
LogStruct Logs::getLog(int logID) {
	LogStruct log;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Logs", "id =" + to_string(logID));
	for (int i = 0; i < result_vector.size();)
	{
		log.log_id = atoi(result_vector[i + 0].c_str());
		log.user_id = atoi(result_vector[i + 1].c_str());
		log.contest_id = atoi(result_vector[i + 2].c_str());
		log.path = result_vector[i + 3];
		i = i + log_field_count;
	}
	return log;
}
vector<LogStruct> Logs::getLogsForContest(int contestID) {
	vector<LogStruct> logVector;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Logs", "contest_id =" + to_string(contestID));
	for (int i = 0; i < result_vector.size();)
	{
		LogStruct log;
		log.log_id = atoi(result_vector[i + 0].c_str());
		log.user_id = atoi(result_vector[i + 1].c_str());
		log.contest_id = atoi(result_vector[i + 2].c_str());
		log.path = result_vector[i + 3];
		i = i + log_field_count;
		logVector.push_back(log);
	}
	return logVector;
}
vector<LogStruct> Logs::getLogsForUser(int userID) {
	vector<LogStruct> logVector;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Logs", "contest_id =" + to_string(userID));
	for (int i = 0; i < result_vector.size();)
	{
		LogStruct log;
		log.log_id = atoi(result_vector[i + 0].c_str());
		log.user_id = atoi(result_vector[i + 1].c_str());
		log.contest_id = atoi(result_vector[i + 2].c_str());
		log.path = result_vector[i + 3];
		i = i + log_field_count;
		logVector.push_back(log);
	}
	return logVector;
}
bool Logs::addLog(string path, int user_id, int contest_id) {
	string values = "(" + path + ", " + to_string(user_id) + ", " + to_string(user_id) + ")";
	dataBase->insert("Logs", "(user_id, contest_id, path)", values);
	return true;
}