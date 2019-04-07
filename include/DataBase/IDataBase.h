#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class IDataBase {
public:
    string virtual select(string request) = 0;
    string virtual update(string request) = 0;
    string virtual insert(string request) = 0;
    string virtual delet(string request) = 0;
};
