cmake_minimum_required(VERSION 3.0.2)
project(project_name)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  geometry_msgs
  image_transport
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
  tf2
)

find_package(OpenCV REQUIRED)

## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(node_name src/demo.cpp)

target_link_libraries(node_name
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)
