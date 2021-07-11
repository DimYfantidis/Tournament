cmake_minimum_required(VERSION 3.19)
project(Tournament)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tournament
        main.cpp
        tournament.h
        tournament.cpp
        auxFunctions.h)
