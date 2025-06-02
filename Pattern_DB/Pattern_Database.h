//
// Created by manish tripathy on 03/06/25.
//

#ifndef PATTERN_DATABASE_H
#define PATTERN_DATABASE_H


#include <iostream>
#include <vector>
#include <string>
#include <random>
#include<cassert>
#include<fstream>
#include "../Models/GenericRubiksCube.h"
#include "Nibble_array.h"

using namespace std;

class PatternDatabase {

    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabase();

public:
    PatternDatabase(const size_t size);
    //    Testing for init_val
    PatternDatabase(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const RubiksCube &cube) const = 0;

    virtual bool setNumMoves(const RubiksCube &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const RubiksCube &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};



#endif //PATTERN_DATABASE_H
