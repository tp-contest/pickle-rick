#pragma once

#include <functional>
#include <iostream>
#include <thread>

#include "data_container.h"
#include "queue.h"
#include "string_consumer.h"
#include "string_producer.h"

class Scheduler {
  std::thread thread;

  void Work() {
    consumer.Consume();
  }

  static void Worker(Scheduler *scheduler) {
    while(true) {
      scheduler->Work();
    }
  }
 public:
  Scheduler()
      : queue(),
        consumer(&queue),
        producer(std::make_shared<StringProducer>(StringProducer(&queue))) {}

  void ServeThread() {
     thread = std::thread(Worker, this);
  }

  void Push(const DataContainer &data) {
    producer->Produce(data);
  }

 private:
  Queue queue;
  StringConsumer consumer;
  std::shared_ptr<StringProducer> producer;
};
