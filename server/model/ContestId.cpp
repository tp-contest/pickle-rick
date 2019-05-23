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

#include "ContestId.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

ContestId::ContestId() { m_Contest_id = 0; }

ContestId::~ContestId() {}

void ContestId::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const ContestId& o) {
  j = nlohmann::json();
  j["contest_id"] = o.m_Contest_id;
}

void from_json(const nlohmann::json& j, ContestId& o) {
  j.at("contest_id").get_to(o.m_Contest_id);
}

int32_t ContestId::getContestId() const { return m_Contest_id; }
void ContestId::setContestId(int32_t const value) { m_Contest_id = value; }

}  // namespace model
}  // namespace server
}  // namespace openapitools
}  // namespace org
