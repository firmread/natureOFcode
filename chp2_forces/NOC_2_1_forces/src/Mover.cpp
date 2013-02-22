//
//  mover.cpp
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#include "Mover.h"

void Mover::setup(){
    location.set(30,30);
    velocity.set(0,0);
    acceleration.set(0,0);
    mass = 1;
}

void Mover::applyForce(ofPoint force){
    ofPoint f;
    f = force/mass;
    acceleration += f;
}

void Mover::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
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
        location.x = ofGetWidth();
        velocity.x *= -1;
    }
    else if (location.x < 0){
        velocity.x *= -1;
        location.x = 0;
    }
    
    if (location.y > ofGetHeight()) {
        velocity.y *= -1;
        location.y = ofGetHeight();
    }
}