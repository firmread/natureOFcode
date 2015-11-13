//
//  Confetti.cpp
//  NOC_4_05_ParticleSystemInheritancePolymorphism
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#include "Confetti.h"

Confetti::Confetti( ofPoint l ) : Particle(l) {}

void Confetti::display() {
    ofEnableAlphaBlending();

    ofFill();
    ofSetColor( 127, lifespan);
    ofRect(location, 12, 12);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor( 0, lifespan);
    ofRect(location, 12, 12);
    
    ofDisableAlphaBlending();
}

