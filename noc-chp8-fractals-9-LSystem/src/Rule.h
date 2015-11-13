// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// LSystem Rule class

#pragma once
#include "ofMain.h"

class Rule {
public:
    
    Rule(char a_, string b_) {
        a = a_;
        b = b_;
    }
    
    char getA() {
        return a;
    }
    
    string getB() {
        return b;
    }
    
protected:
    
    char a;
    string b;
};


