//
// Created by Manish Tripathy on 23/05/25.
//

#ifndef GENERICRUBIKSCUBE_H
#define GENERICRUBIKSCUBE_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include<cassert>

using namespace std;

class RubiksCube {
public:
    virtual ~RubiksCube()=default;

    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };


    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;


    static char getColorLetter(COLOR color);


    virtual bool isSolved() const = 0;

    static string getMove(MOVE ind);


    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);


    RubiksCube &move(MOVE ind);

    RubiksCube &invert(MOVE ind);

    //operations

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;
    //for corner based DB
    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;

    //for edge base DB
    string getEdgeColorString(uint8_t ind) const;

    uint8_t getEdgeOrientation(uint8_t ind) const;

    uint8_t getEdgeIndex(uint8_t ind) const;

    //for solvability checker
    uint8_t getEdgeIndextot(uint8_t ind) const;

    uint8_t getEdgeOrientationtot(uint8_t ind) const;
};

#endif //GENERICRUBIKSCUBE_H
