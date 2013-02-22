//
//  mover.cpp
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#include "Mover.h"

void Mover::setup(float m, float x, float y){
    mass = m;
    location.set(x,y);
    velocity.set(0,0);
    acceleration.set(0,0);
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

    ofSetColor(0,127);
    ofFill();
    ofCircle(location.x, location.y, mass*8);
    
    ofSetColor(0);
    ofSetLineWidth(2);
    ofNoFill();
    ofCircle(location.x, location.y, mass*8);

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