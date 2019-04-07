#include <iostream>
#include "libFileStorage/IFile.h"
#include "libFileStorage/IStorage.h"

class TextFile : public IFile {
public:

private:

};

class MemoryStorage : public IStorage {
public:
    int virtual SaveFile (IFile&&) { 
        
    }

    void virtual GetFile (IFile&, int) {

    }
    void virtual DeleteFile (int) {

    }
private:

};

int main() {
    auto ms1 = MemoryStorage();
}