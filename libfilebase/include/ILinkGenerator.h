#pragma once
#include "FileInfo.h"

class ILinkGenerator {
public:
  virtual std::string getLink(FileInfo& file) = 0;
};