#pragma once

#include "ofMain.h"


class Circle {


public:
    void setup();
    void update();
    void draw();
    
    
    
    
private:
    float r = 0;
    float theta = 0;
    float x;
    float y;
    float angle = 0;
    
};