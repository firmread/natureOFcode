//
//  walker.cpp
//  1_1_Random_Walker
//
//  Created by Firm Read on 6/28/13.
//
//

#include "walker.h"

//init object
void walker::setup(){
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
}

//walk function -> goes to update in testApp
void walker::walk(){
    float r = ofRandom(1);
    
    if      (r < 0.4) x++;
    else if (r < 0.6) x--;
    else if (r < 0.8) y++;
    else              y--;
    
    x = ofClamp(x, 0, ofGetWidth());
    y = ofClamp(y, 0, ofGetHeight());
}

//render function -> goes to draw in testApp
void walker::render(){
    ofCircle(x, y, 1);
}