#pragma once
#include "IFileSystemObject.h"

class IFile: public IFileSystemObject {
public:
  std::string virtual getName() const = 0;
  std::string virtual getContent() const = 0;
  virtual void setContent(const std::string&) = 0;
};