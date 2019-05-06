#pragma once
#include <string>

class IFileSystemObject {
public:
  std::string virtual getName() const = 0;
};