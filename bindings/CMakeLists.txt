include(sources.cmake)
nanobind_add_module(example ${BINDING_SOURCES})
set_target_properties(example PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(example PRIVATE core Python::Python)
target_compile_features(example PUBLIC cxx_std_23)