// The Nature of Code
// Daniel Shiffman
// http://natureofcode.com


class Mover {
public:
    
    ofVec2f location, velocity, acceleration;
    float mass;
    
    Mover() {
        
    }

    Mover(float m, float x, float y) {
        mass = m;
        location.set(x,y);
        velocity.set(0,0);
        acceleration.set(0,0);
    }

    // Newton's 2nd law: F = M * A
    // or A = F / M
    void applyForce(ofVec2f force) {
        // Divide by mass
        force /= mass;
        // Accumulate all forces in acceleration
        acceleration += force;
    }
    
    void update() {
        // Velocity changes according to acceleration
        velocity += acceleration;
        // Location changes by velocity
        location += velocity;
        // We must clear acceleration each frame        
        acceleration.set(0,0);
    }
    
    void display() {
        ofSetLineWidth(2);
        ofSetColor(0,127);
        ofCircle(location.x,location.y,mass*8);
    }
    
    void checkEdges() {
        if (location.y > ofGetHeight()) {
            velocity.y *= -1;
            location.y = ofGetHeight();
        }
    }

};