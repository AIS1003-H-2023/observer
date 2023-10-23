cmake_minimum_required(VERSION 3.17)
project(separation_of_concerns)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

add_executable(demo main.cpp)
target_link_libraries(demo PRIVATE threepp::threepp)
target_include_directories(demo PRIVATE "${CMAKE_SOURCE_DIR}/include")
