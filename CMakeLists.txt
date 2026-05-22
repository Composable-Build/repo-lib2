cmake_minimum_required(VERSION 3.16)
project(plugin_two CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR "0" CACHE STRING "")
set(VERSION_MINOR "0" CACHE STRING "")
set(VERSION_PATCH "0" CACHE STRING "")
set(VERSION_BUILD "0" CACHE STRING "")

configure_file(src/version.h.in ${CMAKE_BINARY_DIR}/version.h @ONLY)

add_library(lib2 SHARED src/plugin.cpp)
target_include_directories(lib2 PUBLIC ${CMAKE_BINARY_DIR})
set_target_properties(lib2 PROPERTIES OUTPUT_NAME "plugin_two")

include(FetchContent)
FetchContent_Declare(Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.3)
FetchContent_MakeAvailable(Catch2)

add_executable(tests_lib2 tests/test_main.cpp)
target_include_directories(tests_lib2 PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(tests_lib2 PRIVATE Catch2::Catch2WithMain lib2)
