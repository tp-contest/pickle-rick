#pragma once

#include <iostream>
#include "stdlib.h"

#define un unsigned

using namespace std;

class ITasks {
 public:
  string virtual getTasksForContest(un int contestID) = 0;
  string virtual getTask(un int taskID) = 0;
  string virtual getinfo(un int taskID) = 0;
  string virtual getSettings(un int taskID) = 0;
  bool virtual setInfo(un int taskID, string info) = 0;
  bool virtual setSettings(un int taskID, string settings) = 0;
};
