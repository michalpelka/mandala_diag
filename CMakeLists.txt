cmake_minimum_required(VERSION 2.8.3)
project(m3dunit_diag)
set(CMAKE_BUILD_TYPE Debug)

find_package(Boost REQUIRED COMPONENTS system thread)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()

###########
## Build ##
###########




add_executable(m3d_diag src/m3d_diag.cpp src/driverLib.cpp)
target_link_libraries(m3d_diag ${Boost_LIBRARIES})

add_executable(m3d_set_speed src/m3d_set_speed.cpp src/driverLib.cpp)
target_link_libraries(m3d_set_speed ${Boost_LIBRARIES})
