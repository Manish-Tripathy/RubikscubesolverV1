cmake_minimum_required(VERSION 3.31)
project(RubikscubesolverV1)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubikscubesolverV1 main.cpp
        Models/GenericRubiksCube.cpp
        Models/GenericRubiksCube.h
        Models/Rubikscube3d.cpp
        Models/RubiksCube1D.cpp
        Solvers/DFS_solver.cpp
        Solvers/BFS_solver.cpp
        Solvers/IDDFS_solver.cpp
        Solvers/IDAStar_Solver.cpp
        Pattern_DB/Nibble_array.cpp
        Pattern_DB/Nibble_array.h
        Pattern_DB/Pattern_Database.cpp
        Pattern_DB/Pattern_Database.h
        Pattern_DB/math.cpp
        Pattern_DB/math.h
        Pattern_DB/Permut_indexer.h
        Pattern_DB/Corner_pattern_DB.cpp
        Pattern_DB/Corner_pattern_DB.h
        Models/Init0/Init0.h
        Pattern_DB/Corner_DB_Maker.cpp
        Pattern_DB/Corner_DB_Maker.h
        Models/RubiksCubeBitboard.cpp
        Pattern_DB/Edge_DB_Maker.cpp
        Pattern_DB/Edge_DB_Maker.h
        Pattern_DB/Edge_pattern_DB.cpp
        Pattern_DB/Edge_pattern_DB.h
        Solvers/IDAStar_Edge_Solver.cpp
)
