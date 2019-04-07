#pragma once
#include "IFile.h"


class IStorage {
public:
    int virtual SaveFile (IFile&&) = 0;
    void virtual GetFile (IFile&, int) = 0;
    void virtual DeleteFile (int) = 0;
};