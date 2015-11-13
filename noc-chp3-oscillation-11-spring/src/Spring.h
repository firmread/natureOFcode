#pragma once

#include "ofMain.h"
#include "Bob.h"

class Spring{
    
private:
    float len;
    float k;
    

    
public:
    
    void setup(float x, float y, int l);
    void connect(Bob & b);
    void display(Bob & b);
    void constrainLength(Bob b, float minLen, float maxLen);
  
    ofVec2f anchor;

    
};


