//
// Created by manish tripathy on 26/06/25.
//

#include "Edge_DB_Maker.h"

using namespace std;

Edge_DB_Maker::Edge_DB_Maker(string _fileName) {
    fileName = _fileName;
}

Edge_DB_Maker::Edge_DB_Maker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    edgeDB = Edge_pattern_DB(init_val);
}



bool Edge_DB_Maker::bfsAndStore() {
    RubiksCube1d cube;
    queue<RubiksCube1d> q;
    q.push(cube);
    edgeDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
        curr_depth++;
        if (curr_depth == 7) break;
        for (int counter = 0; counter < n; counter++) {
            RubiksCube1d node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if ((int) edgeDB.getNumMoves(node) > curr_depth) {
                    edgeDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    edgeDB.toFile(fileName);
    // bool success = edgeDB.toFile(fileName);
    // if (!success) {
    cout<<"completed"<< endl;
    // }

    return true;
}
