#pragma once
#include "ofMain.h"

class particle{
public:
    particle(ofPoint);
    void update();
    void display();
    bool isDead();
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float lifespan;
    
};
