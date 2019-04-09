#pragma once
#include "IFileSystemObject.h"
#include <vector>

class File : public IFileSystemObject {
public:
    explicit File(std::string);
    ~File();

    std::string GetName();
    std::vector<char> GetContent();
    void SetContent(const std::vector<char>&);
private:
    std::string name;
    std::vector<char> content;
};