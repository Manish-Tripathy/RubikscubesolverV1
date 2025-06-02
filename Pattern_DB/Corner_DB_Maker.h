//
// Created by manish tripathy on 03/06/25.
//

#ifndef CORNER_DB_MAKER_H
#define CORNER_DB_MAKER_H


#include "Corner_pattern_DB.h"
#include "../Models/RubiksCubeBitboard.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};




#endif //CORNER_DB_MAKER_H
