//
//  Particle.cpp
//  NOC_4_01_SingleParticle
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#include "Particle.h"

Particle::Particle( ofPoint l ) {
    acceleration.set(0,0.05);
    velocity.set(ofRandom(-1,1), ofRandom(-2,0));
    location = l;
    lifespan = 255.0;
}

void Particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 2.0;
}

void Particle::display() {
    ofEnableAlphaBlending();
    
    ofFill();
    ofSetColor( 127, lifespan);
    ofCircle(location.x, location.y, 12);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor( 0, lifespan);
    ofCircle(location.x, location.y, 12);
    
    ofDisableAlphaBlending();
}

bool Particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}