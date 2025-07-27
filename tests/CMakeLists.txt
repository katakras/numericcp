include(sources.cmake)
add_executable(tests ${TESTS_SOURCES})
target_link_libraries(tests PRIVATE core Catch2::Catch2WithMain nlohmann_json::nlohmann_json)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})

include(CTest)
include(Catch)
catch_discover_tests(tests)