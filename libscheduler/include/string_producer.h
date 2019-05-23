#ifndef PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_
#define PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_

#include "data_container.h"
#include "producer.h"

class StringProducer : public Producer<DataContainer> {
 public:
  explicit StringProducer(Queue *queue) : Producer(queue) {}
  void Produce(const DataContainer &data) override { Push(data); }
};

#endif  // PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_
