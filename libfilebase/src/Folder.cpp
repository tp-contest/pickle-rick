#include "Folder.h"

Folder::Folder(const std::string& name) : name(name) {
}

std::string Folder::getName() const {
  return name;
}


void Folder::addFileObject(IFileSystemObject* object) {
  objects.push_back(object);
}

IFileSystemObject* Folder::getFileObject(const std::string &name) const {
  IFileSystemObject* result = nullptr;

  for (auto const& obj: objects) {
     if (obj->getName() == name) {
       result = obj;
       break;
     }
  }

  return result;
}

void Folder::removeFileObject(std::string name) {
  for (auto begin = objects.begin(); begin != objects.end(); begin++) {
    if ((*begin)->getName() == name) {
      objects.erase(begin);
    }
  }
}
