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
 * SolutionId.h
 *
 *
 */

#ifndef SolutionId_H_
#define SolutionId_H_

#include <nlohmann/json.hpp>

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
///
/// </summary>
class SolutionId {
 public:
  SolutionId();
  virtual ~SolutionId();

  void validate();

  /////////////////////////////////////////////
  /// SolutionId members

  /// <summary>
  ///
  /// </summary>
  int32_t getSolutionId() const;
  void setSolutionId(int32_t const value);

  friend void to_json(nlohmann::json& j, const SolutionId& o);
  friend void from_json(const nlohmann::json& j, SolutionId& o);

 protected:
  int32_t m_Solution_id;
};

}  // namespace model
}  // namespace server
}  // namespace openapitools
}  // namespace org

#endif /* SolutionId_H_ */
