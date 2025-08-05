#include <catch2/catch_all.hpp>

#include "src/serialization/serialization.hpp"

class DummySerializationClass {
 public:
  DummySerializationClass(const int v) : v_(v) {}

  nlohmann::json to_json() const {
    return nlohmann::json({{"$class", "DummySerializationClass"}, {"v", v_}});
  }
  void from_json(const nlohmann::json& j) { v_ = j.at("v"); }

  auto v() const { return v_; }

 private:
  DummySerializationClass() = default;
  friend class SerializationRegistry;

  int v_;
};

REGISTER_SERIALIZABLE_TYPE(DummySerializationClass)

TEST_CASE("Dummy class serialization", "[serialization]") {
  const auto& obj = std::make_shared<DummySerializationClass>(1);
  const auto& obj_json = obj->to_json();
  const auto& obj_from_json = std::static_pointer_cast<DummySerializationClass>(
      SerializationRegistry::instance().deserialize("DummySerializationClass", obj_json));
  REQUIRE(obj->v() == obj_from_json->v());
}