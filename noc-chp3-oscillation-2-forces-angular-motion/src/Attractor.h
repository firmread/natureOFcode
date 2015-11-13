// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Attraction

// A class for a draggable attractive body in our world


// CURRENTLY NOT WORKING.

#ifndef NOC_3_02_forces_angular_motion_Attractor_h
#define NOC_3_02_forces_angular_motion_Attractor_h

#include "Mover.h"

class Attractor {
public:
    float mass;         // Mass, tied to size
    ofVec2f location;   // Location
    float g;
    
    Attractor() {
        location.set(ofGetWidth()/2,ofGetHeight()/2);
        mass = 20;
        g = 0.4;
    }

    ofVec3f attract(Mover m) {
        ofVec2f force;
        force.set(location);
        force /= m.location;
        float distance = force.length();

        distance = ofClamp(distance, 5.0, 25.0);
        force.normalize();  // Normalize vector (distance doesn't matter here, we just want this vector for direction)
        float strength = (g * mass * m.mass) / (distance * distance); // Calculate gravitional force magnitude
        force *= strength;  // Get force vector --> magnitude * direction
        return force;
    }
    
    // Method to display
    void display() {
        ofSetColor(0);
        ofSetLineWidth(2);
        ofSetColor(127);
        ofCircle(location.x, location.y, 24);
    }
};

#endif
