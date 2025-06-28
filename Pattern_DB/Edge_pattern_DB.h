//
// Created by manish tripathy on 26/06/25.
//

#ifndef EDGE_PATTERN_DB_H
#define EDGE_PATTERN_DB_H

#include "../Models/GenericRubiksCube.h"
#include "Pattern_Database.h"
#include "Permut_indexer.h"
using namespace std;


class Edge_pattern_DB: public  PatternDatabase{
    typedef RubiksCube::FACE F;

    PermutationIndexer<12,7> permIndexer;
public:
    Edge_pattern_DB();
    Edge_pattern_DB(uint8_t init_val);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;
};



#endif //EDGE_PATTERN_DB_H
