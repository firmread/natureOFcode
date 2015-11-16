// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com

// Attraction


class attractor {
public:
    float mass;         // Mass, tied to size
    ofPoint location;   // Location
    float g;
    
    attractor() {
        location.set(0,0,0);
        mass = 20;
        g = 0.4;
    }

    ofPoint attract(mover m) {
        ofPoint force;
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
        ofSetColor(ofColor::salmon);
        ofPushMatrix();
        ofTranslate(location.x,location.y,location.z);
        ofDrawSphere(mass);
        ofPopMatrix();
    }
};

