#ifndef PICKLE_RICK_CONSUMER_H
#define PICKLE_RICK_CONSUMER_H

#include "queue.h"

template <typename ContainerData>
class Consumer {
 public:
  virtual void Consume() = 0;
 protected:
  using Queue = IQueue<ContainerData>;
  explicit Consumer(Queue *queue) : queue(queue){};
  ContainerData Pop() { return queue->Pop(); }

 private:
  Queue *queue;
};

#endif //PICKLE_RICK_CONSUMER_H
