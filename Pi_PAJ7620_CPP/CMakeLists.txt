cmake_minimum_required(VERSION 3.9)
project(Gesture_main)

set(CMake_CXX_STANDARD 11)

find_package(wiringPi REQUIRED)


include_directories(${WIRINGPI_INCLUDE_DIRS})


add_executable(Gesture_main paj7620_test.cpp Pi_PAJ7620.cpp)
target_link_libraries(Gesture_main ${WIRINGPI_LIBRARIES})
