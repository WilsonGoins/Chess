cmake_minimum_required(VERSION 3.25)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess
        main.cpp Piece.h Pawn.h Pawn.cpp Board.h Board.cpp Castle.cpp Empty.h Bishop.h Bishop.cpp Knight.h Knight.cpp Queen.h Queen.cpp King.h King.cpp Images.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/HP/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include/SFML)
target_link_libraries(Chess sfml-system sfml-window sfml-graphics sfml-audio)