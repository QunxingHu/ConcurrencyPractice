cmake_minimum_required(VERSION 3.5)
project(ConcurrencyPractice)

set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES main.cpp src/practice1.cpp src/practice2.cpp src/practice2.cpp src/practice3.cpp)
add_executable(ConcurrencyPractice ${SOURCE_FILES})
target_link_libraries(ConcurrencyPractice pthread)