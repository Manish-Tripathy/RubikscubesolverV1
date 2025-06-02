//
// Created by manish tripathy on 03/06/25.
//

#ifndef NIBBLE_ARRAY_H
#define NIBBLE_ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include<cassert>

using namespace std;

class NibbleArray {
    size_t size;
    vector<uint8_t> arr;

public:
    NibbleArray(const size_t size, const uint8_t val = 0xFF);

    uint8_t get(const size_t pos) const;

    void set(const size_t pos, const uint8_t val);

    unsigned char *data();

    const unsigned char *data() const;

    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t val = 0xFF);

};



#endif //NIBBLE_ARRAY_H
