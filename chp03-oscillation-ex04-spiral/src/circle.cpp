#include "circle.h"

circle::circle(){
    
    r = 0;
    theta = 0;
    x = 0;
    y = 0;
    angle = 0;
    
    rSeed = 0;
    
    color.set(0,0,0);
}

void circle::reset(){
    r = 0;
    theta = 0;
    x = 0;
    y = 0;
    angle = 0;
    
    rSeed = ofRandom(0.2);
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void circle::update(float speed){
    x = r * cos(theta);
    y = r * sin(theta);
    
    theta += 0.01 *speed;
    r += (0.05+rSeed) *speed;
    
    angle += (0.1+rSeed) *speed;
}

void circle::draw(){
    ofSetColor(color, 30);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofDrawCircle(x, y, 16, 16);
}