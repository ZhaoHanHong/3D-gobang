cmake_minimum_required(VERSION 3.9.1)

project(3DGobang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(3dgobang STATIC src/board.cpp src/player.cpp src/game.cpp)

add_executable(main main.cpp)
target_link_libraries(main 3dgobang)