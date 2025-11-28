cmake_minimum_required(VERSION 3.24)

project(links_in_a_chain)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(program_test tests/program_test.cpp src/Node.hpp)
add_executable(main main.cpp src/Node.hpp)

target_link_libraries(program_test PRIVATE Catch2::Catch2WithMain)
