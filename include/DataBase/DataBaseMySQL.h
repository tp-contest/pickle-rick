#include "Admins.h"
#include "Competitors.h"
#include "Contest.h"
#include "Logs.h"
#include "Tasks.h"
#include "IDataBase.h"



class DataBaseMySQL : public IDataBase {
public:
    DataBaseMySQL() {
        this->admins = new Admins;
        this->competitors = new Competitors;
        this->logs = new Logs;
        this->tasks = new Tasks;
        this->contest = new Contest(admins, competitorsm, logs, tasks);
    }
    Admins *admins;
    Competitors *competitors;
    Contest *contest;
    logs *logs;
    Tasks *tasks;
private:
    void method();
};