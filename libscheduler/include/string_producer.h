#ifndef PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_
#define PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_

#include "data_container.h"
#include "producer.h"

template <typename ContainerData>
class StringProducer : public Producer<ContainerData> {
 public:
  explicit StringProducer(Queue<ContainerData> *queue)
      : Producer<ContainerData>(queue) {}
  void Produce(const ContainerData &data) override {
    Producer<ContainerData>::Push(data);
  }
};

#endif  // PICKLE_RICK_LIBSCHEDULER_SRC_PRODUCER_CPP_STRING_PRODUCER_H_
