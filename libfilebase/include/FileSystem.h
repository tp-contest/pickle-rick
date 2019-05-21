#pragma once
#include <sstream>
#include <iostream>
#include "IStorage.h"
#include "Folder.h"
#include "MemoryFile.h"

class FileSystem : public IStorage {
public:
  FileSystem();
  virtual void saveFile(const FileInfo&, std::string);
  virtual IFile* findFile(const FileInfo&);
  virtual void deleteFile(const FileInfo&);

private:
  Folder* root;
};