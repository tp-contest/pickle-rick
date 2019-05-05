#pragma once

#include <iostream>
#include "stdlib.h"
#include "IAdmins.h"
#include "IDataBase.h"
#include "DataBaseMySQL.h"

class Admins : public IAdmins {

public:
	Admins(IDataBase* dataDase);

	AdminStruct getAdmin(int adminID) override;

	vector<AdminStruct> getAdminsForContest(int contestID) override;

	bool setAdmin(int contestID, int userID, int adminID = -1) override;


private:

	IDataBase* dataBase;
};