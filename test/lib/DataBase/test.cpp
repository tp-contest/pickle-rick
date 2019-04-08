#include "gtest/gtest.h"

class TestDataBase : public IDataBase {
  friend class Admins;
  friend class Competitors;
  friend class Contest;
  friend class logs;
  friend class Tasks;

 public:
  TestDataBase() {
    this->admins = new Admins(this);
    this->competitors = new Competitors(this);
    this->logs = new Logs(this);
    this->tasks = new Tasks(this);
    this->contest = new Contest(admins, competitors, logs, tasks, this);
    // cout << "dataBaseMySQL created" << endl;
  }
  string select(string request) { return "none"; }
  string update(string request) { return "none"; }
  string insert(string request) { return "none"; }
  string delet(string request) { return "none"; }

  Admins* admins;
  Competitors* competitors;
  Contest* contest;
  Logs* logs;
  Tasks* tasks;

 private:
  void method();
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
  contest = new Contest(NULL, NULL, NULL, NULL, &base);
  EXPECT_TRUE(contest != NULL);
}

TEST(TestCreate, CreateDataBase) {
  DataBaseMySQL* base = new DataBaseMySQL;
  EXPECT_TRUE(base != NULL);
}

/* Тестирование Admins */

TEST(TestAdmins, TestGetAdminsForContes) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 3;
  string adminsList = base->admins->getAdminsForContest(contestID);
  ASSERT_TRUE(adminsList == "[{}]");
}

TEST(TestAdmins, TestGetAdmin) {
  TestDataBase* base = new TestDataBase();
  unsigned int adminID = 42;
  string admin = base->admins->getAdmin(adminID);
  ASSERT_TRUE(admin == "[{}]");
}

TEST(TestAdmins, TestGetPermissions) {
  TestDataBase* base = new TestDataBase();
  unsigned int adminID = 10;
  string permissions = base->admins->getPermissions(adminID);
  ASSERT_TRUE(permissions == "[{}]");
}

TEST(TestAdmins, TestSetPermissions) {
  TestDataBase* base = new TestDataBase();
  unsigned int adminID = 10;
  string permissions;
  bool result = base->admins->setPermissions(adminID, permissions);
  ASSERT_TRUE(result);
}

TEST(TestAdmins, TestAddAdmin) {
  TestDataBase* base = new TestDataBase();
  unsigned int userID = 10;
  unsigned int contestID = 3;
  bool result = base->admins->addAdmin(contestID, userID);
  ASSERT_TRUE(result);
}

/* Тестирование Competitors */

TEST(TestCompetitors, TestGetCompetitorsForContest) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 4;
  string competitorslList =
      base->competitors->getCompetitorsForContest(contestID);
  ASSERT_TRUE(competitorslList == "[{}]");
}

TEST(TestCompetitors, TestGetCompetitor) {
  TestDataBase* base = new TestDataBase();
  unsigned int competitorID = 4;
  string competitor = base->competitors->getCompetitor(competitorID);
  ASSERT_TRUE(competitor == "[{}]");
}

TEST(TestCompetitors, TestGetPersonalScore) {
  TestDataBase* base = new TestDataBase();
  unsigned int competitorID = 4;
  unsigned int score = base->competitors->getPersonalScore(competitorID);
  ASSERT_TRUE(score >= 0);
}

TEST(TestCompetitors, TestGetRateList) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 4;
  string rateList = base->competitors->getRateList(contestID);
  ASSERT_TRUE(rateList == "[{}]");
}

TEST(TestCompetitors, TestGetCompletedTasks) {
  TestDataBase* base = new TestDataBase();
  unsigned int competitorID = 4;
  string tasksList = base->competitors->getCompletedTasks(competitorID);
  ASSERT_TRUE(tasksList == "[{}]");
}

TEST(TestCompetitors, TestSetCompletedTasks) {
  TestDataBase* base = new TestDataBase();
  unsigned int competitorID = 4;
  string tasksList = "[{}]";
  bool result = base->competitors->setCompletedTasks(tasksList, competitorID);
  ASSERT_TRUE(tasksList == "[{}]");
}

