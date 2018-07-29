cmake_minimum_required(VERSION 3.12)
project(GroupProject)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Ant.cpp Ant.h Critter.h Critter.cpp Space.cpp Space.h
<<<<<<< HEAD
<<<<<<< HEAD
        Board.cpp Board.h DoodleBug.cpp DoodleBug.h menu.h menu.cpp menu_item.h menu_item.cpp
        my_lib.cpp my_lib.h)
=======
        Board.cpp Board.h DoodleBug.cpp DoodleBug.h)
>>>>>>> 37572b50b943df1d58b254d35c1649e57240cb8f
=======
        Board.cpp Board.h DoodleBug.cpp DoodleBug.h)
>>>>>>> d8e20ade9b3d20b57cdc2e0c89210287cafaa26e

add_executable(GroupProject ${SOURCE_FILES})