#pragma once

#include <iostream>
#include "stdlib.h"
#include <vector>

#define un unsigned

using namespace std;

class IDataBase {
public:
	vector<string> virtual select(string selector, string table, string condition = "") = 0;
	vector<string> virtual update(string table, string set, string condition = "") = 0;
	vector<string> virtual insert(string table, string variables, string values) = 0;
	vector<string> virtual delete_(string table, string condition) = 0;
};
