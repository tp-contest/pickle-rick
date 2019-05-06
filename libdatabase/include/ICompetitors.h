#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

struct CompetitorStruct {
	int competitor_id;
	int contest_id;
	int user_id;
};
const int competitor_field_count = 3;

class ICompetitors {
public:
	CompetitorStruct virtual getCompetitor(int competitorID) = 0;

	vector<CompetitorStruct> virtual getCompetitorsForContest(int contestID) = 0;

	bool virtual setCompetitor(int contestID, int userID, int competitorID = -1) = 0;
};