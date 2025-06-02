//
// Created by manish tripathy on 01/06/25.
//

#include "../Models/GenericRubiksCube.h"

#ifndef DFS_SOLVER_H
#define DFS_SOLVER_H

template<typename T,typename H>
class DFS_solver {
private:
    vector<RubiksCube::MOVE> _moves;
    int max_depth;

    bool dfs(int dep) {
        if (rubiksCube.isSolved())return true;
        if (dep>max_depth) return false;
        for (int i=0;i<18;i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            _moves.push_back(RubiksCube::MOVE(i));
            if (dfs(dep+1))return true;
            _moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }
    public:
     T rubiksCube;

    DFS_solver(T _rubiksCube,int max_search_dis) {
        rubiksCube = _rubiksCube;
        max_depth = max_search_dis;
    }

    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return _moves;
    }
};



#endif //DFS_SOLVER_H
