#pragma once
#include "IFile.h"

class MemoryFile: public IFile {
public:
  explicit MemoryFile(const std::string&);

  std::string virtual getName() const;
  std::string virtual getContent() const;
  virtual void setContent(const std::string&);

private:
  std::string name;
  std::string content;
};