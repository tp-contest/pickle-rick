#pragma once
#include "IStorage.h"
#include "ContestFileInfo.h"
#include "ILinkGenerator.h"
// #include "Folder.h"

class ContestStorage {
public:
  ContestStorage(IStorage*, ILinkGenerator*);

  void saveFile(const ContestFileInfo&, std::string);
  IFile* findFile(const ContestFileInfo&);
  void deleteFile(const ContestFileInfo&);

  std::string serveFile(const ContestFileInfo&);

private:
  IStorage* storage; 
  ILinkGenerator* linkGen;
};