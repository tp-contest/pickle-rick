#pragma once
#include "File.h"

class IFileBase {
public:
    void virtual insert(IFile&, std::string) = 0;
    void virtual remove(std::string) = 0;
    void virtual get(IFile&, std::string) = 0;
};

