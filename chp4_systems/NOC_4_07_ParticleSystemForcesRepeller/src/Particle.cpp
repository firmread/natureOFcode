//
//  Particle.cpp
//  NOC_4_01_SingleParticle
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#include "Particle.h"

Particle::Particle( ofPoint l ) {
    acceleration.set(0,0);
    velocity.set(ofRandom(-1,1), ofRandom(-2,0));
    location = l;
    lifespan = 255.0;
    mass = 1;
}

void Particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 2.0;
    acceleration *= 0;
}

void Particle::display() {
    ofEnableAlphaBlending();
    
    ofFill();
    ofSetColor( 127, lifespan);
    ofCircle(location, 6);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor( 0, lifespan);
    ofCircle(location, 6);
    
    ofDisableAlphaBlending();
}

void Particle::applyForce(ofPoint force) {
    force /= mass;
    acceleration += force;
}

bool Particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}