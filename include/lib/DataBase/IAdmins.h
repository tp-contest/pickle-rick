#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

struct AdminStruct {
	int Admin_id;
	int contest_id;
	int user_id;
};
const int admin_field_count = 3;

class IAdmins {
public:
	AdminStruct virtual getAdmin(int adminID) = 0;

	vector<AdminStruct> virtual getAdminsForContest(int contestID) = 0;

	bool virtual setAdmin(int contestID, int userID, int adminID = -1) = 0;
};