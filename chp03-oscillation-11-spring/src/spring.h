#pragma once

#include "ofMain.h"
#include "mover.h"

class spring{
public:
    
    void setup(float x, float y, int l);
    void connect(mover & m);
    void display(mover & m);
    void constrainLength(mover m, float minLen, float maxLen);
  
    ofPoint anchor;
    
private:
    float len;
    float k;
    
};


