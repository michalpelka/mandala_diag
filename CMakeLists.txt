cmake_minimum_required(VERSION 2.8.3)
project(m3dunit_diag)
set(CMAKE_BUILD_TYPE Debug)

find_package(Boost REQUIRED COMPONENTS system thread)



###########
## Build ##
###########




add_executable(m3d_diag src/m3d_diag.cpp src/driverLib.cpp)
target_link_libraries(m3d_diag ${Boost_LIBRARIES})


