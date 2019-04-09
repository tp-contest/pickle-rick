#include "ContestFileManagerInMemory.h"

void ContestFileManagerInMemory::SaveFile(const ContestantInfo&, File*) {
}

void ContestFileManagerInMemory::FindFile(const ContestantInfo&, File*, std::string) {
}

void ContestFileManagerInMemory::DeleteFile(const ContestantInfo&, std::string) {
}

void ContestFileManagerInMemory::SaveFile(IFileSystemObject*) {
}

void ContestFileManagerInMemory::FindFile(File*, std::string) {
}

void ContestFileManagerInMemory::DeleteFile(std::string) {
}
