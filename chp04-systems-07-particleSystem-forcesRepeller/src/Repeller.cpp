//
//  Repeller.cpp
//  NOC_4_07_ParticleSystemForcesRepeller
//
//  Created by Matthias Esterl on 7/5/13.
//
//

#include "Repeller.h"

Repeller::Repeller(ofPoint l) {
    location = l;
}

void Repeller::display() {    
    ofFill();
    ofSetColor( 175);
    ofCircle(location, 24);
    
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor( 0);
    ofCircle(location, 24);
}

ofPoint Repeller::repel(Particle p) {
    float G = 100;                              // Gravitational Constant
    
    ofPoint dir = location-p.location;          // Calculate direction of force
    float d = dir.length();                     // Distance between objects
    dir.normalize();                            // Normalize vector (distance doesn't matter here, we just want this vector for direction)
    d = ofClamp(d, 5, 100);                     // Keep distance within a reasonable range
    float force = -1 * G / (d * d);             // Repelling force is inversely proportional to distance
    dir *= force;                               // Get force vector --> magnitude * direction
    return dir;
}