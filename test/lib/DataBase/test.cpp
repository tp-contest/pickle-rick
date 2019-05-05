#include "gtest/gtest.h"
#include "mysql.h"

class TestDataBase : public IDataBase {
public:
	TestDataBase() : conn(mysql_init(NULL)) {
		conn = mysql_real_connect(conn, "localhost", "root", "36360326v", "testdb", 3306, NULL, 0);
		if (conn) {
			cout << "Connection Success" << endl;
		}
		else
		{
			cout << "Connection Failed" << endl;
		}
		cout << "dataBaseMySQL created" << endl;
	}
	vector<string> select(string selector, string table, string condition) {

		result_vector.clear();
		if (!conn)
		{
			result_vector.push_back("There is no connection");
			return result_vector;
		}
		form_select_query(selector, table, condition);
		if (!qstate)
		{
			take_result_from_select();
		}
		else
		{
			result_vector.push_back("Query failed: " + mysql_errno(conn));
		}
		return result_vector;
	}

	vector<string> update(string table, string set, string condition) {
		result_vector.clear();
		if (!conn)
		{
			result_vector.push_back("There is no connection");
			return result_vector;
		}
		form_update_query(table, set, condition);
		if (!qstate)
		{
			result_vector.push_back("Update Success:");
		}
		else
		{
			result_vector.push_back("Update failed: " + mysql_errno(conn));
		}
		return result_vector;
	}

	vector<string> insert(string table, string variables, string values) {
		result_vector.clear();
		if (!conn)
		{
			result_vector.push_back("There is no connection");
			return result_vector;
		}
		form_insert_query(table, variables, values);
		if (!qstate)
		{
			result_vector.push_back("Insert Success:");
		}
		else
		{
			result_vector.push_back("Insert failed: " + mysql_errno(conn));
		}
		return result_vector;
	}

	vector<string> delete_(string table, string condition) {
		result_vector.clear();
		if (!conn)
		{
			result_vector.push_back("There is no connection");
			return result_vector;
		}
		form_delete_query(table, condition);
		if (!qstate)
		{
			result_vector.push_back("Insert Success:");
		}
		else
		{
			result_vector.push_back("Insert failed: " + mysql_errno(conn));
		}
		return result_vector;
	}

private:

	void form_select_query(string selector, string table, string condition) {
		query = "";
		if (condition != "") {
			query = "SELECT " + selector + " FROM " + table + " WHERE " + condition + ";";
		}
		else {
			query = "SELECT " + selector + " FROM " + table + ";";
		}
		const char* cquery = query.c_str();
		qstate = mysql_query(conn, cquery);
	}

	void form_update_query(string table, string set, string condition) {
		query = "";
		if (condition != "") {
			query = "UPDATE " + table + " SET " + set + " WHERE " + condition + ";";
		}
		else {
			query = "UPDATE " + table + " SET " + set + ";";
		}
		const char* cquery = query.c_str();
		qstate = mysql_query(conn, cquery);
	}

	void form_insert_query(string table, string variables, string values) {
		query = "INSERT INTO " + table + " " + variables + " VALUES " + values + ";";
		const char* cquery = query.c_str();
		qstate = mysql_query(conn, cquery);
	}

	void form_delete_query(string table, string condition) {
		query = "DELETE FROM " + table + " WHERE " + condition + ";";
		const char* cquery = query.c_str();
		qstate = mysql_query(conn, cquery);
	}

	void take_result_from_select() {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < mysql_num_fields(res); i++)
			{
				result_vector.push_back(row[i]);
			}
		}
	}


	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	vector<string> result_vector;
	string query;
	int qstate;
};

struct contestDB {

	contestDB() {
		DB = new  TestDataBase;
		admins = new Admins(DB);
		competitors = new Competitors(DB);
		tasks = new Tasks(DB);
		logs = new Logs(DB);
		contest = new Contest(admins, competitors, logs, tasks, DB);
	};

	TestDataBase* DB;
	Admins* admins;
	Competitors* competitors;
	Tasks* tasks;
	Logs* logs;
	Contest* contest;
};

/* Тестирование создания объектов. */

TEST(TestCreate, CreateAdmins) {
	TestDataBase base;
	Admins* admins = NULL;
	admins = new Admins(&base);
	EXPECT_TRUE(admins != NULL);
}

TEST(TestCreate, CreateCompetitors) {
	TestDataBase base;
	Competitors* competitors = NULL;
	competitors = new Competitors(&base);
	EXPECT_TRUE(competitors != NULL);
}

TEST(TestCreate, CreateLogs) {
	TestDataBase base;
	Logs* logs = NULL;
	logs = new Logs(&base);
	EXPECT_TRUE(logs != NULL);
}

TEST(TestCreate, CreateTasks) {
	TestDataBase base;
	Tasks* tasks = NULL;
	tasks = new Tasks(&base);
	EXPECT_TRUE(tasks != NULL);
}

