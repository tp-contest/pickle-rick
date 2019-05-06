#ifndef PICKLE_RICK_QUEUE_H
#define PICKLE_RICK_QUEUE_H

#include "queue"
#include "vector"

#include "data_container.h"
#include "i_queue.h"

template <class Compare>
class Queue : public IQueue<DataContainer> {
  std::priority_queue<DataContainer, std::vector<DataContainer>, Compare> queue;
  void Push(const DataContainer& data) override { queue.push(data); }

  DataContainer Pop() override {
    auto data = queue.front();
    queue.pop();
    return data;
  }
};

#endif  // PICKLE_RICK_QUEUE_H
