#include "particle.h"

particle::particle( ofPoint l ) {
    acceleration.set(0,0.05);
    velocity.set(ofRandom(-1,1), ofRandom(-1,0));
    location = l;
    lifespan = 255.0;
}

void particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 2.0;
}

void particle::display() {
    ofSetColor( 127, lifespan);
    ofDrawCircle(location, 6);
}

bool particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}