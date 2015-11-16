#pragma once

#include "ofMain.h"



class Spaceship {
    
public:
    void setup();
    void update();
    void draw();
    void thrust();
    void turn(float a);
    void checkEdges();
    void applyForce(const ofVec2f & force);
    
    
private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed, damping, heading;
    int radius, mass;
    Boolean thrusting;
    
};
