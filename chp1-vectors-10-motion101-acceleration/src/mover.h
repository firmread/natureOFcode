//
//  mover.h
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//
#include "ofMain.h"

class mover{
public:
    mover();
    void update(int x, int y);
    void display();
    void checkEdges();
    
    // The Mover tracks location, velocity, and acceleration 
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    // The Mover's maximum speed
    float topspeed;
    
};
