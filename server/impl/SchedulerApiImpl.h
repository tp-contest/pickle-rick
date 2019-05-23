#ifndef SCHEDULER_API_IMPL_H_
#define SCHEDULER_API_IMPL_H_

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <iostream>
#include <memory>

#include <SchedulerApi.h>

#include <pistache/optional.h>

#include "Task.h"
#include "scheduler.h"

namespace org {
namespace openapitools {
namespace server {
namespace api {

using namespace org::openapitools::server::model;

class SchedulerApiImpl : public org::openapitools::server::api::SchedulerApi {
 public:
  SchedulerApiImpl(std::shared_ptr<Pistache::Rest::Router>);
  ~SchedulerApiImpl() {}

  void send_task(const Task &task, Pistache::Http::ResponseWriter &response);

 private:
  Scheduler scheduler;
};

}  // namespace api
}  // namespace server
}  // namespace openapitools
}  // namespace org

#endif