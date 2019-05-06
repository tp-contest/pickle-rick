#pragma once

#include <iostream>
#include "stdlib.h"
#include "IAdmins.h"

class Admins : public IAdmins {

public:

	Admins(IDataBase* Base) {
		this->dataBase = Base;
	}

	AdminStruct getAdmin(int adminID) override;

	vector<AdminStruct> getAdminsForContest(int contestID) override;

	bool setAdmin(int contestID, int userID, int adminID = -1) override;


private:

	IDataBase* dataBase = NULL;
};