//
//  mover.cpp
//  NOC_1_7_motion101
//
//  Created by Firm Read on 2/22/13.
//
//

#include "Mover.h"

void Mover::setup(){
    location.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    velocity.set(0,0);
    topspeed = 5;
}

void Mover::update(int x, int y){
    // Compute a vector that points from location to mouse
    ofPoint mouse(x, y);
    
    acceleration = mouse - location;
    // Set magnitude of acceleration
    //acceleration.length(0.2);
    acceleration.normalize();
    acceleration *= 0.2;
    
    // Velocity changes according to acceleration
    velocity += acceleration;
    // Limit the velocity by topspeed
    velocity.limit(topspeed);
    // Location changes by velocity
    location += velocity;
}

void Mover::display(){

    ofSetColor(127,200);
    ofFill();
    ofCircle(location.x, location.y, 24);
    
    ofSetColor(0);
    ofSetLineWidth(2);
    ofNoFill();
    ofCircle(location.x, location.y, 24);

}

