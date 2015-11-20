#pragma once
#include "ofMain.h"

class GOLCell{
public:
    GOLCell(float, float, float);
    void display();
    void newState(int);
    void savePrevious();
    

    float x;
    float y;
    float w;

    int state;
    int previous;
};
