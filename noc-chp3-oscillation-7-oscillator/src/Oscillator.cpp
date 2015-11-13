//
//  Oscillator.cpp
//  NOC_3_7_Oscillator
//
//  Created by Maria Paula Saba dos Reis on 2/13/13.
//
//

#include "Oscillator.h"


void Oscillator::setup(int y)  {
    velocity.set(ofRandom(-0.05, 0.05), ofRandom(-0.05, 0.05));
    amplitude.set(ofRandom(ofGetWidth()/2),y);
    
}

void Oscillator::oscillate()  {
    angle += velocity;
}

void Oscillator::display()  {
    
    float x = sin(angle.x)*amplitude.x;
    float y = sin(angle.y)*amplitude.y;
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    
    ofSetColor(0);
    ofNoFill();
    ofLine(0,0,x,y);
    
    ofSetColor(175);
    ofFill();
    ofCircle(x,y,16);
    
    ofPopMatrix();
}