#pragma once
#include "ofMain.h"

class circle {
public:
    circle();
    void reset();
    void update(float speed);
    void draw();
    
private:
    float r = 0;
    float theta = 0;
    float x;
    float y;
    float angle = 0;
    ofColor color;
    float rSeed;
    
};