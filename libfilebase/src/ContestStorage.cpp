#include "ContestStorage.h"

ContestStorage::ContestStorage(IStorage* storageMethod) {
  storage = storageMethod;
}

void ContestStorage::saveFile(const ContestFileInfo& contestFile, std::string content) {
  auto tempFileInfo = FileInfo();
  tempFileInfo.fileName = 
    std::to_string(contestFile.contestID) + "/" +
    std::to_string(contestFile.contestantID) + "/" + 
    contestFile.fileName;
  storage->saveFile(tempFileInfo, content);
}

IFile* ContestStorage::findFile(const ContestFileInfo& contestFile) {
  auto tempFileInfo = FileInfo();
  tempFileInfo.fileName = 
    std::to_string(contestFile.contestID) + "/" +
    std::to_string(contestFile.contestantID) + "/" +
    contestFile.fileName;
    return storage->findFile(tempFileInfo);
}

void ContestStorage::deleteFile(const ContestFileInfo& contestFile) {
  auto tempFileInfo = FileInfo();
  tempFileInfo.fileName = 
    std::to_string(contestFile.contestID) + 
    std::to_string(contestFile.contestantID) + 
    contestFile.fileName;
  storage->deleteFile(tempFileInfo);
}