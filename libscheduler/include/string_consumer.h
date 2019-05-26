#ifndef PICKLE_RICK_LIBSCHEDULER_SRC_STRING_CONSUMER_H_
#define PICKLE_RICK_LIBSCHEDULER_SRC_STRING_CONSUMER_H_

#include <memory>
#include <vector>

#include "consumer.h"
#include "data_container.h"
#include "iostream"

#include "WorkerApi.h"
#include "Task.h"

using org::openapitools::client::api::ApiClient;
using org::openapitools::client::api::ApiConfiguration;
using org::openapitools::client::api::WorkerApi;
using org::openapitools::client::api::Task;

template <typename ContainerData>
class StringConsumer : public Consumer<ContainerData> {
 private:
  std::shared_ptr<ApiConfiguration> configuration;
  std::shared_ptr<ApiClient> client;
  WorkerApi wa;

 public:
  explicit StringConsumer(Queue<ContainerData> *queue)
      : Consumer<ContainerData>(queue),
        configuration(std::make_shared<ApiConfiguration>()),
        client(std::make_shared<ApiClient>(configuration)),
        wa(client) {
    configuration.get()->setBaseUrl(
        "https://virtserver.swaggerhub.com/kirilllivanov/tp-contest-worker/"
        "1.0.0");
  }

  void Consume() override {
    auto slots = wa.freeSlots();
    int slotsCount = slots.get()[0]->getCount();
    while(slotsCount != 0 && !Consumer<ContainerData>::IsEmpty()) {
      ContainerData data = Consumer<ContainerData>::Pop();
      std::cout << data.taskId << std::endl;
      auto task = std::make_shared<Task>();
      task->setTaskId(data.taskId);
      task->setUserId(data.userId);
      task->setContestId(data.contestId);
      task->setTaskFileId(data.taskFileId);
      std::vector<std::shared_ptr<Task>> taskVector;
      taskVector.push_back(task);
      wa.sendTask(taskVector);
      slotsCount--;
    }
    sleep(1);
  }
};

#endif  // PICKLE_RICK_LIBSCHEDULER_SRC_STRING_CONSUMER_H_
