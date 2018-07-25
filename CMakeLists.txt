cmake_minimum_required(VERSION 3.8)
project(Group Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Ant.cpp Ant.h Critter.h Critter.cpp Space.cpp Space.h utility.cpp utility.h Board.cpp Board.h)
add_executable(Project_1 ${SOURCE_FILES})