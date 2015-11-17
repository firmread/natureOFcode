#pragma once
#include "ofMain.h"

class mover {
public:
    mover();
    
    void setTarget(const ofPoint &target, float diff);
    void update();
    void draw();
    void checkEdges();

private:
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float topSpeed;
    int size, cor;
};
