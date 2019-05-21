#include "MemoryFile.h"

MemoryFile::MemoryFile(const std::string& _name) : name(_name), content("") {
}

std::string MemoryFile::getName() const {
  return name;
}

std::string MemoryFile::getContent() const {
  return content;
}

void MemoryFile::setContent(const std::string& _content) {
  content = _content;
}