cmake_minimum_required(VERSION 3.12)
project(SpaceChess)

set(CMAKE_CXX_STANDARD 14)

include_directories(SpaceChess)

add_executable(SpaceChess
        SpaceChess/Axis.h
        SpaceChess/Bishop.cpp
        SpaceChess/Bishop.h
        SpaceChess/Directions.h
        SpaceChess/Game.cpp
        SpaceChess/Piece.cpp
        SpaceChess/Piece.h
        SpaceChess/PieceShape.h
        SpaceChess/Position.h
        SpaceChess/Queen.cpp
        SpaceChess/Queen.h
        SpaceChess/Rook.cpp
        SpaceChess/Rook.h)
