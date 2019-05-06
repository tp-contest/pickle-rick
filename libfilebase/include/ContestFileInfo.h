#pragma once
#include "FileInfo.h"

struct ContestFileInfo: public FileInfo {
  int contestID;
  int contestantID;
};