TEST(TestCompetitors, TestAddCompetitor) {
  TestDataBase* base = new TestDataBase();
  unsigned int userID = 4;
  unsigned int contestID = 4;
  bool result = base->competitors->addCompetitor(contestID, userID);
  ASSERT_TRUE(result);
}

/* Тестирование Logs */

TEST(TestLogs, TestGetLog) {
  TestDataBase* base = new TestDataBase();
  unsigned int logID = 9;
  string log = base->logs->getLog(logID);
  ASSERT_TRUE(log == "[{}]");
}

TEST(TestLogs, TestGetLogsForContest) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 4;
  string logsList = base->logs->getLogsForContest(contestID);
  ASSERT_TRUE(logsList == "[{}]");
}

TEST(TestLogs, TestGetLogsForUser) {
  TestDataBase* base = new TestDataBase();
  unsigned int userID = 33;
  string logsList = base->logs->getLogsForUser(userID);
  ASSERT_TRUE(logsList == "[{}]");
}

TEST(TestLogs, TestAddLog) {
  TestDataBase* base = new TestDataBase();
  string log = "[{}]";
  bool result = base->logs->addLog(log);
  ASSERT_TRUE(result);
}

/* Тестирование Tasks */

TEST(TestTasks, TestGetTasksForContest) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 6;
  string tasksList = base->tasks->getTasksForContest(contestID);
  ASSERT_TRUE(tasksList == "[{}]");
}

TEST(TestTasks, TestGetTask) {
  TestDataBase* base = new TestDataBase();
  unsigned int taskID = 6;
  string task = base->tasks->getTask(taskID);
  ASSERT_TRUE(task == "[{}]");
}

TEST(TestTasks, TestGetInfo) {
  TestDataBase* base = new TestDataBase();
  unsigned int taskID = 6;
  string taskInfo = base->tasks->getinfo(taskID);
  ASSERT_TRUE(taskInfo == "[{}]");
}

TEST(TestTasks, TestGetSettings) {
  TestDataBase* base = new TestDataBase();
  unsigned int taskID = 6;
  string taskSettings = base->tasks->getSettings(taskID);
  ASSERT_TRUE(taskSettings == "[{}]");
}

TEST(TestTasks, TestSetInfo) {
  TestDataBase* base = new TestDataBase();
  string info = "[{}]";
  unsigned taskID = 12;
  bool result = base->tasks->setInfo(taskID, info);
  ASSERT_TRUE(result);
}

TEST(TestTasks, TestSetSettings) {
  TestDataBase* base = new TestDataBase();
  string settings = "[{}]";
  unsigned taskID = 12;
  bool result = base->tasks->setInfo(taskID, settings);
  ASSERT_TRUE(result);
}

/* Тестирование Contest */

TEST(TestContest, TestGetID) {
  TestDataBase* base = new TestDataBase();
  string contestTitle = "MyName";
  unsigned int contestID = base->contest->getID(contestTitle);
  ASSERT_TRUE(contestID == 42);
}

TEST(TestContest, TestGetInfo) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 7;
  string info = base->contest->getInfo(contestID);
  ASSERT_TRUE(info == "[{}]");
}

TEST(TestContest, TestGetStartTime) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 7;
  string startTime = base->contest->getStartTime(contestID);
  ASSERT_TRUE(startTime == "[{}]");
}

TEST(TestContest, TestGetEndTime) {
  TestDataBase* base = new TestDataBase();
  unsigned int contestID = 7;
  string endTime = base->contest->getEndTime(contestID);
  ASSERT_TRUE(endTime == "[{}]");
}

TEST(TestContest, TestAddContest) {
  TestDataBase* base = new TestDataBase();
  string settings = "[{}]";
  string title = "[{}]";
  string info = "[[]]";
  bool result = base->contest->addContest(title, info, settings);
  ASSERT_TRUE(result);
}

TEST(TestContest, TestSetInfo) {
  TestDataBase* base = new TestDataBase();
  string info = "[{}]";
  unsigned int contestID = 7;
  bool result = base->contest->setInfo(contestID, info);
  ASSERT_TRUE(result);
}

TEST(TestContest, TestSetEndTime) {
  TestDataBase* base = new TestDataBase();
  string endTime = "[{}]";
  unsigned int contestID = 7;
  bool result = base->contest->setInfo(contestID, endTime);
  ASSERT_TRUE(result);
}
