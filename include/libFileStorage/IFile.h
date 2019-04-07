#pragma once
#include <iostream>

class IFile {
public:
    void virtual SetContents(std::ifstream content) = 0;
    std::ofstream virtual GetContents() = 0;
};