cmake_minimum_required(VERSION 2.8.3)
project(sine_pub)

find_package(catkin REQUIRED COMPONENTS std_msgs roscpp)

catkin_package(
  CATKIN_DEPENDS std_msgs
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(sine_pub src/sine_pub.cpp)
target_link_libraries(sine_pub ${catkin_LIBRARIES})
