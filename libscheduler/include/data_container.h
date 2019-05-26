#ifndef PICKLE_RICK_DATA_CONTAINER_H
#define PICKLE_RICK_DATA_CONTAINER_H

#include <cstdint>

struct DataContainer {
  int32_t taskId;
  int32_t userId;
  int32_t contestId;
  int32_t taskFileId;
};

#endif  // PICKLE_RICK_DATA_CONTAINER_H