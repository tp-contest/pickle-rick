/**
 * Pickle Rick API
 * No description provided (generated by Openapi Generator
 * https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 1.0.1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
/*
 * TaskId.h
 *
 *
 */

#ifndef TaskId_H_
#define TaskId_H_

#include <nlohmann/json.hpp>

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
///
/// </summary>
class TaskId {
 public:
  TaskId();
  virtual ~TaskId();

  void validate();

  /////////////////////////////////////////////
  /// TaskId members

  /// <summary>
  ///
  /// </summary>
  int32_t getTaskId() const;
  void setTaskId(int32_t const value);

  friend void to_json(nlohmann::json& j, const TaskId& o);
  friend void from_json(const nlohmann::json& j, TaskId& o);

 protected:
  int32_t m_Task_id;
};

}  // namespace model
}  // namespace server
}  // namespace openapitools
}  // namespace org

#endif /* TaskId_H_ */
