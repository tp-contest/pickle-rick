#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

struct CompetitorStruct {
	int competitor_id;
	int contest_id;
	int user_id;
};

class ICompetitors {
public:
	string virtual getCompetitorsForContest(un int contestID) = 0;
	string virtual getCompetitor(un int competitorID) = 0;
    un int virtual getPersonalScore(un int competitorID) = 0;
	string virtual getRateList(un int contestID) = 0;
	string virtual getCompletedTasks(un int competitorID) = 0;
	bool virtual setCompletedTasks(string completedTasks, un int competitorID) = 0;
	bool virtual addCompetitor(un int contestID, un int userID) = 0;
};