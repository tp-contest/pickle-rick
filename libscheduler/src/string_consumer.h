#ifndef PICKLE_RICK_LIBSCHEDULER_SRC_STRING_CONSUMER_H_
#define PICKLE_RICK_LIBSCHEDULER_SRC_STRING_CONSUMER_H_

#include "consumer.h"
#include "data_container.h"
#include "iostream"

class StringConsumer : public Consumer<DataContainer> {
 public:
  explicit StringConsumer(Queue *queue) : Consumer(queue) {}
  void Consume() override {
    DataContainer data = Pop();
    std::cout << data.data << std::endl;
  }
};

#endif  // PICKLE_RICK_LIBSCHEDULER_SRC_STRING_CONSUMER_H_
