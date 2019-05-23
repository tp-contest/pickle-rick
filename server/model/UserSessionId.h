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
 * UserSessionId.h
 *
 *
 */

#ifndef UserSessionId_H_
#define UserSessionId_H_

#include <nlohmann/json.hpp>
#include "SessionId.h"
#include "UserId.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
///
/// </summary>
class UserSessionId {
 public:
  UserSessionId();
  virtual ~UserSessionId();

  void validate();

  /////////////////////////////////////////////
  /// UserSessionId members

  /// <summary>
  ///
  /// </summary>
  int32_t getUserId() const;
  void setUserId(int32_t const value);
  /// <summary>
  ///
  /// </summary>
  int32_t getSessionId() const;
  void setSessionId(int32_t const value);

  friend void to_json(nlohmann::json& j, const UserSessionId& o);
  friend void from_json(const nlohmann::json& j, UserSessionId& o);

 protected:
  int32_t m_User_id;

  int32_t m_Session_id;
};

}  // namespace model
}  // namespace server
}  // namespace openapitools
}  // namespace org

#endif /* UserSessionId_H_ */
