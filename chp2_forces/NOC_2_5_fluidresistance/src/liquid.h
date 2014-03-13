//
//  liquid.h
//  NOC_2_5_fluidresistance
//
//  Created by Firm Read on 2/22/13.
//
//

#include "ofMain.h"
#include "mover.h"

class liquid{
public:
    
    void setup(float x_, float y_, float w_, float h_, float c_);
    bool contains(mover m);
    ofPoint drag(mover m);
    void display();
    
    // Liquid is a rectangle
    float x,y,w,h;
    // Coefficient of drag
    float c;
};
