#include "FileSystem.h"
FileSystem::FileSystem() {
  root = new Folder("/");
}

void FileSystem::saveFile(const FileInfo& info, std::string content) {
  std::string filename = info.fileName;
  std::istringstream path(filename);
  std::string temp_str;
  // getline(path, temp_str, '/');
  IFileSystemObject* tempObject = root;
  while (getline(path, temp_str, '/')) {
    //Дошли до названия файла
    if (path.eof()) {
      MemoryFile* newFile = new MemoryFile(temp_str);
      newFile->setContent(content);
      if(auto folder = dynamic_cast<Folder*>(tempObject)) {
        folder->addFileObject(newFile);
        // std::cout << "Saved file: " << newFile->getName() << std::endl;
      }
    }
    else {
      if(auto folder = dynamic_cast<Folder*>(tempObject)) {
        if (auto nextObject = folder->getFileObject(temp_str)) {
          if (auto nextFolder = static_cast<Folder*>(nextObject)) {
            tempObject = nextFolder;
          }
        } else {
          //Нету папки с таким названием; Нужно создать
          auto newFolder = new Folder(temp_str);
          folder->addFileObject(newFolder);
          // std::cout << "Created folder: " << temp_str << std::endl;
          tempObject = newFolder;
        }
      }
    }
  } 
}

IFile* FileSystem::findFile(const FileInfo& info) {
  std::string filename = info.fileName;
  std::istringstream path(filename);
  std::string temp_str;
  IFileSystemObject* tempObject = root;

  IFile* retFile = nullptr;

  while (getline(path, temp_str, '/')) {
    //Дошли до названия файла
    if (path.eof()) {
      if(auto folder = dynamic_cast<Folder*>(tempObject)) {
        if (retFile = dynamic_cast<IFile*>(folder->getFileObject(temp_str))) {
          break;
        }
      } else {
        std::cerr
          << "Error! Coudn't cast tempObject("
          << tempObject->getName()
          << ") to *Folder!"
          << std::endl;
      }
    }
    else {
      if(auto folder = dynamic_cast<Folder*>(tempObject)) {
        if (auto nextObject = folder->getFileObject(temp_str)) {
          if (auto nextFolder = static_cast<Folder*>(nextObject)) {
            tempObject = nextFolder;
          }
        } else {
          //Нету папки с таким названием; Ошибка, такой файл не добавляли.
          std::cerr << "Error! Folder not found: " << temp_str << std::endl;
        }
      } else {
        std::cerr
          << "Error! Coudn't cast tempObject("
          << tempObject->getName()
          << ") to *Folder!"
          << std::endl;
      }
    }
  } 

  return retFile;
}

void FileSystem::deleteFile(const FileInfo& info) {

}
