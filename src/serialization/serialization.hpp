#pragma once

#include <nlohmann/json.hpp>

using json = nlohmann::json;

// concept
template <typename T>
concept serializable = requires(T obj, json j) {
  { obj.to_json() } -> std::convertible_to<json>;
  { obj.from_json(j) };
};

// class holding registry of types and deserializers
class SerializationRegistry {
 public:
  using DeserializeFunc = std::function<std::shared_ptr<void>(const json&)>;

  static SerializationRegistry& instance();

  template <serializable T>
  void register_type(const std::string& type_name) {
    deserializers_[type_name] = [](const json& j) -> std::shared_ptr<void> {
      auto obj = std::shared_ptr<T>(new T());
      obj->from_json(j);
      return obj;
    };
  }

  std::shared_ptr<void> deserialize(const std::string& type_name, const json& j) const;

 private:
  std::unordered_map<std::string, DeserializeFunc> deserializers_;
};

#define REGISTER_SERIALIZABLE_TYPE(T)                         \
  namespace {                                                 \
  struct T##RegistryEntry {                                   \
    T##RegistryEntry() {                                      \
      SerializationRegistry::instance().register_type<T>(#T); \
    }                                                         \
  };                                                          \
  static T##RegistryEntry global_##T##RegistryEntry;          \
  }
