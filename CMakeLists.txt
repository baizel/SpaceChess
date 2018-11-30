cmake_minimum_required(VERSION 3.12)
project(SpaceChess)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpaceChess
        SpaceChess/Game.cpp SpaceChess/Piece.cpp SpaceChess/Piece.h SpaceChess/Rook.cpp SpaceChess/Rook.h SpaceChess/Bishop.cpp SpaceChess/Bishop.h SpaceChess/Queen.cpp SpaceChess/Queen.h SpaceChess/Utils.cpp SpaceChess/Utils.h)
