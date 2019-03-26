#pragma once
#include <vector>

typedef char byte;

class IFile {
public:
    void virtual setContent(std::vector<byte>) = 0;
    std::vector<byte> virtual getContent() = 0;
};


