#pragma once
#include "FileBase.h"

class CommonFileBase : public IFileBase {
public:
    CommonFileBase() {};
    ~CommonFileBase() {};
    void insert(IFile& file, std::string filename) {
        files.push_back(std::make_pair(file.getContent(), filename));
    }

    void remove(std::string name) { 
        for (auto i = files.begin(); i < files.end(); i++) {
            if (i->second == name) {
                files.erase(i);
            }
        }
    }

    void get(IFile& out, std::string name) {
        for (auto &file : files) {
            if (file.second == name) {
                out.setContent(file.first);
            }
        }
    }
private:
    std::vector<std::pair<std::vector<byte>, std::string>> files;
};