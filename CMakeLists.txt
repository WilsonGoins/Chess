cmake_minimum_required(VERSION 3.25)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess
        main.cpp Piece.h Pawn.h Pawn.cpp Board.h Board.cpp)
