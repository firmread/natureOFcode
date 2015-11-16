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
    void setup(float m, float x, float y);
    void applyForce(ofPoint force);
    void update();
    void display();
    void checkEdges();
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float mass;
    
};
