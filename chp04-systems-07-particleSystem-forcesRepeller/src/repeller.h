#pragma once
#include "ofMain.h"
#include "particle.h"

class repeller{
public:
    repeller(ofPoint);
    void display();
    ofPoint repel(particle);
    
    ofPoint location;
};
