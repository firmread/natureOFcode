// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com


class Mover {
public:
    
    ofVec3f location, velocity, acceleration;
    float mass, g;
    
    Mover() {

    }

    Mover(float m, float x, float y, float z, float g_) {
        mass = m;
        location.set(x,y,z);
        velocity.set(0,0,0);
        acceleration.set(0,0,0);
        g = g_;
    }
    
    void applyForce(ofVec3f force) {
        force /= mass;
        acceleration += force;
    }
    
    void update() {
        velocity += acceleration;
        location += velocity;
        acceleration.set(0,0,0);
    }
    
    void display() {
        ofSetColor(255);
        ofPushMatrix();
        ofTranslate(location.x,location.y,location.z);
        ofSphere(mass*4);
        ofPopMatrix();
    }
    
    ofVec3f attract(Mover m) {
        ofVec3f force;
        force.set(location);
        force -= m.location;
        float distance = force.length();
        distance = ofClamp(distance, 5.0, 25.0);
        force.normalize();
        float strength = (g * mass * m.mass) / (distance * distance);
        force *= strength;
        return force;
    }
};