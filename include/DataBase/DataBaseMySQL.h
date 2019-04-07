#include <iostream>
#include "stdlib.h"
#include "Admins.h"
#include "Competitors.h"
#include "Contest.h"
#include "Logs.h"
#include "Tasks.h"
#include "IDataBase.h"

class DataBaseMySQL : public IDataBase {
    friend class Admins;
    friend class Competitors;
    friend class Contest;
    friend class logs;
    friend class Tasks;
public:
    DataBaseMySQL() {
        this->admins = new Admins(this);
        this->competitors = new Competitors(this);
        this->logs = new Logs(this);
        this->tasks = new Tasks(this);
        this->contest = new Contest(admins, competitors, logs, tasks, this);
    }
    Admins *admins;
    Competitors *competitors;
    Contest *contest;
    Logs *logs;
    Tasks *tasks;
private:
    void method();
};