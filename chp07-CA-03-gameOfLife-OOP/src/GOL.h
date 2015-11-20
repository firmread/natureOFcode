#pragma once
#include "ofMain.h"
#include "GOLCell.h"

class GOL{
public:
    GOL();
    void init();
    void generate();
    void display();

    int w ;
    int columns;
    int rows;
    vector< vector<GOLCell*> > board;
};
