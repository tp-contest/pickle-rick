/**
 * TP-Contest Worker
 * No description provided (generated by Openapi Generator
 * https://github.com/openapitools/openapi-generator)
 *
 * The version of the OpenAPI document: 1.0.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.0.0.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "Object.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {

Object::Object() { m_object = web::json::value::object(); }

Object::~Object() {}

void Object::validate() {
  // TODO: implement validation
}

web::json::value Object::toJson() const { return m_object; }

void Object::fromJson(const web::json::value& val) {
  if (val.is_object()) {
    m_object = val;
  }
}

void Object::toMultipart(std::shared_ptr<MultipartFormData> multipart,
                         const utility::string_t& prefix) const {
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(".")) {
    namePrefix += utility::conversions::to_string_t(".");
  }
  multipart->add(ModelBase::toHttpContent(
      namePrefix + utility::conversions::to_string_t("object"), m_object));
}

void Object::fromMultiPart(std::shared_ptr<MultipartFormData> multipart,
                           const utility::string_t& prefix) {
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(".")) {
    namePrefix += utility::conversions::to_string_t(".");
  }

  m_object = ModelBase::valueFromHttpContent(multipart->getContent(
      namePrefix + utility::conversions::to_string_t("object")));
}

web::json::value Object::getValue(const utility::string_t& key) const {
  return m_object.at(key);
}

void Object::setValue(const utility::string_t& key,
                      const web::json::value& value) {
  m_object[key] = value;
}

}  // namespace model
}  // namespace client
}  // namespace openapitools
}  // namespace org
