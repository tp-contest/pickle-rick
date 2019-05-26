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

#include "Contest.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

Contest::Contest() {
  m_Contest_id = 0;
  m_User_id = 0;
  m_Input_file_id = 0;
  m_Output_file_id = 0;
  m_Description_file_id = 0;
}

Contest::~Contest() {}

void Contest::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const Contest& o) {
  j = nlohmann::json();
  j["contest_id"] = o.m_Contest_id;
  j["user_id"] = o.m_User_id;
  j["input_file_id"] = o.m_Input_file_id;
  j["output_file_id"] = o.m_Output_file_id;
  j["description_file_id"] = o.m_Description_file_id;
}

void from_json(const nlohmann::json& j, Contest& o) {
  j.at("contest_id").get_to(o.m_Contest_id);
  j.at("user_id").get_to(o.m_User_id);
  j.at("input_file_id").get_to(o.m_Input_file_id);
  j.at("output_file_id").get_to(o.m_Output_file_id);
  j.at("description_file_id").get_to(o.m_Description_file_id);
}

int32_t Contest::getContestId() const { return m_Contest_id; }
void Contest::setContestId(int32_t const value) { m_Contest_id = value; }
int32_t Contest::getUserId() const { return m_User_id; }
void Contest::setUserId(int32_t const value) { m_User_id = value; }
int32_t Contest::getInputFileId() const { return m_Input_file_id; }
void Contest::setInputFileId(int32_t const value) { m_Input_file_id = value; }
int32_t Contest::getOutputFileId() const { return m_Output_file_id; }
void Contest::setOutputFileId(int32_t const value) { m_Output_file_id = value; }
int32_t Contest::getDescriptionFileId() const { return m_Description_file_id; }
void Contest::setDescriptionFileId(int32_t const value) {
  m_Description_file_id = value;
}

}  // namespace model
}  // namespace server
}  // namespace openapitools
}  // namespace org
