cmake_minimum_required(VERSION 4.3.2)
project(engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(engine main.cpp
        board/board.cpp
        board/board.h
        game.cpp
        game.h
        board/buildings/building.h
        board/buildings/building.cpp
        utils/utils.h
        utils/utils.cpp
        board/buildings/buildings.h
        )
