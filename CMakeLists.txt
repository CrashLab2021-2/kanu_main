cmake_minimum_required(VERSION 3.0.2)
project(kanu_main)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
  kanu_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES kanu_main
  CATKIN_DEPENDS geometry_msgs roscpp sensor_msgs std_msgs kanu_msgs
  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(kanu_main src/main.cpp)

add_dependencies(kanu_main ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(kanu_main
  ${catkin_LIBRARIES}
)
