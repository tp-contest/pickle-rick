#pragma once
#include "IStorage.h"
#include "ContestFileInfo.h"
#include "Folder.h"

class ContestStorage {
public:
  explicit ContestStorage(IStorage*);

  void saveFile(const ContestFileInfo&, std::string);
  IFile* findFile(const ContestFileInfo&);
  void deleteFile(const ContestFileInfo&);

private:
  IStorage* storage; 
};