project(reconstruct)
cmake_minimum_required(VERSION 3.1)

# opencv
find_package(OpenCV 2.4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# pcl
find_package(PCL 1.7 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})

# Boost
find_package(
  Boost
  COMPONENTS thread
  REQUIRED)

add_subdirectory(src/myastra)

add_executable( reconstruct src/scan.cpp src/read.cpp src/registration.cpp src/common.cpp)
target_link_libraries (reconstruct ${PCL_LIBRARIES} ${OpenCV_LIBS} Boost::thread)

