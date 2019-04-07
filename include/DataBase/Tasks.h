#include <iostream>
#include "stdlib.h"
#include "ITasks.h"
#include "IDataBase.h"

class Tasks : public ITasks {
public:
    Tasks(IDataBase* dataBase){}

}