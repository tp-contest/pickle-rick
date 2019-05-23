#ifndef PICKLE_RICK_PRODUCER_H
#define PICKLE_RICK_PRODUCER_H

#include "queue.h"

template <typename ContainerData>
class Producer {
 public:
  virtual void Produce(const ContainerData &data) = 0;

 protected:
  using Queue = IQueue<ContainerData>;
  explicit Producer(Queue *queue) : queue(queue){};
  void Push(const ContainerData &data) { queue->Push(data); }

 private:
  Queue *queue;
};

#endif  // PICKLE_RICK_PRODUCER_HT
