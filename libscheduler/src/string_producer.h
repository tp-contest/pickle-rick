#ifndef PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_
#define PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_

#include "data_container.h"
#include "producer.h"

class StringProducer : public Producer<std::string, DataContainer> {
 public:
  explicit StringProducer(Queue *queue) : Producer(queue) {}
  void Produce(const std::string &data) override {
    Push(DataContainer(0, data));
  }
};

#endif  // PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_
