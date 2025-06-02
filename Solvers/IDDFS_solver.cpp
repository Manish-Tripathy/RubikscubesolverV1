//
// Created by manish tripathy on 01/06/25.
//
#include "DFS_solver.cpp"
#ifndef IDDFS_SOLVER_H
#define IDDFS_SOLVER_H

template<typename T,typename H>
class IDDFS_solver {
    private:
    int max_dep;
    vector<RubiksCube::MOVE> moves;

public:
    T rubiksCube;

    IDDFS_solver(T _rubiksCube,int max_search_dep):rubiksCube(_rubiksCube),max_dep(max_search_dep)
    {}

    vector<RubiksCube::MOVE> solve() {
        for (int i=1;i<=max_dep;i++) {
            DFS_solver<T,H> dfs_solver(rubiksCube,i);
            moves=dfs_solver.solve();
            if (dfs_solver.rubiksCube.isSolved()) {
                rubiksCube=dfs_solver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};


#endif //IDDFS_SOLVER_H