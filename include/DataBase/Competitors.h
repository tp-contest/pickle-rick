#include <iostream>
#include "stdlib.h"
#include "ICompetitors.h"
#include "IDataBase.h"

class Competitors : public ICompetitors {
public:
    Competitors(IDataBase* dataBase){}

}