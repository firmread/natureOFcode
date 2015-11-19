#include "particle.h"

particle::particle(ofPoint l, ofImage img_) {
    acceleration.set(0,0.05);
    velocity.set(ofRandom(-1,1), ofRandom(-1,0));
    velocity *= 2;
    
    location = l;
    lifespan = 255;
    img = img_;
}

void particle::update() {
    velocity += acceleration;
    location += velocity;
    lifespan -= 2.0;
}

void particle::display() {
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    ofSetColor(255, lifespan);
    img.draw(location);
    
    ofDisableBlendMode();
}

bool particle::isDead() {
    if (lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}