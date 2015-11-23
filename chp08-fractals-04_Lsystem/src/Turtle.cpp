//
//  Turtle.cpp
//  04_Lsystem
//
//  Created by Charlie Whitney on 11/19/13.
//
//

#include "Turtle.h"

void Turtle::setup( float moveLength, float turnAngle ) {
    length = moveLength;
    theta = turnAngle;
}

void Turtle::setInstructions(string str){
    instructions = str;
}

void Turtle::draw() {
    
    for (int i = 0; i < instructions.length(); i++) {
        char c = instructions[i];
        
        if (c == 'F') {
            ofLine(0, 0, length, 0);
            ofTranslate(length, 0);
        }else if( c == 'G') {
            ofTranslate(length, 0);
        }else if (c == '+') {
            ofRotate(theta);
        }
        else if (c == '-') {
            ofRotate(-theta);
        }
        else if (c == '[') {
            ofPushMatrix();
        }
        else if (c == ']') {
            ofPopMatrix();
        }
    }
}