cmake_minimum_required(VERSION 3.31)
project(RubikscubesolverV1)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubikscubesolverV1 main.cpp
        Models/GenericRubiksCube.cpp
        Models/GenericRubiksCube.h
        Models/Rubikscube3d.cpp
        Models/RubiksCube1D.cpp
)
