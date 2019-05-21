#pragma once
#include <string>
#include <vector>
#include "IFileSystemObject.h"

class Folder: public IFileSystemObject {
public:
  explicit Folder(const std::string&);

  std::string virtual getName() const;
  void addFileObject(IFileSystemObject*);
  IFileSystemObject* getFileObject(const std::string&) const;
  void removeFileObject(std::string);

private:
  std::vector<IFileSystemObject*> objects;
  std::string name;
};