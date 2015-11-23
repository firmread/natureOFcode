//
//  Turtle.h
//  04_Lsystem
//
//  Created by Charlie Whitney on 11/19/13.
//
//

#pragma once

#include "ofMain.h"

class Turtle {
public:
    void setup( float moveLength, float turnAngle );
    void setInstructions( string str );
    void draw();
    
    string instructions;
    float length;
    float theta;
};