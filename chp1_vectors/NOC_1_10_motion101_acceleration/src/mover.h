//
//  mover.h
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#ifndef __NOC_1_7_motion101__mover__
#define __NOC_1_7_motion101__mover__

#include <iostream>
#include "ofMain.h"

class mover{
public:
    void setup();
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

#endif /* defined(__NOC_1_7_motion101__mover__) */
