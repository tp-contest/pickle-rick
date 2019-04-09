#pragma once
#include "IContestFileManager.h"

class ContestFileManagerInMemory : public IContestFileManager {
public:
    void SaveFile(const ContestantInfo&, File*);
    void FindFile(const ContestantInfo&, File*, std::string);
    void DeleteFile(const ContestantInfo&, std::string);

private:
    Folder* root;
    void SaveFile(IFileSystemObject*);
    void FindFile(File*, std::string);
    void DeleteFile(std::string);
};