TEST(TestCreate, CreateContest) {
	TestDataBase base;
	Contest* contest = NULL;
	contest = new Contest(NULL,NULL,NULL,NULL,&base);
	EXPECT_TRUE(contest != NULL);
}

TEST(TestCreate, CreateDataBase) {
	DataBaseMySQL* base = new DataBaseMySQL;
	EXPECT_TRUE(base != NULL);
}

/* Тестирование Admins */

TEST(TestAdmins, TestGetAdminsForContes) {
	contestDB* base = new contestDB();
	unsigned int contestID = 3;
	vector<AdminStruct> adminsList = base->admins->getAdminsForContest(contestID);
	ASSERT_TRUE(adminsList.size() > 0);
}

TEST(TestAdmins, TestGetAdmin) {
	contestDB* base = new contestDB();
	unsigned int adminID = 42;
	AdminStruct admin;
	admin = base->admins->getAdmin(adminID);
	ASSERT_TRUE(admin.admin_id != -1);
}


TEST(TestAdmins, TestAddAdmin) {
	contestDB* base = new contestDB();
	unsigned int userID = 10;
	unsigned int contestID = 3;
	bool result = base->admins->setAdmin(contestID, userID);
	ASSERT_TRUE(result);
}

/* Тестирование Competitors */

TEST(TestCompetitors, TestGetCompetitorsForContest) {
	contestDB* base = new contestDB();
	unsigned int contestID = 4;
	vector<CompetitorStruct> competitorslList = base->competitors->getCompetitorsForContest(contestID);
	ASSERT_TRUE(!competitorslList.empty());
}

TEST(TestCompetitors, TestGetCompetitor) {
	contestDB* base = new contestDB();
	unsigned int competitorID = 4;
	CompetitorStruct competitor = base->competitors->getCompetitor(competitorID);
	ASSERT_TRUE(competitor.competitor_id != -1);
}

TEST(TestCompetitors, TestSetCompetitor) {
	contestDB* base = new contestDB();
	int contest_id = 4;
	int user_id = 2;
	bool result = base->competitors->setCompetitor(contest_id, user_id);
	ASSERT_TRUE(result);
}


/* Тестирование Logs */

TEST(TestLogs, TestGetLog) {
	contestDB* base = new contestDB();
	unsigned int logID = 9;
	LogStruct log = base->logs->getLog(logID);
	ASSERT_TRUE(log.contest_id != -1);
}

TEST(TestLogs, TestGetLogsForContest) {
	contestDB* base = new contestDB();
	unsigned int contestID = 4;
	vector<LogStruct> logsList = base->logs->getLogsForContest(contestID);
	ASSERT_TRUE(!logsList.empty());
}

TEST(TestLogs, TestGetLogsForUser) {
	contestDB* base = new contestDB();
	unsigned int userID = 33;
	vector<LogStruct> logsList = base->logs->getLogsForUser(userID);
	ASSERT_TRUE(!logsList.empty());
}

TEST(TestLogs, TestAddLog) {
	contestDB* base = new contestDB();
	int user_id = 12;
	int contest_id = 4;
	string path;
	bool result = base->logs->addLog(path, user_id, contest_id);
	ASSERT_TRUE(result);
}

/* Тестирование Tasks */

TEST(TestTasks, TestGetTasksForContest) {
	contestDB* base = new contestDB();
	unsigned int contestID = 6;
	vector<TaskStruct> tasksList = base->tasks->getTasksForContest(contestID);
	ASSERT_TRUE(!tasksList.empty());
}

TEST(TestTasks, TestGetTask) {
	contestDB* base = new contestDB();
	unsigned int taskID = 6;
	TaskStruct task = base->tasks->getTask(taskID);
	ASSERT_TRUE(task.task_id != -1);
}

TEST(TestTasks, TestSetTask) {
	contestDB* base = new contestDB();
	string description = "[{}]";
	string settings = "[{}]";
	bool result = base->tasks->addTask(description, settings);
	ASSERT_TRUE(result);
}

/* Тестирование Contest */

TEST(TestContest, TestGetContestWithTitle) {
	contestDB* base = new contestDB();
	string contestTitle = "MyName";
	ContestStruct contest = base->contest->getContest(contestTitle);
	ASSERT_TRUE(contest.contest_id != -1);
}

TEST(TestContest, TestGetContestWithID) {
	contestDB* base = new contestDB();
	int contestID = 7;
	ContestStruct contest = base->contest->getContest(contestID);
	ASSERT_TRUE(contest.contest_id != -1);
}


TEST(TestContest, TestAddContest) {
	contestDB* base = new contestDB();
	int start_time = 4500;
	int end_time = 7000;
	string description = "[{}]";
	bool result = base->contest->setContest(start_time, end_time, description);
	ASSERT_TRUE(result);
}