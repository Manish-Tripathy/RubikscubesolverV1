//
// Created by manish tripathy on 03/06/25.
//

#include "Corner_DB_Maker.h"

using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore() {
    RubiksCube1d cube;
    queue<RubiksCube1d> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
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
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    // bool success = cornerDB.toFile(fileName);
    // if (!success) {
    cout<<"completed"<< endl;
    // }

    return true;
}