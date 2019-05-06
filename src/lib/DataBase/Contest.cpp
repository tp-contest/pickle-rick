#include "Contest.h"

Contest::Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* DB) {
	this->dataBase = DB;
}
ContestStruct Contest::getContest(int contestID) {
	ContestStruct contest;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Contests", "id=" + to_string(contestID));
	if (result_vector.size() == 1) {
		contest.contest_id = -1;
		return contest;
	}
	contest.contest_id = atoi(result_vector[0].c_str());
	contest.start_time = atoi(result_vector[1].c_str());
	contest.end_time = atoi(result_vector[2].c_str());
	contest.description = result_vector[3];
	return contest;
}
ContestStruct Contest::getContest(string title) {
	ContestStruct contest;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Contests", "title=" + title);
	if (result_vector.size() == 1) {
		contest.contest_id = -1;
		return contest;
	}
	contest.contest_id = atoi(result_vector[0].c_str());
	contest.start_time = atoi(result_vector[1].c_str());
	contest.end_time = atoi(result_vector[2].c_str());
	contest.description = result_vector[3];
	return contest;
}
vector<ContestStruct> Contest::getContestsList() {
	vector<ContestStruct> contestVector;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Contests");
	if (result_vector.size() == 1) {
		ContestStruct contest;
		contest.contest_id = -1;
		contestVector.push_back(contest);
		return contestVector;
	}
	for (int i = 0; i < result_vector.size();)
	{
		ContestStruct contest;
		contest.contest_id = atoi(result_vector[0].c_str());
		contest.start_time = atoi(result_vector[1].c_str());
		contest.end_time = atoi(result_vector[2].c_str());
		contest.description = result_vector[3];
		i = i + contest_field_count;
		contestVector.push_back(contest);
	}
	return contestVector;
}
bool Contest::setContest(int start_time, int end_time, string description) {
	string values = "(" + to_string(start_time) + ", " + to_string(end_time) + ", " + description + ")";
	dataBase->insert("Contests", "(stert_time, end_time, description)", values);
	return true;
}