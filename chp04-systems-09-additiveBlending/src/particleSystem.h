#pragma once
#include "ofMain.h"
#include "particle.h"

class particleSystem{
public:
    particleSystem(ofPoint, ofImage);
    void update();
    void display();
    void addParticle();
    
    ofPoint origin;
    ofImage img;
    vector<particle*> particles;
};
