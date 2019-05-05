#include "Competitors.h"

Competitors::Competitors(IDataBase* dataDase) {
	this->dataBase = dataBase;
	cout << "competitors created" << endl;
}
CompetitorStruct Competitors::getCompetitor(int competitorID) {
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Logs", "id =" + to_string(competitorID));
	CompetitorStruct competitor;
	competitor.competitor_id = atoi(result_vector[0].c_str());
	competitor.contest_id = atoi(result_vector[1].c_str());
	competitor.user_id = atoi(result_vector[2].c_str());
	return competitor;
}
vector<CompetitorStruct> Competitors::getCompetitorsForContest(int contestID) {
	vector<CompetitorStruct> competitorVector;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Competitors", "contest_id =" + to_string(contestID));
	for (int i = 0; i < result_vector.size();)
	{
		CompetitorStruct competitor;
		competitor.competitor_id = atoi(result_vector[i + 0].c_str());
		competitor.contest_id = atoi(result_vector[i + 1].c_str());
		competitor.user_id = atoi(result_vector[i + 2].c_str());
		i = i + competitor_field_count;
		competitorVector.push_back(competitor);
	}
	return competitorVector;
}
bool Competitors::setCompetitor(int contestID, int userID, int competitorID) {
	if (competitorID != -1) {
		string values = "(" + to_string(contestID) + ", " + to_string(userID) + ")";
		string condition = "competitor_id=" + to_string(competitorID);
		dataBase->update("Competitors", values, condition);
	}
	else {
		string values = "(" + to_string(contestID) + ", " + to_string(userID) + ")";
		dataBase->insert("Competitors", "(contest_id, user_id)", values);
	}
	return true;
}