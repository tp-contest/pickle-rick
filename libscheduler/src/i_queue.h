#ifndef PICKLE_RICK_I_QUEUE_H
#define PICKLE_RICK_I_QUEUE_H

template <typename T>
class IQueue {
 public:
  virtual void Push(const T&) = 0;
  virtual T Pop() = 0;
};

#endif  // PICKLE_RICK_I_QUEUE_H
