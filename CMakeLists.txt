cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

project (Stepper)

include_directories(/home/pi/wiringPi/wiringPi)
include_directories(include/)

add_library(All SHARED
  include/Stepper.cpp)

target_link_libraries(All wiringPi)

add_executable(Stepper testStepper.cpp)
target_link_libraries(Stepper All)
