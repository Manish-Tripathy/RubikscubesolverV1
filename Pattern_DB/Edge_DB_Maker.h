//
// Created by manish tripathy on 26/06/25.
//

#ifndef EDGE_DB_MAKER_H
#define EDGE_DB_MAKER_H

#include "Edge_pattern_DB.h"
#include "../Models/RubiksCube1D.cpp"


class Edge_DB_Maker {
private:
    string fileName;
    Edge_pattern_DB edgeDB;

public:
    Edge_DB_Maker(string _fileName);
    Edge_DB_Maker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};



#endif //EDGE_DB_MAKER_H
