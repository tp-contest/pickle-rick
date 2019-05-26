#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>
#include "IDataBase.h"
#include "DataBaseMySQL.h"

using namespace std;

struct AdminStruct {
	int admin_id;
	int contest_id;
	int user_id;
};
const int admin_field_count = 3;

class IAdmins {
public:

	AdminStruct virtual GetAdmin(int adminID) = 0;

	vector<AdminStruct> virtual GetAdminsForContest(int contestID) = 0;

	bool virtual SetAdmin(int contestID, int userID, int adminID = -1) = 0;
};