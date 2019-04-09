#pragma once
#include <string>

class IFileSystemObject {
public:
    std::string virtual GetName() = 0;
};