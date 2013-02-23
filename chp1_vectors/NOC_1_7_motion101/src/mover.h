#ifndef __NOC_1_7_motion101__mover__
#define __NOC_1_7_motion101__mover__

#include <iostream>
#include "ofMain.h"

class mover{
public:
    void setup();
    void update();
    void display();
    void checkEdges();
    
    ofPoint location;
    ofPoint velocity;
    
};

#endif