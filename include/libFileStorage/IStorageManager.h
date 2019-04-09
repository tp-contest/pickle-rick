#pragma once
#include "IFileSystemObject.h"
#include "File.h"
#include "Folder.h"

class IStorageManager {
public:
    void virtual SaveFile(IFileSystemObject*) = 0;
    void virtual FindFile(File*, std::string) = 0;
    void virtual DeleteFile(std::string) = 0;
};