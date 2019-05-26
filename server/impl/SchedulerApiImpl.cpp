#include <iostream>
#include <memory>

#include "SchedulerApiImpl.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

SchedulerApiImpl::SchedulerApiImpl(
    std::shared_ptr<Pistache::Rest::Router> rtr,
    const std::shared_ptr<Scheduler<DataContainer>> &scheduler)
    : SchedulerApi(rtr), scheduler(scheduler) {
  scheduler->ServeThread();
}

void SchedulerApiImpl::send_task(const Task &task,
                                 Pistache::Http::ResponseWriter &response) {
  DataContainer data;
  data.taskId = task.getTaskId();
  data.userId = task.getUserId();
  data.contestId = task.getContestId();
  data.taskFileId = task.getTaskFileId();

  scheduler->Push(data);
  response.send(Pistache::Http::Code::Ok, "Do some magic\n");
}

}  // namespace api
}  // namespace server
}  // namespace openapitools
}  // namespace org
