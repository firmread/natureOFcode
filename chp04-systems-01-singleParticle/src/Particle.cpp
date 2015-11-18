#include "Particle.h"

Particle::Particle( ofPoint l ) {
    acceleration.set(0,0.05);
    velocity.set(ofRandom(-1,1), ofRandom(-1,0));
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
    ofCircle(location, 6);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor( 0, lifespan);
    ofCircle(location, 6);
    
    ofDisableAlphaBlending();
}

bool Particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}