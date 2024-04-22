cmake_minimum_required(VERSION 3.18)
project(fast_lio)

## Compile as C++11, supported in ROS Kinetic and newer
SET( CMAKE_CXX_FLAGS "-std=c++17 -O3" )
add_compile_options(-std=c++17)
add_definitions(-DPROJ_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

find_package(ament_cmake_auto REQUIRED COMPONENTS
    rclcpp
    rclpy
    sensor_msgs
)
find_package(PCL REQUIRED)
# YAML CPP
find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML_CPP REQUIRED yaml-cpp)

# ament_auto_find_build_dependencies()
# ament_auto_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${YAML_CPP_INCLUDEDIR}
)


SET(IESKF_SLAM_FILE
    src/ieskf_slam/modules/frontend/frontend.cpp
)
SET(NOETIC_FRONTEND_WRAPPER_FILE
    src/wrapper/ros_humble/ieskf_frontend_humble_wrapper.cpp
)

ament_auto_add_executable(ieskf_frontend_node src/app/ros_humble/ieskf_humble_running_node.cpp
  ${NOETIC_FRONTEND_WRAPPER_FILE}
  ${IESKF_SLAM_FILE}
)

# target_link_libraries(ieskf_frontend_node
#   ${catkin_LIBRARIES}
#   ${PCL_LIBRARIES}
#   ${YAML_CPP_LIBRARIES}
# )

# ament_auto_add_executable(ieskf_frontend_node src/app/ros_noetic/ieskf_noetic_running_node.cpp
#   ${NOETIC_FRONTEND_WRAPPER_FILE}
#   ${IESKF_SLAM_FILE}
# )
