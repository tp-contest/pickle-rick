#include "Admins.h"

Admins::Admins(IDataBase* dataDase) {
	this->dataBase = dataBase;
	cout << "admins created" << endl;
}

AdminStruct Admins::getAdmin(int adminID) {
	AdminStruct admin;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Admins", "id =" + to_string(adminID));
	admin.Admin_id = atoi(result_vector[0].c_str());
	admin.contest_id = atoi(result_vector[1].c_str());
	admin.user_id = atoi(result_vector[2].c_str());
	return admin;
}

vector<AdminStruct> Admins::getAdminsForContest(int contestID) {
	vector<AdminStruct> AdminVector;
	vector<string> result_vector;
	result_vector = dataBase->select("*", "Admins", "contest_id =" + to_string(contestID));
	for (int i = 0; i < result_vector.size();)
	{
		AdminStruct admin;
		admin.Admin_id = atoi(result_vector[i + 0].c_str());
		admin.contest_id = atoi(result_vector[i + 1].c_str());
		admin.user_id = atoi(result_vector[i + 2].c_str());
		i = i + admin_field_count;
		AdminVector.push_back(admin);
	}
	return AdminVector;
}

bool  Admins::setAdmin(int contestID, int userID, int adminID) {
	if (adminID != -1) {
		string values = "(" + to_string(contestID) + ", " + to_string(userID) + ")";
		string condition = "admin_id=" + to_string(adminID);
		dataBase->update("Admins", values, condition);
	}
	else {
		string values = "(" + to_string(contestID) + ", " + to_string(userID) + ")";
		dataBase->insert("Admins", "(contest_id, user_id)", values);
	}
	return true;
}