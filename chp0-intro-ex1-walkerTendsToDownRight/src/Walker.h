#pragma once

#include "ofMain.h"

class Walker {
    
public:
    float x;
    float y;
    
    Walker();
    void render();
    void step();
};