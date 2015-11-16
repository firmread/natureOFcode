#pragma once

#include "ofMain.h"

class Mover {
    
public:
    void setup();
    
    void setTarget(const ofVec2f & target, float diff);
    void update();
    void draw();
    void checkEdges();
    
    
private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed;
    int size, cor;
};
