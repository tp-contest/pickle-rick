#pragma once
#include <string>
#include "FileInfo.h"
#include "IFile.h"

class IStorage {
public:
  virtual void saveFile(const FileInfo&, std::string) = 0;
  virtual IFile* findFile(const FileInfo&) = 0;
  virtual void deleteFile(const FileInfo&) = 0;
};