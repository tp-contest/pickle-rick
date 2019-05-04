#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ITable {
private:
	string virtual getTable() = 0;
	string virtual getRow(un int ID) = 0;
	string virtual getColumn(un int ID, string columnName) = 0;
	bool virtual addRow(string row) = 0;
	bool virtual setRow(un int ID, string row) = 0;
	bool virtual deletRow(un int ID) = 0;
};