//
// Created by Manish Tripathy on 23/05/25.
//

#include "GenericRubiksCube.h"



char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::WHITE:
            return 'W';
        case COLOR::ORANGE:
              return 'O';
    }

    throw std::invalid_argument("Invalid COLOR for getColorLetter()");
}

string RubiksCube::getMove(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";
    }

    throw std::invalid_argument("Invalid MOVE for getMove()");
}


RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bPrime();
        case MOVE::B2:
            return this->b2();
    }

    throw std::invalid_argument("Invalid MOVE for move()");
}


RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return this->lPrime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rPrime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::U:
            return this->uPrime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dPrime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::F:
            return this->fPrime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bPrime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();
    }

    throw std::invalid_argument("Invalid MOVE for invert()");
}

void RubiksCube::print() const {
    cout << "Rubik's Cube:\n";
    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        }
        cout << " ";

        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moves_performed;
    // srand(time(0));
    std::random_device rd;
    std::mt19937_64 RNG(rd());
    std::uniform_int_distribution<long long> dist(0, 17); // replace long long with appropriate type

    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (dist(RNG));
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}

//Helper function returns string of corner
string RubiksCube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}


string RubiksCube::getEdgeColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
        case 0:  // UF
            str += getColorLetter(getColor(FACE::UP, 2, 1));
            str += getColorLetter(getColor(FACE::FRONT, 0, 1));
            break;
        case 1:  // UR
            str += getColorLetter(getColor(FACE::UP, 1, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 1));
            break;
        case 2:  // UB
            str += getColorLetter(getColor(FACE::UP, 0, 1));
            str += getColorLetter(getColor(FACE::BACK, 0, 1));
            break;
        case 3:  // UL
            str += getColorLetter(getColor(FACE::UP, 1, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 1));
            break;
        case 4:  // DF
            str += getColorLetter(getColor(FACE::DOWN, 0, 1));
            str += getColorLetter(getColor(FACE::FRONT, 2, 1));
            break;
        case 5:  // DR
            str += getColorLetter(getColor(FACE::DOWN, 1, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 1));
            break;
        case 6: // DB
            str += getColorLetter(getColor(FACE::DOWN, 2, 1));
            str += getColorLetter(getColor(FACE::BACK, 2, 1));
            break;
        case 7: // DL
            str += getColorLetter(getColor(FACE::DOWN, 1, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 1));
            break;
        case 8:  // FR
            str += getColorLetter(getColor(FACE::FRONT, 1, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 1, 0));
            break;
        case 9:  // FL
            str += getColorLetter(getColor(FACE::FRONT, 1, 0));
            str += getColorLetter(getColor(FACE::LEFT, 1, 2));
            break;
        case 10:  // BL
            str += getColorLetter(getColor(FACE::BACK, 1, 2)); // mistake was 1 0 i guess
            str += getColorLetter(getColor(FACE::LEFT, 1, 0));
            break;
        case 11:  // BR
            str += getColorLetter(getColor(FACE::BACK, 1, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 1, 2));
            break;
    }
    return str;
}



uint8_t RubiksCube::getEdgeIndex(uint8_t ind) const {
    string edge = getEdgeColorString(ind);

    static const vector<string> edgeSignatures = {
        "WR", "WB", "WO", "WG", // UF UR UB UL
        "YR", "YB", "YO" // DF DR DB
    };

    string s = edge;
    sort(s.begin(), s.end());

    for (uint8_t i = 0; i < 12; ++i) {
        string t = edgeSignatures[i];
        sort(t.begin(), t.end());

        if (s == t) {
             // cout<<s<<" "<<t<<endl;
            return i;
        }
    }

    // throw std::runtime_error("Invalid edge colors");
    return 8;
}


uint8_t RubiksCube::getEdgeOrientation(uint8_t ind) const {
    string edge = getEdgeColorString(ind);
    if (edge[0]!='W' && edge[1]!='W') {
        if (edge[0]!='Y' && edge[1]!='Y')return -1;
    }
    static const vector<string> edgeSignatures = {
        "WR", "WB", "WO", "WG", // UF UR UB UL
        "YR", "YB", "YO" // DF DR DB
    };

    if (edge[0]=='W' || edge[0]=='Y')return 0;
    return 1;
}


uint8_t RubiksCube::getEdgeIndex(uint8_t ind) const {
    string edge = getEdgeColorString(ind);

    static const vector<string> edgeSignatures = {
        "WR", "WB", "WO", "WG", // UF UR UB UL
        "YR", "YB", "YO" // DF DR DB
    };

    string s = edge;
    sort(s.begin(), s.end());

    for (uint8_t i = 0; i < 12; ++i) {
        string t = edgeSignatures[i];
        sort(t.begin(), t.end());

        if (s == t) {
            // cout<<s<<" "<<t<<endl;
            return i;
        }
    }

    // throw std::runtime_error("Invalid edge colors");
    return 8;
}
