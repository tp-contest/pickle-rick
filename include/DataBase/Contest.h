#include <iostream>
#include "stdlib.h"
#include "IContest.h"
#include "IDataBase.h"

class Contest : public IContest {
public:
    Contest(Admins* admins, Competitors* competitors, Logs* logs, Tasks* tasks, IDataBase* dataBase){}
    
}