#include "serialization/serialization.hpp"

SerializationRegistry& SerializationRegistry::instance() {
  static SerializationRegistry instance;
  return instance;
}

std::shared_ptr<void> SerializationRegistry::deserialize(const std::string& type_name,
                                                         const json& j) const {
  const auto& it = deserializers_.find(type_name);
  if (it == deserializers_.end()) {
    throw std::runtime_error("Type serialisation not registered: " + type_name);
  }
  return it->second(j);
}