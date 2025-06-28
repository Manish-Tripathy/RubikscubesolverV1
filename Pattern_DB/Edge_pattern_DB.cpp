//
// Created by manish tripathy on 26/06/25.
//

#include "Edge_pattern_DB.h"

Edge_pattern_DB::Edge_pattern_DB() : PatternDatabase(520'000'000) {}
Edge_pattern_DB::Edge_pattern_DB(uint8_t init_val) : PatternDatabase(520'000'000, init_val) {}


uint32_t Edge_pattern_DB::getDatabaseIndex(const RubiksCube &cube) const {
    array<uint8_t, 7> edgePerm;

    for (int i=0;i<12;i++) {
        int x=cube.getEdgeIndex(i);
        if (x!=8) {
            assert(x>=0 && x<=6);
            edgePerm[x]=i;
        }
    }
 for (int i=0;i<7;i++) {
     if (!(edgePerm[i]>=0 && edgePerm[i]<=11)) {
         cube.print();
         throw std::runtime_error("Invalid edge index");
     }
 }
    uint32_t rank = this->permIndexer.rank(edgePerm);

    array<uint8_t, 7> edge_orientation = {
        cube.getEdgeOrientation(edgePerm[0]),
        cube.getEdgeOrientation(edgePerm[1]),
        cube.getEdgeOrientation(edgePerm[2]),
        cube.getEdgeOrientation(edgePerm[3]),
        cube.getEdgeOrientation(edgePerm[4]),
        cube.getEdgeOrientation(edgePerm[5]),
        cube.getEdgeOrientation(edgePerm[6]),
};

    uint32_t orientationNum =
            edge_orientation[0] * 64 +
            edge_orientation[1] * 32 +
            edge_orientation[2] * 16 +
            edge_orientation[3] * 8 +
            edge_orientation[4] * 4 +
            edge_orientation[5] * 2 +
            edge_orientation[6];
    uint32_t num=(rank * 128) + orientationNum;
    if (num>520'000'000) {
        throw std::runtime_error("Invalid edge colors");
    }
    return (rank * 128) + orientationNum;
}