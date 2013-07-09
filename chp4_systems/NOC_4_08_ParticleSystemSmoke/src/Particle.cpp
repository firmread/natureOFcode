//
//  Particle.cpp
//  NOC_4_01_SingleParticle
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#include "Particle.h"

Particle::Particle(ofPoint l, ofImage img_) {
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

void Particle::update() {
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
    lifespan -= 2.0;
}

void Particle::display() {
    ofEnableAlphaBlending(); 
    img.draw(location);
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