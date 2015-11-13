// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Attraction

// A class for a draggable attractive body in our world

class Attractor {
public:
    float mass;         // Mass, tied to size
    ofVec3f location;   // Location
    float g;
    
    Attractor() {
        location.set(0,0,0);
        mass = 20;
        g = 0.4;
    }

    ofVec3f attract(Mover m) {
        ofVec3f force;
        force.set(location);
        force -= m.location;
        float distance = force.length();
        distance = ofClamp(distance,5.0,25.0);
        force.normalize();
        float strength = (g * mass * m.mass) / (distance * distance);
        force *= strength;
        return force;
    }

    void display() {
        ofSetColor(255,0,0);
        ofPushMatrix();
        ofTranslate(location.x,location.y,location.z);
        ofSphere(mass);
        ofPopMatrix();
    }
};

