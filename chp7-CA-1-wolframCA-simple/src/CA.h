//
//  CA.h
//  Exercise_7_01_WolframCA_randomizedrules
//
//  Created by Firm Read on 3/13/14.
//
//

#ifndef __Exercise_7_01_WolframCA_randomizedrules__CA__
#define __Exercise_7_01_WolframCA_randomizedrules__CA__

#include <iostream>
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


#endif /* defined(__Exercise_7_01_WolframCA_randomizedrules__CA__) */
