#include "Contest.h"
#include <boost/any.hpp>

Contest::Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* DB) {
	this->dataBase = DB;
}
ContestStruct Contest::GetContest(int contestID) {
	ContestStruct contest;
	vector<string> result_vector;
	result_vector = dataBase->Select("*", "Contests", "id=" + to_string(contestID));
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
ContestStruct Contest::GetContest(string title) {
	ContestStruct contest;
	vector<string> result_vector;
	result_vector = dataBase->Select("*", "Contests", "title=" + title);
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
vector<ContestStruct> Contest::GetContestsList() {
	vector<ContestStruct> contestVector;
	vector<string> result_vector;
	result_vector = dataBase->Select("*", "Contests");
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
bool Contest::SetContest(int start_time, int end_time, string description) {
	string values = "(" + to_string(start_time) + ", " + to_string(end_time) + ", " + description + ")";
	dataBase->Insert("Contests", "(stert_time, end_time, description)", values);
	return true;
}

ContestStruct Contest::CreateContest(ContestData contestData) {
	string values = "(" + to_string(contestData.user_id) + ", " + to_string(contestData.input_file_id) + ", " + to_string(contestData.output_file_id) + ", " + to_string(contestData.description_file_id) + ")";
	dataBase->Insert("Contests", "(user_id, input_file_id, output_file_id, description_file_id)", values);
	boost::any result;
	ContestStruct newContest;
	result = dataBase->Select("*", "Contests", "user_id=" + to_string(contestData.user_id) + ", input_file_id=" + to_string(contestData.input_file_id) + ", output_file_id" + to_string(contestData.output_file_id) + ", description_file_id" + to_string(contestData.description_file_id));
	try
	{
		vector<string> result_vector = boost::any_cast<vector<string>>(result_vector);
		for (int i = 0; i < result_vector.size();)
		{
			newContest.contest_id = atoi(result_vector[i++].c_str());
			newContest.user_id = atoi(result_vector[i++].c_str());
			newContest.input_file_id = atoi(result_vector[i++].c_str());
			newContest.output_file_id = atoi(result_vector[i++].c_str());
			newContest.description_file_id = atoi(result_vector[i++].c_str());
		}
		return newContest;
	}
	catch (boost::bad_any_cast & e)
	{
		newContest.contest_id = -1;
		return newContest;
	}
}