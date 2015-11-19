#include "particle.h"

particle::particle(ofPoint l, ofImage img_) {
    acceleration.set(0,0);
    
    /*
     float vx = randomGaussian()*0.3;
     float vy = randomGaussian()*0.3 - 1.0;
     velocity.set(vx,vy);
    */
    velocity.set(ofRandom(-1,1), ofRandom(-2,0));
    location = l;
    lifespan = 100.0;
    mass = 1;
    img = img_;
}

void particle::update() {
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
    lifespan -= 2.0;
}

void particle::display() {
    img.draw(location);
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