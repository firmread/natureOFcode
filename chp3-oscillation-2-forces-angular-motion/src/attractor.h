

#include "mover.h"

class attractor {
public:
    float mass;
    ofPoint location;
    float g;
    
    attractor() {
        location.set(ofGetWidth()/2,ofGetHeight()/2);
        mass = 20;
        g = 0.4;
    }

    ofPoint attract(mover m) {
        ofPoint force(location);
        force -= m.location;
        
        float distance = force.length();
        distance = ofClamp(distance, 5.0, 25.0);
        force.normalize();
        
        float strength = (g * mass * m.mass) / (distance * distance);
        force *= strength;
        
        return force;
    }
    
    // Method to display
    void display() {
        ofSetColor(127);
        ofDrawCircle(location.x, location.y, 24);
    }
};
