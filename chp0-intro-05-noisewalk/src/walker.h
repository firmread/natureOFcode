#pragma once
#include "ofMain.h"

class walker {
public:
    walker();

    void update();
    void draw();
    
    int constrain(int, int, int);
    int overflow(int, int, int);

    ofPoint pos;
    ofPoint noisePos;
    float noiseSpeed;
    
    int scale;
};

