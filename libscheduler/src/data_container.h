#ifndef PICKLE_RICK_DATA_CONTAINER_H
#define PICKLE_RICK_DATA_CONTAINER_H

#include <string>

struct DataContainer {
  int header;
  std::string data;
  DataContainer(int header, std::string data)
      : header(header), data(std::move(data)) {}
};

#endif  // PICKLE_RICK_DATA_CONTAINER_H
