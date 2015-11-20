#pragma once
#include "ofMain.h"

class CA{
public:
    CA();
    void randomize();
    void restart();
    void generate();
    void display();
    int rules (int a, int b, int c);
    bool finished();
    
    vector <int> cells;
    int generation;
    vector <int> ruleset;
    int w;
};
