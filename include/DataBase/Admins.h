#include <iostream>
#include "stdlib.h"
#include "IAdmins.h"
#include "IDataBase.h"

class Admins : public IAdmins {
public:
    Admins(DataBaseMySQL* dataBase){}
}