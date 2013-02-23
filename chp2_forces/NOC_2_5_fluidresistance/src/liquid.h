//
//  liquid.h
//  NOC_2_5_fluidresistance
//
//  Created by Firm Read on 2/22/13.
//
//

#ifndef __NOC_2_5_fluidresistance__liquid__
#define __NOC_2_5_fluidresistance__liquid__

#include <iostream>
#include "ofMain.h"
#include "Mover.h"

class liquid{
public:
    
    void setup(float x_, float y_, float w_, float h_, float c_);
    bool contains(Mover m);
    ofPoint drag(Mover m);
    void display();
    
    // Liquid is a rectangle
    float x,y,w,h;
    // Coefficient of drag
    float c;
};

#endif /* defined(__NOC_2_5_fluidresistance__liquid__) */
