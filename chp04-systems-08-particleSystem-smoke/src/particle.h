#pragma once
#include "ofMain.h"

class particle{
public:
    particle(ofPoint, ofImage);
    void update();
    void display();
    void applyForce(ofPoint);
    bool isDead();
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float lifespan;
    float mass;
    ofImage img;
    
};