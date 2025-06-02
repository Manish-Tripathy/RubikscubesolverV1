//
// Created by manish tripathy on 01/06/25.
//

#include "../Models/GenericRubiksCube.h"

#ifndef RubiksCube_BFS_solver_h
#define RubiksCube_BFS_solver_h

template<typename T,typename H>
class BFS_solver {
private:
    vector<RubiksCube::MOVE> _move;
    unordered_map<T,bool,H> vis;
    unordered_map<T,RubiksCube::MOVE,H> move_done;


    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        vis[rubiksCube]=1;

        while (!q.empty()) {
            T node=q.front();
            q.pop();
            if (node.isSolved())return node;

            for (int i=0;i<18;i++) {
                auto curr=RubiksCube::MOVE(i);
                node.move(curr);
                if (!vis[node]) {
                    vis[node]=true;
                    move_done[node]=curr;
                    q.push(node);
                }
                node.invert(curr);
            }

        }

        return rubiksCube;
    }

    public:
    T rubiksCube;

    BFS_solver(T _rubiksCube):rubiksCube{_rubiksCube}
    {}

    vector<RubiksCube::MOVE> solve() {
        T solved_cube=bfs();
        assert(solved_cube.isSolved());
        T curr=solved_cube;
        while (!(curr==rubiksCube)) {
            RubiksCube::MOVE curr_move=move_done[curr];
            _move.push_back(curr_move);
            curr.invert(curr_move);
        }
        rubiksCube=solved_cube;
        reverse(_move.begin(),_move.end());
        return _move;
    }
};



#endif //RubiksCube_BFS_solver_h
