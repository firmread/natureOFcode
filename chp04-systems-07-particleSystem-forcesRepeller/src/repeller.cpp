#include "repeller.h"

repeller::repeller(ofPoint l) {
    location = l;
}

void repeller::display() {
    ofSetColor( 175);
    ofDrawCircle(location, 24);
}

ofPoint repeller::repel(particle p) {
    float G = 100;                              // Gravitational Constant
    
    ofPoint dir = location-p.location;          // Calculate direction of force
    float d = dir.length();                     // Distance between objects
    dir.normalize();                            // Normalize vector (distance doesn't matter here, we just want this vector for direction)
    d = ofClamp(d, 5, 100);                     // Keep distance within a reasonable range
    float force = -1 * G / (d * d);             // Repelling force is inversely proportional to distance
    dir *= force;                               // Get force vector --> magnitude * direction
    return dir;
}