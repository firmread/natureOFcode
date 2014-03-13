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
    
    vector <int> cells;
    int generation;
    vector <int> ruleset;
    int w;
};


#endif /* defined(__Exercise_7_01_WolframCA_randomizedrules__CA__) */
