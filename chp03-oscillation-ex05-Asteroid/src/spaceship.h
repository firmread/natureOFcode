#pragma once
#include "ofMain.h"

class spaceship {
public:
    void setup();
    void update();
    void draw();
    void thrust();
    void turn(float a);
    void checkEdges();
    void applyForce(const ofPoint & force);
    
    
private:
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float topSpeed, damping, heading;
    int radius, mass;
    bool thrusting;
    
};
