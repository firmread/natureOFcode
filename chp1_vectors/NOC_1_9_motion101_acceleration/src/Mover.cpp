//
//  mover.cpp
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#include "Mover.h"

void Mover::setup(){
    location.set(ofGetWidth()/2, ofGetHeight()/2);
    velocity.set(0,0);
    topspeed = 6;
}

void Mover::update(){
    acceleration.set(ofRandom(-2,2), ofRandom(-2,2));
    
    velocity += acceleration;
    velocity.limit(topspeed);
    location += velocity;
}

void Mover::display(){

    ofSetColor(127);
    ofFill();
    ofCircle(location.x, location.y, 24);
    
    ofSetColor(0);
    ofSetLineWidth(2);
    ofNoFill();
    ofCircle(location.x, location.y, 24);

}

void Mover::checkEdges(){
    if (location.x > ofGetWidth()) {
        location.x = 0;
    }
    else if (location.x < 0){
        location.x = ofGetWidth();
    }
    
    if (location.y > ofGetHeight()) {
        location.y = 0;
    }
    else if(location.y < 0){
        location.y = ofGetHeight();
    }
    
    
}