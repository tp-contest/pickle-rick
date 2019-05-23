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

#include "UserData.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

UserData::UserData() {
  m_User_password = "";
  m_User_name = "";
}

UserData::~UserData() {}

void UserData::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const UserData& o) {
  j = nlohmann::json();
  j["user_password"] = o.m_User_password;
  j["user_name"] = o.m_User_name;
}

void from_json(const nlohmann::json& j, UserData& o) {
  j.at("user_password").get_to(o.m_User_password);
  j.at("user_name").get_to(o.m_User_name);
}

std::string UserData::getUserPassword() const { return m_User_password; }
void UserData::setUserPassword(std::string const& value) {
  m_User_password = value;
}
std::string UserData::getUserName() const { return m_User_name; }
void UserData::setUserName(std::string const& value) { m_User_name = value; }

}  // namespace model
}  // namespace server
}  // namespace openapitools
}  // namespace org
