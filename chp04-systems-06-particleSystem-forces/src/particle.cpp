#include "particle.h"

particle::particle( ofPoint l ) {
    acceleration.set(0,0);
    velocity.set(ofRandom(-1,1), ofRandom(-2,0));
    location = l;
    lifespan = 255.0;
    mass = 1;
}

void particle::update() {
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
    lifespan -= 2.0;
}

void particle::display() {
    ofSetColor( 127, lifespan);
    ofDrawCircle(location, 6);
}

void particle::applyForce(ofPoint force) {
    force /= mass;
    acceleration += force;
}

bool particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}