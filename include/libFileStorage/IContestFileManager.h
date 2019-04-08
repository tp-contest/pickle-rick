#pragma once
#include "IStorageManager.h"
#include "ContestantInfo.h"

class IContestFileManager : public IStorageManager {
public:
    void virtual SaveFile(const ContestantInfo&, File*) = 0;
    void virtual FindFile(const ContestantInfo&, File*, std::string) = 0;
    void virtual DeleteFile(const ContestantInfo&, std::string) = 0;
};