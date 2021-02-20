project(reconstruct)
cmake_minimum_required (VERSION 3.1)

#opencv 
find_package(OpenCV 3.4 REQUIRED)

#pcl
find_package(PCL 1.7 REQUIRED)

# Boost
find_package(Boost COMPONENTS thread REQUIRED)

SET(CMAKE_BUILD_TYPE "RELEASE")

include_directories(${PCL_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable( reconstruct src/scan.cpp src/read.cpp src/registration.cpp src/common.cpp)
target_link_libraries (reconstruct ${PCL_LIBRARIES} ${OpenCV_LIBS} Boost::thread)

