#pragma once
#include <vector>
#include "IFileSystemObject.h"

class Folder : public IFileSystemObject {
public:
    Folder(std::string);
    ~Folder();

    std::string GetName();
    
    void AddFileObject(IFileSystemObject*);
    void RemoveFileObject(std::string);
    void GetFileObject(IFileSystemObject*, std::string);
private:
    std::string name;
    std::vector<IFileSystemObject*> objects;
};