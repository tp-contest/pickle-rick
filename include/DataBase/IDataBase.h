#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class IDataBase {
public:
    string virtual select(string request);
    string virtual update(string request);
    string virtual insert(string request);
    string virtual delet(string request);
};
