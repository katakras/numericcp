include(sources.cmake)
add_library(core STATIC ${CORE_SOURCES})


target_link_libraries (core PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})