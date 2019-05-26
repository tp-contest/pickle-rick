#pragma once

#include <functional>
#include <iostream>
#include <thread>

#include "data_container.h"
#include "queue.h"
#include "string_consumer.h"
#include "string_producer.h"

template <typename ContainerData>
class Scheduler {
  std::thread thread;

  void Work() {
    consumer.Consume();
  }

  static void Worker(Scheduler<ContainerData>  *scheduler) {
    while(true) {
      scheduler->Work();
    }
  }
 public:
  Scheduler()
      : queue(),
        consumer(&queue),
        producer(std::make_shared<StringProducer<ContainerData>>(StringProducer(&queue))) {}

  void ServeThread() {
     thread = std::thread(Worker, this);
  }

  void Push(const ContainerData &data) {
    producer->Produce(data);
  }

 private:
  Queue<ContainerData> queue;
  StringConsumer<ContainerData> consumer;
  std::shared_ptr<StringProducer<ContainerData>> producer;
};
