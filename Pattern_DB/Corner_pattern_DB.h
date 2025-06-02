//
// Created by manish tripathy on 03/06/25.
//

#ifndef CORNER_PATTERN_DB_H
#define CORNER_PATTERN_DB_H

#include "../Models/GenericRubiksCube.h"
#include "Pattern_Database.h"
#include "Permut_indexer.h"
using namespace std;


class CornerPatternDatabase : public PatternDatabase {

    typedef RubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;

};



#endif //CORNER_PATTERN_DB_H
