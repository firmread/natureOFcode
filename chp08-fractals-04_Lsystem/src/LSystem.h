//
//  LSystem.h
//  04_Lsystem
//
//  Created by Charlie Whitney on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "Rule.h"

class LSystem {
  public:

    void setup( string axiom, vector<Rule> rules );
    void addGeneration();
    
    string          sentence;
    int             generation;
    vector<Rule>    ruleList;
};