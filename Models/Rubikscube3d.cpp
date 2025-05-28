//
// Created by manish tripathy on 28/05/25.
//
#include "GenericRubiksCube.h"

class RubiksCube3d:public RubiksCube {

    void RotateFaceCW(int idx) {
        char temp[3][3]={};
        for (int j=0;j<3;j++)
            temp[j][2]=cube[idx][0][j];
        for (int i=0;i<3;i++)
            temp[2][2-i]=cube[idx][i][2];
        for (int j=0;j<3;j++)
            temp[2-j][0]=cube[idx][2][2-j];
        for (int i=0;i<3;i++)
            temp[0][i]=cube[idx][2-i][0];
        temp[1][1]=cube[idx][1][1];
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++)
                cube[idx][i][j]=temp[i][j];
        }
    }


    public:
    char cube[6][3][3];
    RubiksCube3d() {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(static_cast<COLOR>(i));
                }
            }
        }
    }


    bool isSolved() const override {
     for (int i=0;i<6;i++) {
         for (int j=0;j<3;j++) {
             for (int k=0;k<3;k++) {
                 if (this->cube[i][j][k]!=getColorLetter(static_cast<COLOR>(i))) {
                     return false;
                 }
             }
         }
     }
        return true;
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

   RubiksCube& u()override {
        this->RotateFaceCW(0);
        char temp[3]={};
        for (int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for (int idx=1;idx<=3;idx++) {
            for (int i=0;i<3;i++)
                cube[idx][0][i]=cube[idx+1][0][i];
        }
        for (int i=0;i<3;i++) cube[4][0][i]=temp[i];
        return *this;
    }


    RubiksCube& uPrime()override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube& u2()override {
        this->u();
        this->u();

        return *this;
    }


    RubiksCube &l() override {
        this->RotateFaceCW(1);

        char temp[3]={};
        for (int i=0;i<3;i++) temp[i]=cube[0][i][0];
        for (int i=0;i<3;i++) cube[0][i][0]=cube[4][2-i][2];
        for (int i=0;i<3;i++) cube[4][2-i][2]=cube[5][i][0];
        for (int i=0;i<3;i++) cube[5][i][0]=cube[2][i][0];
        for (int i=0;i<3;i++) cube[2][i][0]=temp[i];

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }


    RubiksCube &f() override {
        this->RotateFaceCW(2);

        char temp[3] = {};
        for (int i=0;i<3;i++) temp[i]=cube[0][2][i];
        for (int i=0;i<3;i++) cube[0][2][i]=cube[1][2-i][2];
        for (int i=0;i<3;i++) cube[1][2-i][2]=cube[5][0][2-i];
        for (int i=0;i<3;i++) cube[5][0][2-i]=cube[3][i][0];
        for (int i=0;i<3;i++) cube[3][i][0]=temp[i];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }


     RubiksCube &r() override {
        this->RotateFaceCW(3);

        char temp[3] = {};
        for (int i=0;i<3;i++) temp[i]=cube[0][2-i][2];
        for (int i=0;i<3;i++) cube[0][2-i][2]=cube[2][2-i][2];
        for (int i=0;i<3;i++) cube[2][2-i][2]=cube[5][2-i][2];
        for (int i=0;i<3;i++) cube[5][2-i][2]=cube[4][i][0];
        for (int i=0;i<3;i++) cube[4][i][0]=temp[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->RotateFaceCW(4);

        char temp[3] = {};
        for (int i=0;i<3;i++)temp[i]=cube[0][0][2-i];
        for (int i=0;i<3;i++)cube[0][0][2-i]=cube[3][2-i][2];
        for (int i=0;i<3;i++)cube[3][2-i][2]=cube[5][2][i];
        for (int i=0;i<3;i++)cube[5][2][i]=cube[1][i][0];
        for (int i=0;i<3;i++)cube[1][i][0]=temp[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->RotateFaceCW(5);

        char temp[3] = {};
        for (int i=0;i<3;i++)temp[i]=cube[2][2][i];
        for (int i=0;i<3;i++)cube[2][2][i]=cube[1][2][i];
        for (int i=0;i<3;i++)cube[1][2][i]=cube[4][2][i];
        for (int i=0;i<3;i++)cube[4][2][i]=cube[3][2][i];
        for (int i=0;i<3;i++)cube[3][2][i]=temp[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }


    bool operator==(const RubiksCube3d &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3d &operator=(const RubiksCube3d &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3d &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }


};