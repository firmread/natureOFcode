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
    
    // An array of 0s and 1s
    vector <int> cells;
    
    // How many generations?
    int generation;
    
    // An array to store the ruleset, for example {0,1,1,0,1,1,0,1}
    int ruleset[8] = {0,1,0,1,1,0,1,0};
    int w;
};
