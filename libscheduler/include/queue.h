#ifndef PICKLE_RICK_QUEUE_H
#define PICKLE_RICK_QUEUE_H

#include <iostream>
#include <queue>

#include <boost/thread.hpp>

#include "data_container.h"
#include "i_queue.h"

class Queue : public IQueue<DataContainer> {
  std::queue<DataContainer, std::deque<DataContainer>> queue;
  boost::mutex m_mutex;
  boost::condition_variable m_cond;

  void Push(const DataContainer& data) override {
    boost::unique_lock<boost::mutex> lock(m_mutex);
    queue.push(data);
    m_cond.notify_one();
  }

  DataContainer Pop() override {
    boost::unique_lock<boost::mutex> lock(m_mutex);
    while (IsEmpty()) {
      m_cond.wait(lock);
    }

    DataContainer data = queue.front();
    queue.pop();
    return data;
  }

  bool IsEmpty() override {
    return queue.empty();
  }
};

#endif  // PICKLE_RICK_QUEUE_H
