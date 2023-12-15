cmake_minimum_required(VERSION 3.20)
project(lab_OOP_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_executable(main main.cpp array.hpp Trapezoid.hpp Rombus.hpp Pentagon.hpp)
add_executable(test test.cpp array.hpp Trapezoid.hpp Rombus.hpp Pentagon.hpp)

target_link_libraries(test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test)