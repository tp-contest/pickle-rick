#pragma once
#include "ILinkGenerator.h"
#include "IStorage.h"

class Downloader: public ILinkGenerator {
public:
  Downloader(IStorage& _s) : s(_s) {}
  virtual std::string getLink(FileInfo& file);
private:
  IStorage& s;
};