cmake_minimum_required(VERSION 3.0.0)
project(boost-tutorial VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
include(CTest)
enable_testing()

add_executable(boost-tutorial main.cpp)
add_executable(tuto2 tuto2.cpp)
add_executable(smart-pointer-tutorial-5 smart-pointer-tutorial-5.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

