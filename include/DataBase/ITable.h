#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ITable {
public:
    string virtual getTable();
    string virtual getRow(un int ID);
    string virtual getColumn(un int ID, string columnName);
    bool virtual addRow(string row);
    bool virtual setRow(un int ID, string row);
    bool virtual deletRow(un int ID);
};