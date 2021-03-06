cmake_minimum_required(VERSION 3.9)  # setting this is required
project(simulator)                   # this sets the project name

# compiler
set(CMAKE_C_COMPILER /usr/local/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

# gather all files
include_directories(include)
file(GLOB SOURCES src/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})


# OMP portion
# link to OpenMP if exists
find_package(OpenMP REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)

# Looks like you need brew clang for omp, but the Apple one for find_package(OpenMP...)
if(APPLE)
    set(CMAKE_C_COMPILER /usr/local/opt/llvm/bin/clang)
    set(CMAKE_CCX_COMPILER ${CMAKE_C_COMPILER}++)
endif()
# end OMP portion

# add run target
add_custom_target(run
    COMMAND ${CMAKE_PROJECT_NAME} 
    DEPENDS ${CMAKE_PROJECT_NAME} 
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
    )
